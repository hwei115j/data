#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "huffman.h"

void test(node *top)
{
    printf("node = %p p = %011p l = %011p r = %011p next = %p data = %d \n"\
            , top, top->parent, top->child_l, top->child_r, top->next, top->data);
    if(top->child_l != NULL)
        test(top->child_l);
    if(top->child_r != NULL)
        test(top->child_r);
}
int main()
{
    uint32_t code[UNIT] = {};
    uint32_t stati[UNIT] = {};
    char dic[UNIT][10] = {};

    node *root;
    file_in(stati);
    memcpy(code, stati, sizeof(stati));
    root = set_root(stati);
    //test(root);
    coding(root, code, dic);
#if 0
    for(int i = 0; i < UNIT; i++)
        if(dic[i][0]) printf("%1c %3d = %s\n", i, i,  dic[i]);
#endif
    file_out(dic);

    return 0;
}
