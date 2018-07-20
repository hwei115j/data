#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(list_t *plist)
{
	plist->head = NULL;
}

int newNode(list_t *plist, int data)
{
	node_t *reg = plist->head;

	if(reg == NULL)
	{
		if((plist->head = malloc(sizeof(node_t))) == NULL)
			return 1;
		reg = plist->head;
	}
	else
	{

		while(reg->next != NULL)
			reg = reg->next;
		if((reg->next = malloc(sizeof(node_t))) == NULL)
			return 1;
		reg = reg->next;
	}
	reg->data = data;
	reg->next = NULL;

	return 0;
}

int readNode(list_t *plist, int n)
{
	node_t *reg = plist->head;
	int i;

	if(reg == NULL)
		return 0;
	for(i = 0; i < n && reg->next != NULL; i++)
		reg = reg->next;

	return (n == i)?reg->data:0;
}

/*int creatList(list_t *plist, int len, int *array)
{
	if(deleteList(plist) == 1)
		return 1;
	if((plist->head = malloc(sizeof(node_t))) == NULL)
		return 1;
	node_t *reg = plist->head;
	int i;
	
	reg->data = array[0];
	reg->next = NULL;
	for(i = 1; i < len; i++)
	{
		if((reg->next = malloc(sizeof(node_t))) == NULL)
			return 1;
		reg = reg->next;
		reg->data = array[i];
		reg->next = NULL;
	}

	return 0;
}*/
int isListEmpty(list_t *plist)
{
	return !(plist == NULL);
}
int printList(list_t *plist)
{
	node_t *reg = plist->head;
	if(plist == NULL)
		return 1;
	while(reg->next != NULL)
	{
		printf("%d ",reg->data);
		reg = reg->next;
	}
	printf("%d\n", reg->data);

	return 0;
}
