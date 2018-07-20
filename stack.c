#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
    union
    {
        char c_num;
        int i_num;
        long long int lli_num;
        float f_num;
        double d_num;
    }d;
    char n;
}type;

typedef struct Stack
{
    int top;
    type *data;
    type *(*pop)(struct Stack *);
    void (*push)(struct Stack *, type);
}stack;

type *pop_impl(stack *obj)
{
    if(obj->top == 0)
        return NULL;
    return &obj->data[obj->top--];
}

void push_impl(stack *obj, type ven)
{
    obj->data[obj->top++] = ven;
}

stack *init()
{
    stack *obj = malloc(sizeof(stack));
    obj->top = 0;
    obj->data = malloc(sizeof(type) * MAX);
    obj->pop = pop_impl;
    obj->push = push_impl;

    return obj;
}

int main()
{
    stack *obj = init();
    int n;

    while(scanf("%d", &n))
    {
        if(n == 0)
            scanf(
    }
}
