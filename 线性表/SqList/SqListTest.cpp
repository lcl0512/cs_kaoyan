#include <cstdio>
#include "SqList.h"

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
    
    return 0;
}

