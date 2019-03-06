#include <stdio.h>
#include <stdint.h>
#include "test.h"

void quick(uint32_t *n, int len)
{
    if(!len)
        return ;
    uint32_t pivot = n[len/2];
    int l = 0, r = len;

    quick(&n[len/2], len/2);
    quick(&n[len/2 + 1], len/2 + 1);
}
int main()
{
    uint32_t n[MAX];
    int len;

    IN(n, len);
    quick(n, len)
    return 0;
}

