#include <cstdio>
#include "LinkedQueue.h"
int main()
{
    LinkedQueue Q;
    InitQueue(Q);
    if(QueueEmpty(Q)){
        printf("Queue is empty.\n");
    }
    for(int i =1;i<=10;++i)
        EnQueue(Q, i);
    if(QueueEmpty(Q)){
        printf("Queue is empty.\n");
    }else{
        printf("Queue is not empty.\n");
    }
    ElemType x;
    for(int i =1;i<=10;++i){
        DeQueue(Q, x);
        printf("%d ", x);
    }
    printf("\n");
    if(QueueEmpty(Q)){
        printf("Queue is empty.\n");
    }
    return 0;
}

