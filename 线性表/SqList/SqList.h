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
/*习题1 删除最小值的元素 */
ElemType Delete_Min(SqList& L);
/*交换a,b的值*/
void swap(ElemType& a,ElemType& b);
/*习题2 顺序表逆置*/
void Reverse_List(SqList& L);
/*习题3 删除顺序表中所有值为x的元素, 返回删除元素的个数*/
int Delete_Elem(SqList& L,ElemType x);
/*习题4 删除有序顺序表在s与t之间（包含s和t）的所有元素*/
int Delete_Elem_Range(SqList& L, ElemType s, ElemType t);
/*习题5 删除顺序表在s与t之间（包含s和t）的所有元素*/
int Delete_Elem_Range2(SqList& L, ElemType s, ElemType t);
/*习题6 删除有序顺序表中其值重复的元素*/
int Delete_Same(SqList& L);
#endif
