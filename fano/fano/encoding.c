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
    if((out = fopen(argv[2], "wb")) == NULL)
    {
        printf("error file\n");
        return 0;
    }
    if((dic = fopen("dic", "w")) == NULL)
    {
        printf("error file\n");
        return 0;
    }
    sum = file_in(ascii, sorii, in);  //讀取文件並建立排序&總和
    func(sorii, tree, sum, 1);      //建立二元樹
    coding(tree, ascii, code);      //建立字典檔
    file_out(code, in, out, dic);        //編碼並寫入文件

    return 0;
}
