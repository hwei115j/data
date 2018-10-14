#include <stdio.h>
#include "list.h"

int main()
{
    struct list *head = list_new();

    list_push_last(head, 10);
    list_push_first(head, 20);
    list_push_last(head, 30);
    list_push_last(head, 40);
    list_print(head);
    putchar('\n');
    printf("%d\n", list_get_last(head));
    printf("%d\n", list_get_first(head));
    printf("%d\n", list_size(head));
    putchar('\n');
    list_del_last(head);
    list_del_first(head);
    list_print(head);
    putchar('\n');
    list_del(head, 1);
    list_print(head);
    list_free(head);
    
    return 0;
}
