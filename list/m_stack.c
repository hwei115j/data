#include <stdio.h>
#include "list.h"
#include "stack.h"

int main()
{
    struct stack *sk = stack_new();
    
    stack_push(sk, 100);
    stack_push(sk, 101);
    stack_push(sk, 102);
    stack_push(sk, 103);
    stack_push(sk, 104);
    
    stack_print(sk);
    printf("\n");
    printf("%d\n", stack_pop(sk));
    printf("%d\n", stack_size(sk));
    printf("\n");
    stack_print(sk);
    printf("\n"); 
    stack_free(sk);
}
