#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "SqList.h"
#include "SqListQuestion.h"

int cmp(const void* a,const void* b){
    if(*(ElemType*)a<*(ElemType*)b)
        return -1;
    else
        return 1;
}

void Test_Reverse_List(){
    SqList L;
    InitList(L);
    for(int i=0;i<10;++i){
        ListInsert(L,1,i*i);
    }
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");
    Reverse_List(L);
    printf("--------逆置链表--------\n");
    PrintList(L);
    printf("\n");

}

void Test_Delete_Min(){
    SqList L;
    InitList(L);
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i){
        int x = rand()%20;
        ListInsert(L,1,x);
    }
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");
    Delete_Min(L);
    printf("--------删除最小--------\n");
    PrintList(L);
    printf("\n");
}

void Test_Delete_Range(){
    SqList L;
    int x;
    InitList(L);
    srand((unsigned)time(NULL)); // 以时间作为随机数的种子
    for(int i=0;i<15;++i){
        x = rand()%10; // 产生0-9之间的随机数
        ListInsert(L,1,x);
    }
    qsort(L.data,L.length,sizeof(ElemType),cmp);// 快速排序
    ElemType s = L.data[rand()%5];
    ElemType t = L.data[rand()%10 + 5];
    //ElemType s = 0;
    //ElemType t = 10;
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");
    Delete_Elem_Range(L, s, t);
    printf("--------删除顺序表中所有值从%d到%d的元素--------\n", s, t);
    PrintList(L);
    printf("\n");

}

void Test_Delete_Range2(){
    SqList L;
    int x;
    InitList(L);
    srand((unsigned)time(NULL)); // 以时间作为随机数的种子
    for(int i=0;i<15;++i){
        x = rand()%10; // 产生0-9之间的随机数
        ListInsert(L,1,x);
    }
    ElemType s = L.data[rand()%5];
    ElemType t = L.data[rand()%10 + 5];
    if(s>t)
        swap(s,t);
    //ElemType s = 0;
    //ElemType t = 10;
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");
    Delete_Elem_Range2(L, s, t);
    printf("--------删除顺序表中所有值从%d到%d的元素--------\n", s, t);
    PrintList(L);
    printf("\n");

}

void Test_Delete_Elem(){
    SqList L;
    int x;
    InitList(L);
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i){
        x = rand()%10;
        ListInsert(L,1,x);
    }
    x = L.data[rand()%10];
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");
    Delete_Elem(L, x);
    printf("--------删除顺序表中所有值为%d的元素--------\n", x);
    PrintList(L);
    printf("\n");

}
void Test_Delete_Same(){
    SqList L;
    int x;
    InitList(L);
    srand((unsigned)time(NULL));
    for(int i=0;i<15;++i){
        x = rand()%10;
        ListInsert(L,1,x);
    }
    qsort(L.data, L.length, sizeof(ElemType),cmp);
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");
    Delete_Same(L);
    printf("--------删除顺序表重复的元素--------\n");
    PrintList(L);
    printf("\n");
}

void Test_Merge_List(){
    SqList L1,L2,L;
    int x;
    InitList(L2);
    InitList(L1);
    InitList(L);
    srand((unsigned)time(NULL)); // 以时间作为随机数的种子
    for(int i=0;i<10;++i){
        x = rand()%20; // 产生0-9之间的随机数
        ListInsert(L2,1,x);
        x = rand()%20;
        ListInsert(L1,1,x);
    }

    qsort(L1.data,L1.length,sizeof(ElemType),cmp);// 快速排序
    qsort(L2.data,L2.length,sizeof(ElemType),cmp);// 快速排序
    //EL2emType s = 0;
    //EL2emType t = 10;
    printf("--------初始数据--------\n");
    PrintList(L1);
    PrintList(L2);
    printf("\n");
    Merge_List(L1,L2,L);
    printf("--------归并后的链表--------\n");
    PrintList(L);
    printf("\n");
}

void Test_Reverse(){
    ElemType A[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i){
        A[i] = rand()%10;
    }
    printf("--------初始数据--------\n");
    print_Arr(A,10);
    printf("\n");
    Reverse(A,3,7);
    printf("--------前3个和后7个数互换位置--------\n");
    print_Arr(A,10);
    printf("\n");
}

void Test_SearchExchangeInsert(){
    ElemType A[15];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i){
        A[i] = rand()%10;
    }
    int x = rand()%15;
    qsort(A,10,sizeof(ElemType),cmp);
    printf("--------初始数据--------\n");
    print_Arr(A,10);
    printf("\n");
    SearchExchangInsert(A,10,x);

    printf("--------查找后交换或插入%d--------\n",x);
    print_Arr(A,11);
    printf("\n");

}
void Test_MeanSearch(){
    ElemType a[]={2,4,6,8,20};
    ElemType b[]={11,13,15,17,19};
    //srand((unsigned)time(NULL));
    //for(int i=0;i<10;++i){
    //    a[i] = rand()%20;
    //    b[i] = rand()%20;
    //}
    //qsort(a,10,sizeof(ElemType),cmp);
    //qsort(b,10,sizeof(ElemType),cmp);
    
    print_Arr(a,5);
    print_Arr(b,5);
    int ret = MeanSearch(a,b,5);
    printf("中位数：%d\n", ret);
}
int main()
{  
    printf("--------测试删除最小--------\n");
    Test_Delete_Min();

    printf("--------测试逆置顺序表----------\n");
    Test_Reverse_List();

    printf("--------测试删除所有x-----------\n");
    Test_Delete_Elem();
    
    
    printf("--------测试有序顺序表的范围删除-----------\n");
    Test_Delete_Range();

    printf("--------测试顺序表的范围删除-----------\n");
    Test_Delete_Range2();


    printf("--------测试删除相同-----------\n");
    Test_Delete_Same();

    
    printf("--------测试归并有序链表-----------\n");
    Test_Merge_List();

    printf("--------测试逆转数组部分-----------\n");
    Test_Reverse();

    printf("--------测试查找或插入-----------\n");
    Test_SearchExchangeInsert();

    printf("--------测试中位数查找----------\n");
    Test_MeanSearch();

    return 0;
}

