#include <cstdio>
#include "SqStack.h"
int main()
{   
    SqStack S;
    ElemType x;
    InitStack(S);
    if(StackEmpty(S)){
        printf("Stack is empty.\n");
    }else{
        printf("Stack is not empty.\n");
    }
    for(int i = 0;i<10; ++i){
        printf("%d ", i*2);
        Push(S, i*2);
    }
    printf("\n");
    GetTop(S, x);
    printf("top = %d\n", x);
    for(int i = 0;i<10; ++i){
        Pop(S,x);
        printf("%d ", x);
    }
    printf("\n");
    if(StackEmpty(S)){
        printf("Stack is empty.\n");
    }
    return 0;
}

    
