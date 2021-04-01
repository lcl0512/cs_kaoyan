#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include "SqList.h"

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
    srand((unsigned)time(NULL));
    for(int i=0;i<15;++i){
        x = rand()%10;
        ListInsert(L,1,x);
    }
    qsort(L.data,L.length,sizeof(ElemType),cmp);
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

int main()
{
    SqList L;
    InitList(L);
    for(int i=0;i<10;++i){
        ListInsert(L,1,i*i);
    }
    printf("--------初始数据--------\n");
    PrintList(L);
    printf("\n");

    ListInsert(L, 3, 3);
    printf("--------在位置3插入3后--------\n");
    PrintList(L);
    printf("\n");

    ElemType deletedElem;
    ListDelete(L, 5, deletedElem);
    printf("--------删除位置5的元素后--------\n");
    PrintList(L);
    printf("\n");

    int pos = LocateElem(L, 49); 
    printf("%d在第%d个位置.\n", 49, pos);
    
    printf("--------测试删除最小--------\n");
    Test_Delete_Min();

    printf("--------测试逆置顺序表----------\n");
    Test_Reverse_List();

    printf("--------测试删除所有x-----------\n");
    Test_Delete_Elem();
    
    
    printf("--------测试有序顺序表的范围删除-----------\n");
    Test_Delete_Range();
    printf("--------测试删除所有x-----------\n");
    printf("--------测试删除所有x-----------\n");
    return 0;
}

