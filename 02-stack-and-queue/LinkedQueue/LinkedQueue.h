#ifndef LINKED_QUEUE_H 
#define LINKED_QUEUE_H

#define MaxSize 64
typedef int ElemType; 
typedef struct Node{
    ElemType data;
    struct Node *next;
}LinkedNode;
typedef struct{
    LinkedNode *front;
    LinkedNode *rear;
}LinkedQueue;

void InitQueue(LinkedQueue& Q);
bool QueueEmpty(const LinkedQueue& Q);
void EnQueue(LinkedQueue& Q, ElemType x);
bool DeQueue(LinkedQueue& Q, ElemType& x);
bool GetHead(const LinkedQueue& Q, ElemType& x);

#endif
