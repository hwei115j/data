#include<stdio.h>
#include<stdlib.h>

#define MAX 1001
#define SWAP(x, y) do{ int SW; SW = (x); (x) = (y); (y) = SW;}while(0)

typedef struct heap Heap;
typedef int (* func)(Heap *);

struct heap
{
	int tree[MAX];
	int reg;
	int sp;
	func pop, push;
	func list;
};

int pop_f(Heap *obj)
{
	int n, min = 1;

	if(obj->sp == 2)
		return obj->tree[--obj->sp];
	if(obj->sp < 2)
		return -1;

	n = obj->tree[min];
	obj->tree[min] = obj->tree[--obj->sp];
	
	while(min*2 < obj->sp)
	{
		if(min*2+1 < obj->sp)
		{
			if(obj->tree[min*2] > obj->tree[min*2+1])
			{
				if(obj->tree[min] < obj->tree[min*2])
				{
					SWAP(obj->tree[min], obj->tree[min*2]);
					min*=2;
				}
				else
					return n;
			}
			else if(obj->tree[min*2] < obj->tree[min*2+1])
			{
				if(obj->tree[min] < obj->tree[min*2+1])
				{
					SWAP(obj->tree[min], obj->tree[min*2+1]);
					min = min*2+1;
				}
				else
					return n;
			}
			else
				return n;
		}
		else
		{
			if(obj->tree[min] < obj->tree[min*2])
				SWAP(obj->tree[min], obj->tree[min*2]);
			else
				return n;
			min = min*2;
		}		
	}	

	return n;
}

int push_f(Heap *obj)
{
	int n;

	obj->tree[obj->sp++] = obj->reg;
	n = obj->sp-1;
	if(obj->sp == 2)
		return 0;
	while(n/2 && obj->tree[n/2] < obj->tree[n])
	{
		SWAP(obj->tree[n/2], obj->tree[n]);
		n/=2;
	}

	return 0;	
}

int list_f(Heap *obj)
{
	int i;
	
	for(i = 1; i < obj->sp; i++)
		printf("%d ", obj->tree[i]);
	printf("\n");

	return 0;
}
int init(Heap **obj)
{
	if(NULL == (*obj = malloc(sizeof(Heap))))
		return -1;
	(*obj)->tree;
	(*obj)->reg = 0;
	(*obj)->sp = 1;
	(*obj)->pop = pop_f;
	(*obj)->push = push_f;
	(*obj)->list = list_f;
	return 0;
}

int main()
{
	Heap *adt;
	int n;

	init(&adt);
	while(1)
	{
		puts("push 1:");
		puts("pop  2:");
		puts("list 3:");
		puts("exit 0:");
		scanf("%d", &n); 
		switch(n)
		{
			case 1:
				puts("input integer:");
				scanf("%d", &adt->reg);
				adt->push(adt);
				break;	
			case 2:
				printf("%d\n", adt->pop(adt));
				break;
			case 3:
				adt->list(adt);
				break;
			case 0:
				return 0;
		}
	}
	return 0;
}
