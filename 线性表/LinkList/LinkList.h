#pragma once

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/*头插法建立链表*/
LinkList List_HeadInsert(LinkList &L);
/*尾插法建立链表*/
LinkList List_TrailInsert(LinkList &L);
