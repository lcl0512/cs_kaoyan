#include "LinkedQueue.h"
#include <cstddef>
#include <cstdlib>

void InitQueue(LinkedQueue& Q){
    Q.front = Q.rear = (LinkedNode*)malloc(sizeof(LinkedNode));// 带头结点的链式队列
    Q.front->next = NULL;
}
bool QueueEmpty(const LinkedQueue& Q){
    if(Q.rear==Q.front)
        return true;
    return false;
}
void EnQueue(LinkedQueue& Q, ElemType x){
    LinkedNode* s = (LinkedNode*)malloc(sizeof(LinkedNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue(LinkedQueue& Q, ElemType& x){
    if(Q.front == Q.rear)
        return false;
    LinkedNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(p==Q.rear)
        Q.rear = Q.front;
    free(p);
    return true;
}
bool GetHead(const LinkedQueue& Q, ElemType& x){
    if(Q.front==Q.rear)
        return false;
    x = Q.front->next->data;
    return true;
}



