#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fano.h"

int main(int argc, char *argv[])
{
    FILE *in, *out, *dic;
    int ascii[MAX] = {}, sorii[MAX] = {}, tree[T_MAX] = {};
    char code[MAX][10] = {};
    int sum;
    
    if(argc < 3)
    {
        printf("error arrc\n");
        return 0;
    }
    if((in = fopen(argv[1],"r")) == NULL)
    {
        printf("error file\n");
        return 0;
    }
    if((dic = fopen(argv[2], "r")) == NULL)
    {
        printf("error file\n");
        return 0;
    }
    if((out = fopen("out", "w")) == NULL)
    {
        printf("error file\n");
        return 0;
    }

    read_dic(code, dic);
    file_decode(in, code, out);
    for(int i = 0; i < MAX; i++)
        if(code[i][0])
            printf("%d %s\n", i, code[i]);
    return 0;
}
