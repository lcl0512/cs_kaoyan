#include "Double_LinkList.h"
#include <cstdio>
#include <cstdlib>
#include <pthread.h>

void creat_DLinkList(DLinkList& L){
    L = (DLinkList)malloc(sizeof(DNode));
    ElemType x;
    L->next = NULL;
    L->prior = NULL;
    DNode* p = L;
    scanf("%d",x);
    while(x!=9999){
        DNode* s = (DNode*) malloc(sizeof(DNode));
        s->data = x;
        s->next = NULL;
        p->next = s;
        s->prior = p;
        p = s;
        scanf("%d",x);
    }
}

DNode* get_node(DLinkList& L, int i){
    if(i<0){
        return NULL;
    }else if(i==0){
        return L;
    }
    DNode* p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    return p; 
}
/*插入值x作为后继*/
void insert_as_succ(DLinkList& L, int i, ElemType x){
    DNode* s = (DNode*) malloc(sizeof(DNode));
    s->data = x;
    DNode* p = get_node(L,i);
    if(p==NULL)
        return;
    s->next = p->next;
    s->prior = p;
    if(p->next)
        p->next->prior= s;
    p->next = s;
}
/*删除值为x的结点*/
void delete_x(DLinkList &L, ElemType x){

}

