#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "test.h"

int main()
{
     uint32_t a;

     srand(time(NULL));

     for(int i = 0; i < MAX; i++) {
         a = (rand()%LIM)+1;
         printf("%d ", a);
     }

     return 0;
}
