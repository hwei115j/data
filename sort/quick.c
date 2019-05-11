#include <stdio.h>
#include <stdint.h>
#include "test.h"

void quick(uint32_t *n, int len)
{
    if(len < 2)
        return ;
    uint32_t pivot = n[0];
    int left = 0, right = len - 1;
    while(left < right)
    {
        while(n[left] < pivot && left < right)
            left++;
        while(n[right] >= pivot && left < right)
            right--;
        SWAP(n[left], n[right]);
    }
    quick(&n[0], len/2);
    quick(&n[len/2], (len + 1)/2);
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

