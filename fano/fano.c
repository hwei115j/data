#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABSO(x) ((x >= 0)?(x):(-(x)))
#define MAX 300
#define T_MAX 1024

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

    if(in[0] == 0)
        return ;
    for(i = 0; !code[i][0] || (strstr(in, code[i]) - in); i++);
    out[0] = i; out[1] = '\0';
    decode(&in[strlen(code[i])], code, &out[1]);
}
int compar(const void *a, const void *b)
{
    return ((*(int *)b) - (*(int *)a));
}

int main()
{
    char in[MAX], out[MAX];
    char str[10] = {};
   
    while(scanf("%[^\n]%*c", in) != EOF)
    {
        int i, j, sum = 0;
        int ascii[MAX] = {}, sorii[MAX] = {};
        int tree[T_MAX] = {};
        char code[MAX][10] = {};

        for(i = 0; in[i]; i++)
        {
            ascii[in[i]]++;
            sorii[in[i]]++;
        }
        qsort(sorii, MAX, sizeof(int), compar); //排序
        for(i = 0; i < MAX; i++)        //計算總和
            sum += sorii[i];
        func(sorii, tree, sum, 1);  //建立二元樹
        coding(tree, ascii, code);        //編碼
        for(i = 0; i < MAX; i++)
            if(code[i][0])
                printf("%c = %s\n", i, code[i]);

        scanf("%[^\n]%*c", in);
        for(i = 0; in[i]; i++)
            printf("%s", code[in[i]]);
        printf("\n");

        scanf("%s%*c", in);
        decode(in, code, out);
        printf("%s\n", out);
    }

    return 0;
}
