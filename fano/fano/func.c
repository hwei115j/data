#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fano.h"

void func(int *arr, int *tree, int max, int n)
{
    int i, sum = 0;
    double reg = max/2.0;

    if(arr[0] == max)
    {
        tree[n] = max;
        return ;
    }
    for(i = 0; arr[i] && ((sum + arr[i]) < reg); i++)
        sum += arr[i];
    if(ABSO(reg - (sum + arr[i])) < ABSO(reg - sum))
        sum += arr[i++];
    func(arr, tree, sum, n*2);
    func(&arr[i], tree, max - sum, n*2+1);
}

int squa(int n)
{
    return (n > 1)?2*squa(n/2):1;
}

void restr(char *str)
{
    int i, j;
    char c;

    for(i = 0, j = strlen(str)-1; i<j; ++i, --j)
        c = str[i], str[i]=str[j], str[j]=c;
}

void tocode(int node, int level, char *str)
{
    int i;

    for(i = 0; (level >> i) > 1; i++)
        str[i] = '0' + ((node >> i)&1);
    restr(str);
}

void coding(int *tree, int *ascii, char (*code)[10])
{
    int i, j;

    for(i = 0; i < MAX; i++)
        if(ascii[i])
        {
            int reg;

            for(j = 0; tree[j] != ascii[i]; j++);
            reg = j - squa(j);
            tocode(reg, j - reg, code[i]);
            tree[j] = 0;
        }
}

void decode(char *in, char (*code)[10], char *out)
{
    int i;

    if(in[0])
        return ;
    for(i = 0; !code[i][0] || (strstr(in, code[i]) - in); i++);
    out[0] = i; out[1] = '\0';
    decode(&in[strlen(code[i])], code, &out[1]);
}

int fdecode(char *in, char (*code)[10], uint8_t out)
{
    int i;
    
    if(in[0] == 0)
        return 0;
    for(i = 0; i < MAX && (!code[i][0] || (strstr(in, code[i]) - in)); i++);
    if(i == MAX)
    {
        out = 0;
        return 0;
    }
    out = i;

    return strlen(code[i]);
}

void file_decode(FILE *in, char (*code)[10], FILE *out)
{ 
    uint8_t in_buffer[MAX] = {}, out_buffer;
    uint8_t file_buffer;
    int pot = 0, reg = 0;

    while(!feof(in))
    {
        fread(&file_buffer, sizeof(uint8_t), 1, in);
        push_bu(file_buffer, in_buffer, &pot, MAX);
        while((reg = fdecode(in_buffer, code, out_buffer)))
        {
            pot -= reg;
            fwrite(&out_buffer, sizeof(uint8_t), 1, out);
        }
    }
}

void push_bu(uint8_t in, uint8_t *out, int *pot, int max)
{
    int i;

    if(*pot + 1 == max)
        return ;
    for(i = 7; i >= 0; i--)
        out[(*pot)++] = ((in >> i)&1) + '0';
}
void read_dic(char (*code)[10], FILE *dic)
{
    int n;
    
    while(fscanf(dic, "%d", &n) != EOF)
        fscanf(dic, "%s", code[n]);
}
int compar(const void *a, const void *b)
{
    return ((*(int *)b) - (*(int *)a));
}

int file_in(int *ascii, int *sorii, FILE *in)
{
    int i, sum = 0;
    char c;
    
    while((c = fgetc(in)) != EOF)
    {
        ascii[c]++;
        sorii[c]++;
    }
    qsort(sorii, MAX, sizeof(int), compar); //排序
    for(i = 0; i < MAX; i++)        //計算總和
        sum += sorii[i];
    
    return sum;
}

void file_out(char (*code)[10], FILE *in, FILE *out, FILE *dic)        //編碼並寫入文件
{
    int i, cont = 0;
    char c;
    uint8_t buffer = 0;
    
    rewind(in);
    while((c = fgetc(in)) != EOF)
        for(i = 0; code[c][i]; i++)
        {
            cont++;
            buffer |= code[c][i] - '0'; 
            if(!(cont%8))
            {
                fwrite(&buffer, sizeof(char), 1, out);
                buffer = 0;
            }
            buffer <<= 1;
        }
    if((cont%8))
    {
        buffer <<= (7-cont%8);
        fwrite(&buffer, sizeof(char), 1, out);
    }
    for(i = 0; i < MAX; i++)
        if(code[i][0])
            fprintf(dic ,"%d %s\n", i, code[i]); 
}
