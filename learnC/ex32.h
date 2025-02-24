#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {//单个链表节点，包含指向前后两个元素的指针以及当前节点存储的值
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {//链表，元素统计以及前后两个元素
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();//创建链表
void List_destroy(List *list);//销毁链表
void List_clear(List *list);//清空链表
void List_clear_destroy(List *list);//清空并销毁链表

#define List_count(A) ((A)->count)//获取链表节点个数
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)//获取第一个节点的值
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)//先进行检测，获取最后一个节点的值

//模拟stack
void List_push(List *list, void *value);//将新的值存储进链表
void *List_pop(List *list);//弹出最新push的值

void List_unshift(List *list, void *value);
void *List_shift(List *list);

void *List_remove(List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) 
	ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif

