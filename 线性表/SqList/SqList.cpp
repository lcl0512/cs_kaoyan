#include <cstdio>
#include "SqList.h"
/**
 *
 *
 */
void InitList(SqList& L){
    L.length = 0;
}
/**
 *
 *
 */
bool ListInsert(SqList &L, int i, ElemType e){
    if(i<1 || i > L.length+1){
        return false;
    }
    if(L.length >= MaxSize){
        return false;
    }
    for(int j = L.length; j >= i; --j){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

/**
 *
 *
 */
bool ListDelete(SqList& L,int i, ElemType &e){
    if(i<1 || i > L.length)
        return false;
    e = L.data[i-1];
    for(int j = i; j<L.length; ++j){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
/**
 *
 *
 *
 */
int LocateElem(SqList L,ElemType e){
    int i;
    for(i = 0; i < L.length;++i){
        if(L.data[i]==e)
            return i + 1;
    }
    return 0;
}

void PrintList(const SqList& L){
    printf("[");
    for(int i=0;i< L.length - 1;++i){
        printf(" %d,", L.data[i]);
    }
    if(L.length==0)
        printf("]\n"); 
    else
        printf(" %d ]\n",L.data[L.length - 1]);
}


ElemType Delete_Min(SqList& L){
    if(L.length==0){
        printf("顺序表为空，删除失败……");
        return -1;
    }
    int ret = L.data[0];
    int min_i = 0;
    for(int i=1;i<L.length; ++i){
        if(L.data[i]<ret){
            ret = L.data[i];
            min_i = i;
        }
    }
    L.data[min_i] = L.data[L.length-1];// 空出的位置用最后一个元素填补
    L.length--; // 长度减一
    return ret;
}

void swap(ElemType& a, ElemType& b){
    ElemType tmp = a;
    a = b;
    b = tmp;
}
void Reverse_List(SqList& L){
    int n = L.length;
    for(int i=0;i < n/2; ++i){
        swap(L.data[i], L.data[n-i - 1]);
    }
}

int Delete_Elem(SqList& L,ElemType x){
    int k = 0;
    int old_len = L.length;
    for(int i=0;i < L.length; ++i){
        if(L.data[i]!=x){
            L.data[k] = L.data[i];
            ++k;
        }
    }
    L.length = k;
    return old_len - k;
}


int Delete_Elem_Range(SqList& L, ElemType s, ElemType t){
    if(L.length==0 || s>=t){
        printf("顺序表为空或s和t不合理……");
        return -1;
    }
    int k = 0;
    int i = 0;
    while(i < L.length && L.data[i]<s) ++i;
    if(i==L.length)
        return 0;
    k = L.length - 1;
    while(k >= i && L.data[k] > t) --k;
    if(k < i)
        return 0;
    while(k<L.length - 1){
        L.data[i++] = L.data[++k];
    }
    L.length -= (k-i+1);
    return k - i + 1;
}



int Delete_Elem_Range2(SqList& L, ElemType s, ElemType t){
    if(L.length==0 || s>=t){
        printf("顺序表为空或s和t不合理……");
        return -1;
    }
    int k = 0;
    for(int i=0; i < L.length; ++i){
        if(L.data[i]>=s && L.data[i]<=t){
            ++k;
        }else{
            L.data[i-k] = L.data[i];
        }
    }
    return k;
}



int Delete_Same(SqList& L){
    int count = 0;
    for(int k = 0,i = 1; i< L.length; ++i){
        if(L.data[k]!=L.data[i])
            L.data[++k] = L.data[i];
        else
            count++;
    }
    L.length -= count;
    return count;
}
