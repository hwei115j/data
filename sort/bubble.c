#include <stdio.h>
#include <stdint.h>
#include "test.h"

int main()
{
    uint32_t n[MAX];
    int len;

   IN(n, len);
   for(int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - 1 - i; j++)
            if(n[j] > n[j + 1])
                SWAP(n[j], n[j + 1]);
    for(int i = 0; i < len; i++)
        printf("%d\n", n[i]);

    return 0;
}
