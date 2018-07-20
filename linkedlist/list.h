#include<stdio.h>

typedef struct node
{
	int data;
	struct node *next;
}node_t;

typedef struct list
{
	node_t *head;
}list_t;

extern void init(list_t *);
extern int newNode(list_t *, int);
//在最後一個結點後新增結點
extern int readNode(list_t *, int);
//讀取結點，如果沒有結點傳回0
extern int creatList(list_t *, int, int *); 
//以陣列值來建立串列
extern int isListEmpty(list_t *);
//檢查串列是否為空 是 = 1; 否 = 0;
extern int printList(list_t *);
//顯示串列的每一個節點
extern node_t *searchNode(list_t *, int);
//搜尋串列內的資料，如果有(第一個)則傳回結點指標，否傳回NULL
extern int deleteNode(list_t *, int);
//刪除結點
extern int insertNode(list_t *, int, int);
//在第2個參數之前插入第3個參數值的結點
extern int deleteList(list_t *);
