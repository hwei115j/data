#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct stack *stack_new()
{
    struct stack *s = malloc(sizeof(struct stack));

    s->head = list_new();
    s->sp = 0;

    return s;
}

int stack_push(struct stack *sk, int data)
{
    if(list_push_last(sk->head, data) == -1)
        return -1;
    sk->sp++;

    return 0;
}

int stack_pop(struct stack *sk)
{
    int data = list_get_last(sk->head);

    list_del_last(sk->head);
    sk->sp--;

    return data;
}

int stack_size(struct stack *sk)
{
    return sk->sp;
}

int stack_print(struct stack *sk)
{
    printf("%d\n", stack_size(sk)); 

    return list_print(sk->head);
}

void stack_free(struct stack *sk)
{
    list_free(sk->head);
    free(sk);
}
