#ifndef SQ_LIST_QUESTION_H
#define SQ_LIST_QUESTION_H
#include "SqList.h"
/*习题1 删除最小值的元素 */
ElemType Delete_Min(SqList& L);
/*交换a,b的值*/
void swap(ElemType& a,ElemType& b);
/*打印数组*/
void print_Arr(ElemType A[], int n);
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
/*习题7 将两个有序顺序表合并为新的有序顺序表*/
bool Merge_List(const SqList& L1,const SqList& L2, SqList& L);
/*习题8 将数组A[m+n]位置互换*/
void Reverse(ElemType A[], int m,int n);
/*习题9 在递增有序的顺序表中查找x，找不到则插入x*/
void SearchExchangInsert(ElemType A[], int len, ElemType x);
/*习题10 将顺序表循环左移p个位置,本题与第8题相同*/

/*习题11 */
int MeanSearch(ElemType A[], ElemType B[],int n);

/*打印数组*/
void print_Arr(ElemType A[], int n);
#endif
