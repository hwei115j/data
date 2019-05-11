#include <stdio.h>
#include <stdint.h>
#include "test.h"

void bubble(uint32_t *n, int len)
{
   for(int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - 1 - i; j++)
            if(n[j] > n[j + 1])
                SWAP(n[j], n[j + 1]);
}
int main()
{
    uint32_t n[MAX];
    int len;

    IN(n, len);
    bubble(n, len);
    OUT(n, len);
    return 0;
}
