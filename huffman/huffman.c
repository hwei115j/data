#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

static int comp(const void *a, const void *b)
{
    return ((*(uint32_t *)a) - (*(uint32_t *)b));
}

void test1(node *head)
{
    printf("node = %011p next = %011p data = %d\n", head, head->next, head->data);
    if(head->next != NULL)
        test1(head->next);
}
node *set_root(uint32_t *stati)
{
    int cont;

    qsort(stati, UNIT, sizeof(int), comp);
    for(cont = 0; stati[cont] == 0 && cont < UNIT; cont++);
#if 0
    printf("%d\n", cont);
    for(int i = cont; i < UNIT; i++)
        printf("%u\n", stati[i]);
#endif
    node *top = init_list(&stati[cont], UNIT - cont);
    test1(top);
    for(int i = 0; i < UNIT - cont - 1; i++)
    {
//        printf("\n");
        top = sort_node(top);
//        test1(top);
    }

    return top;
}

node *sort_node(node *top)
{
    if(top->next == NULL)
        return top;
    top = add_node(top, top->next);
    top = insert_list(top);

    return top;
}

node *init_list(uint32_t *arr, size_t max)
{
    node *head = new_node();
    head->data = arr[0];
    node *reg = head;
    for(int i = 1; i < max; i++)
    {
        reg->next = new_node();
        reg = reg->next;
        reg->data = arr[i];
    }

    return head;
}

node *new_node()
{
    node *reg = malloc(sizeof(node));

    reg->parent = reg->child_l = reg->child_r = reg->next = NULL;

    return reg;
}

node *add_node(node *cl, node *cr)
{
    node *reg = new_node();
    
    reg->next = cr->next;
    reg->child_l = cl;
    reg->child_r = cr;
    reg->data = cl->data + cr->data;
    cl->next = cr->next = NULL;

    return reg;
}

node *insert_list(node *top)
{
    if(top->next == NULL || top->data <= top->next->data)
        return top;
    node *reg = top;
    node *head = top->next;

    while(reg->next != NULL && top->data > reg->next->data)
        reg = reg->next;
    top->next = reg->next;
    reg->next = top;

    return head;
}

void file_in(uint32_t *stati)
{
#if 0
    char str[200];

    scanf("%s", str);
    strlen(str);
    for(int i = 0; str[i]; i++)
    {
        printf("#%d = %c\n",i, str[i]);
        stati[str[i]]++;
    }
#endif
    //fread(str, sizeof(char), 200, stdin);
    int ch;

    //while((ch = fgetc(stdin)) != EOF)
    //    stati[ch]++;
    while((ch = getchar()) != EOF)
        stati[ch]++;
}

#if 1
static void coding_re(node *top, uint32_t *code, char (*dic)[10], char *reg, char *st)
{
    if(top->child_r == NULL && top->child_l == NULL)
    {
        int i;

        for(i = 0; i < UNIT && top->data != code[i]; i++);
        code[i] = 0;
        memcpy(dic[i], st, sizeof(char) * 10);
    }
    if(top->child_l != NULL)
    {
        reg[0] = '0';
        coding_re(top->child_l, code, dic, &reg[1], st);
    }
    if(top->child_r != NULL)
    {
        reg[0] = '1';
        coding_re(top->child_r, code, dic, &reg[1], st);
    }
    reg[0] = 0;
}
void coding(node *top, uint32_t *code, char (*dic)[10])
{
    char reg[UNIT] = {};

    coding_re(top, code, dic, reg, reg);
}
#endif
