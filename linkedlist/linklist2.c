#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
typedef struct link Link;
typedef int (* func)(Link *);

struct node
{
	int data;
	Node *next;
};

struct link 
{
	int size;
	int aims, reg;
	Node *head;
	func insert, delete;
	func show;
};

int insert_f(Link *obj)
{
	Node *point = obj->head;
	Node *reg = NULL;
	int i;

	for(i = 0; i <= obj->aims && point->next != NULL; i++)
		point = point->next;
	reg = point->next;
	if(NULL == (point->next = malloc(sizeof(Link))))
		return -1;
	point = point->next;	//進入新節點
	point->data = obj->reg;
	point->next = reg;
	obj->size++;

	return 0;
}

int delete_f(Link *obj)
{
	Node *point = obj->head;
	Node *reg = NULL;
	int i;
		
	for(i = 0; i <= obj->aims && point->next->next != NULL; i++)
		point = point->next;
	reg = point->next->next;
	free(point->next);
	point->next = reg;
	obj->size--;

	return 0;
}

int show_f(Link *obj)
{
	Node *point = obj->head;

	printf("size = %d\n", obj->size);
	while(point != NULL)
	{
		printf("data = %d next = %x &note = %x\n",\
			 point->data, point->next, point);
		point = point->next;
	}
	
	return 0;
}

int init(Link **obj)
{
	if(NULL == ((*obj = malloc(sizeof(Link)))))
		return -1;
	if(NULL == ((*obj)->head = malloc(sizeof(Link))))
		return -1;
	(*obj)->head->next = NULL;
	(*obj)->size = 0;
	(*obj)->insert = insert_f;
	(*obj)->delete = delete_f;
	(*obj)->show = show_f;
}

 
int main()
{
	Link *adt = NULL;
	int n;

	init(&adt);
	while(1)
	{
		printf("\ninsert 1, delete 2, show 3 , exit 0\n");
		scanf("%d", &n);
		switch (n)
		{
			case 1:
				printf("請輸入一個整數和要插入的位置:\n");
				scanf("%d%d", &adt->reg, &adt->aims);
				adt->insert(adt);
				break;
			case 2:
				printf("要刪除第幾個節點:\n");
				scanf("%d", &adt->aims);
				adt->delete(adt);
				break;
			case 3:
				adt->show(adt);
				break;
			case 0:
				return 0;
		}
	}
	
	return 0;
}
