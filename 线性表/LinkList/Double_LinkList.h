#ifndef DOUBLE_LINKLIST_H
#define DOUBLE_LINKLIST_H
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode* prior;
    struct DNode* next;
}DNode,*DLinkList;
/*建立双链表*/
void creat_DLinkList(DLinkList& L);
/*插入值x作为后继*/
void insert_as_succ(DLinkList& L, ElemType x);
/*删除值为x的结点*/
void delete_x(DLinkList &L, ElemType x);
#endif
