#include <stdio.h>
#include "test.h"
//#define SWAP(a, b) do{int _ss = (a); (a) = (b); (b) = (_ss);}while(0)

void heapify(int *tree, int n, int i)
{
    int c1 = i*2+1;
    int c2 = i*2+2;
    int max = i;

    if(c1 < n && tree[c1] > tree[max])
        max = c1;
    if(c2 < n && tree[c2] > tree[max])
        max = c2;
    if(max != i) {
        SWAP(tree[i], tree[max]);
        heapify(tree, n, max);
    }
}

void build_heap(int *tree, int n)
{
    for(int i = n;i--;)
        heapify(tree, n, i);
}

void heap_sort(int *tree, int n)
{
    build_heap(tree, n);
    for(int i = 1; i <= n; i++) {
        SWAP(tree[0], tree[n-i]);
        heapify(tree, n-i, 0);
    }
}
void rearr(int *arr, int n)
{
    for(int i = 0; i != n;)
        SWAP(arr[i++], arr[n--]);
}
int main()
{
    int tree[] = {1, 5, 2, 10, 4, 3};
    int arr[MAX], n;
    
    IN(arr, n);
//    heapify(tree, 6, 0);
//    build_heap(tree, 6);
    heap_sort(arr, n);
//    rearr(arr, n);
    OUT(arr, n);
}
