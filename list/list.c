#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_add(struct list_head *new, struct list_head *head)
此函式會將新結點(new)串到head之後。
list_add_tail(struct list_head *new, struct list_head *head)
此函式則是將新結點(new)插到head之前。
list_del(struct list_head *entry)
將entry從其所屬串列中移出。
list_del_init(struct list_head *entry)
此函式除了將entry從其所屬串列中移出，還會將移出的entry從新初始化。
list_empty(struct list_head *head)
檢查此串列是不是空的。
list_splice(struct list_head *list, struct list_head *head)
將兩串列串接在一起。此函式會將list所指的串列接到head之後。
list_entry(ptr, type, member)
取出ptr所指的結點。此函式會回傳一結點指標，此結點包含ptr所指到的list_head。
list_for_each(pos, head)
走訪head所指到的串列，pos則會指向每一次走訪的結點。
list_for_each_prev(pos, head)
與上一個函式相同，不過走訪順序是相反的。
list_for_each_safe(pos, n, head)

