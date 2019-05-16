#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

int cmp(const void * a, const void * b)
{
   return ( *(uint32_t *)a - *(uint32_t *)b );
}

int main()
{
    uint32_t n[MAX] = {};
    int i;

    IN(n, i);
//    for(i = 0; scanf("%d", &n[i]) != EOF; i++);
    qsort(n, i, sizeof(uint32_t), cmp);
    OUT(n, i);
/*    for(i = 0; i < MAX; i++)
        printf("%d\n", n[i]);
*/
    return 0;
}
