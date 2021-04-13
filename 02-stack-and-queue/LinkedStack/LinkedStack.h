#ifndef LINKED_STACK_H
#define LINKED_STACK_H
typedef int ElemType;
typedef struct LinkedNode{
    ElemType data;
    struct LinkedNode* next;
}LinkedNode,*LinkedStack;

void InitStack(LinkedStack& S);
bool StackEmpty(const LinkedStack& S);
bool Push(LinkedStack& S, ElemType x);
bool Pop(LinkedStack& S, ElemType& x);
bool GetTop(LinkedStack& S, ElemType& x);

#endif
