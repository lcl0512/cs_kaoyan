#ifndef SQ_STACK_H
#define SQ_STACK_H

#define MaxSize 128
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack& S);
bool StackEmpty(const SqStack& S);
bool Push(SqStack& S, ElemType x);
bool Pop(SqStack& S, ElemType& x);
bool GetTop(SqStack& S, ElemType& x);

#endif

