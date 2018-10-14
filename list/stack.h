#ifndef __STACK_H_
#define __STACK_H_
#include "list.h"

struct stack
{
    struct list *head;
    int sp;
};

//新增堆疊
struct stack *stack_new();
//push進堆疊
int stack_push(struct stack *sk, int data);
//pop出堆疊
int stack_pop(struct stack *sk);
//印出堆疊內所有元素
int stack_print(struct stack *sk);
//堆疊大小
int stack_size(struct stack *sk);
//free堆疊
void stack_free(struct stack *sk);
#endif
