#include <stdio.h>
#include "test.h"

void merge(int *n, len)
{
    if(!len)
        return ;
    merge(&n[len/2], len/2);
    merge(&n[len/2 + 1], len/2 + 1);

}
int main()
{
    uint32_t n[MAX];
    int len;

    IN(n, len);
    merge(n, len);
    
}

