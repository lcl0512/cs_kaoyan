#include "LinkList.h"
#include <cstddef>
#include <cstdlib>
#include <cstdio>

/**
 *
 *
 *
 */
LinkList List_HeadInsert(LinkList &L){
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=9999){
        s = (LNode*) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TrailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d",&x);
    while(x!=9999){
        s = (LNode*) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r  = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

LNode* GetElem(const LinkList& L, int i){
    int j = 1;
    LNode *p = L->next;
    if(i==0){
        return L;
    }else if(i<0){
        return NULL;
    }

    while(p&&j<i){
        p = p->next;
        j++;
    }
    return p;
}
/**
 *
 *
 */
LNode* LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while(p!=NULL && p->data!=e)
        p = p->next;
    return p;
}

/*向一个结点后插入结点*/
bool Insert(LinkList& L, int i, ElemType e){
    if(i<0)// 如果i==0，则在头结点后面插入
        return false;
    LNode* p = GetElem(L,i);
    LNode* s = (LNode*) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
/*向一个结点前插入结点*/
bool Insert_Prev(LinkList& L, int i, ElemType e){
    if(i<1)
        return false;
    LNode* p = GetElem(L,i-1); //找到第i个结点的前驱
    LNode* s = (LNode*) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool Delete_Elem(LinkList& L, int i, ElemType& e){
    if(i<1)
        return false;
    LNode* p = GetElem(L,i-1);
    LNode* s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}
bool Delete_ElemByValue(LinkList& L, ElemType e){
    LNode* p = L;
    while(p->next!=NULL && p->next->data!=e)
        p = p->next;
    if(p->next==NULL)
        return false;
    LNode* s = p->next;
    p->next = s->next;
    free(s);
    return true;
}

int Length(const LinkList& L){
    LNode* p = L->next;
    int i = 0;
    while(p!=NULL){
        ++i;
        p=p->next;
    }
    return i;
}

void Print_LinkList(const LinkList& L){
    LNode* p = L->next;
    if(p==NULL)
        return;
    printf("[");
    while(p->next!=NULL){
        printf(" %d,",p->data);
        p = p->next;
    }
    printf(" %d ]\n", p->data);
}
