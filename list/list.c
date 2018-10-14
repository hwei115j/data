#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *list_new()
{
    struct list *p = malloc(sizeof(struct list));

    p->data = 0;
    p->next = NULL;

    return p;
}

int list_push_last(struct list *head, int n)
{
    struct list *p = head;
    
    for(; p->next != NULL; p = p->next);
    if((p->next = list_new()) == NULL)
        return -1;
    p->next->data = n;
    head->data++;

    return 0;
}
int list_push_first(struct list *head, int n)
{
    struct list *p;

    if((p = list_new()) == NULL)
        return -1;
    p->next = head->next;
    head->next = p;
    p->data = n;
    head->data++;
    
    return 0;
}
int list_print(struct list *head)
{
    struct list *p = head;
    int i;

    for(i = 0; p->next != NULL; p = p->next, i++)
        printf("list[%d]: data = %d arr = %p next = %p\n", i, p->data, p, p->next);
    printf("list[%d]: data = %d arr = %p next = %p\n", i, p->data, p, p->next);

    return i;
}
int list_del(struct list *head, int n)
{
    struct list *p = head;
    struct list *reg;
    int i;

    for(i = 0; i < n-1 && p->next != NULL; p = p->next, i++);
    if(i != n-1) return -1;
    reg = p->next->next;
    free(p->next);
    p->next = reg;
    head->data--;

    return 0;
}
int list_free(struct list *head)
{
    struct list *p;
    
    while(head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }

    return 0;
}

int list_size(struct list *head)
{
    return head->data;
}

int list_get_first(struct list *head)
{
    return head->next->data;
}

int list_get_last(struct list *head)
{
    struct list *p = head;
    
    for(; p->next != NULL; p = p->next);

    return p->data;
}
int list_del_first(struct list *head)
{
    return list_del(head, 1);
}
int list_del_last(struct list *head)
{
    return list_del(head, head->data);
}
