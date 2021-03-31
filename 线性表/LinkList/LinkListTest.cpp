#include "LinkList.h"
#include <cstdio>
int main()
{
    LinkList L1,L2;
    List_HeadInsert(L1);
    printf("-------头插法-------\n");
    Print_LinkList(L1);
    printf("\n");
    List_TrailInsert(L2);
    printf("-------尾插法-------\n");
    Print_LinkList(L2);
    printf("\n");
    /*按序号查找结点值*/
    LNode* p =  GetElem(L1, 4);
    printf("第%d个结点是%d\n", 4, p->data);
    /*按值查找结点 */
    ElemType e;
    p = LocateElem(L1, 4);
    printf("查找结点是%d\n", p->data);
    
    printf("\n-------原数据-------\n");
    Print_LinkList(L2);
    printf("\n");

    /*向一个结点后插入结点*/
    Insert(L2, 4, 99);
    printf("-------向第4个结点后插入99-------\n");
    Print_LinkList(L2);
    printf("\n");

    /*向一个结点前插入结点*/
    Insert_Prev(L2, 7, 77);
    printf("-------向第7个结点前插入77-------\n");
    Print_LinkList(L2);
    printf("\n");

    /*按序号删除结点，e接收删除结点的值*/
    Delete_Elem(L2, 7, e);
    printf("-------删除第7个结点%d-------\n",e);
    Print_LinkList(L2);
    printf("\n");

    /*按值删除结点*/
    Delete_ElemByValue(L2, 3);
    printf("-------删除第3个结点-------\n");
    Print_LinkList(L2);
    printf("\n");

    /*求表长*/
    int len = Length(L2);
    printf("表长：%d\n", len);
    return 0;
}

