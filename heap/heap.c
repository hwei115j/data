#include <stdio.h>
#define HEAP_MAX 1000
#define SWAP(a, b) do{int _n = a; a = b; b = _n;}while(0)
static int heap[HEAP_MAX];
static int sp = 0;
static void up(int n)
{
    if(!n) return ;
    if(heap[(n-1)/2] < heap[n]) {
        SWAP(heap[(n-1)/2], heap[n]);
        up((n-1)/2);
    }
}
static void down(int n)
{
    int a;

    if(n*2 >= sp) return ;
    if(n*2+1 >= sp || heap[n*2] > heap[n*2+1])
        a = n*2;
    else
        a = n*2+1;
    if(heap[n] < heap[a]) {
        SWAP(heap[n], heap[a]);
        down(a);
    }
}
void push(int in)
{
    heap[sp++] = in;
    up(sp-1);
}
int pop()
{
    int out = heap[0];
    heap[0] = heap[--sp];
    down(0);
    return out;
}

static void list()
{
    for(int i = 0; i < sp; i++)
        printf("%d\n", heap[i]);
}

int main()
{
    while(scanf("%d", &n) != EOF)
        push(n);
    list();
}
