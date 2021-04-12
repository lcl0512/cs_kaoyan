#include "LinkedStack.h"
#include <cstdlib>
void InitStack(LinkedStack& S){
    S = NULL;
}
bool StackEmpty(const LinkedStack& S){
    if(S==NULL){
        return true;
    }
    return false;
}
bool Push(LinkedStack& S, ElemType x){
    LinkedNode* p = (LinkedNode*)malloc(sizeof(LinkedNode));
    p->data = x;
    LinkedNode* q = S;
    p->next = q;
    S = p;
    return true;
}
bool Pop(LinkedStack& S, ElemType& x){
    if(S==NULL)
        return false;
    LinkedNode* p = S;
    x = p->data;
    S = S->next;
    free(p);
    return true;
}
bool GetTop(LinkedStack& S, ElemType& x){
    if(S==NULL)
        return false;
    x = S->data;
    return true;
}


