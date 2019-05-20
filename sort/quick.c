#include <stdio.h>
#include <stdint.h>
#include "test.h"

void quick(uint32_t *n, int len)
{
    if(len <= 1) return ;
    int pivot = 0, i, j;

    for(i = pivot+1, j = len-1; i < j;) {
        while(i < j && n[i] <= n[pivot]) i++;
        while(i < j && n[j] > n[pivot]) j--;
        SWAP(n[i], n[j]);
    }
    if(n[i] < n[pivot])
        SWAP(n[i], n[pivot]);
    quick(&n[0], i);
    quick(&n[i], len-i);
}
int main()
{
    uint32_t n[MAX];
    int len;

    IN(n, len);
    quick(n, len);
    OUT(n, len);
    return 0;
}

