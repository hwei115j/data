#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "huffman.h"

#define UNIT 256

struct node *parent, *child_l, *child_r;
void decode(FILE *in, node *root)
{
    if(root->child_l == root->child_r)
        printf("%c", root->data);
    int ch = fgetc(in);

    if(ch == "0")
        decode(in, root->child_l);
    if(ch == "1")
        decode(in, root->child_r);
}
node *tree(char (*dic)[10])
{
    node *root = new_node();
}
int main()
{
    FILE *in = fopen("./output", "r");
    FILE *dic_in = fopen("./dic", "r");
    char dic[UNIT][10] = {};
    char str[10];
    int n;
    node *root;

    while(fscanf(dic_in, "%d%s", &n, str))
        memcpy(dic[n], str, sizeof(str));
    root = tree(dic);
    decode(in, root);

    return 0;
}

