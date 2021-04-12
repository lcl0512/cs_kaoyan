#include "SqStack.h"

void InitStack(SqStack& S){
    S.top = -1;
}
bool StackEmpty(const SqStack& S){
    if(S.top==-1)
        return true;
    else
        return false;
}
bool Push(SqStack& S, ElemType x){
    if(S.top+1>=MaxSize){
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    return true;
}
bool Pop(SqStack& S, ElemType& x){
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack& S, ElemType& x){
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top];
    return true;
}


