#ifndef SQ_LIST_H
#define SQ_LIST_H

#define MaxSize 50

typedef int ElemType;
typedef struct {
    ElemType  data[MaxSize];
    int length;
} SqList;
/* 顺序表初始化*/
void InitList(SqList& L);
int Length(const SqList& L);
/*插入第i个位置*/
bool ListInsert(SqList& L,int i, ElemType e);
/* 删除第i个元素*/
bool ListDelete(SqList& L,int i, ElemType &e);
int LocateElem(SqList L,ElemType e);

void PrintList(const SqList& L);
#endif
