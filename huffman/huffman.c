#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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
    printf("%d\n", cont);
    for(int i = cont; i < UNIT; i++)
        printf("%u\n", stati[i]);
    node *top = init_list(&stati[cont], UNIT - cont);
    //test1(top);
    for(int i = 0; i < UNIT - cont - 1; i++)
    {
      //  printf("\n");
        top = sort_node(top);
        //test1(top);
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
    if(top->next == NULL)
        return top;
    node *reg = top;
    node *head = top->next;

    while(reg->next != NULL && top->data > reg->next->data)
        reg = reg->next;
    top->next = reg->next;
    reg->next = top;

    if(top->next == head)
        return top;
    return head;
}

void file_in(uint32_t *stati)
{
    char str[200];

    scanf("%s", str);
    for(int i = 0; str[i]; i++)
        stati[str[i]]++;
}
void coding(node *top, uint32_t *code, char *reg)
{
    if(top->child_r == top->child_l)
    {
        for(i = 0; i < UNIT && top->data != code[i]; i++);
        code[i] = stonum(reg);
    }
    if(top->child_l != NULL)
        coding(top->child_l);
    if(top->child_r != NULL)
        coding(top->child_r);
}
