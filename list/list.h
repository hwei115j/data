#ifndef __LIST_H_
#define __LIST_H_

struct list
{
    int data;
    struct list *next;
};

//初始化一個節點
struct list *list_new();
//往開頭新增一個節點
int list_push_first(struct list *head, int n);
//往尾端新增一個節點
int list_push_last(struct list *head, int n);
//列印整個list
int list_print(struct list *head);
//清除第n個節點
int list_del(struct list *head, int n);
//刪除整個list
int list_free(struct list *head);
//取得list的節點數目
int list_size(struct list *head);
//取得第一個節點的資料
int list_get_first(struct list *head);
//取得最後一個節點的資料
int list_get_last(struct list *head);
//刪除第一個節點
int list_del_first(struct list *head);
//刪除最後一個節點
int list_del_last(struct list *head);

#endif

