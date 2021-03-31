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
/*按序号查找结点值*/
LNode* GetElem(const LinkList& L, int i);
/*按值查找结点 */
LNode* LocateElem(LinkList L, ElemType e);
/*向一个结点后插入结点*/
bool Insert(LinkList& L, int i, ElemType e);
/*向一个结点前插入结点*/
bool Insert_Prev(LinkList& L, int i, ElemType e);
/*按序号删除结点，e接收删除结点的值*/
bool Delete_Elem(LinkList& L, int i, ElemType& e);
/*按值删除结点*/
bool Delete_ElemByValue(LinkList& L, ElemType e);
/*求表长*/
int Length(const LinkList& L);
/*打印链表*/
void Print_LinkList(const LinkList& L);
