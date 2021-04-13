#include "SqListQuestion.h"
#include <cstdio>
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
    L.length -= k;
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


bool Merge_List(const SqList& L1,const SqList& L2, SqList& L){
    if(L1.length + L2.length > MaxSize)
        return false;
    int i=0;
    int j=0;
    int k =0;
    while(i<L1.length && j<L2.length){
        if(L1.data[i]<L2.data[j]){
           // ListInsert(L, L.length+1, L1.data[i++]);
           L.data[k++] = L1.data[i++];
        }else{
            //ListInsert(L,L.length+1, L2.data[j++]);
            L.data[k++] = L2.data[j++];
        }
    }
    while(i<L1.length){
        //ListInsert(L, L.length+1, L1.data[i++]);
        L.data[k++] = L1.data[i++];
    }
    while(j<L2.length){
       // ListInsert(L, L.length+1, L2.data[j++]);
       L.data[k++] = L.data[j++];
    }
    L.length = L1.length + L2.length;
    return true;
}


void Reverse(ElemType A[], int m, int n){
    int i =0;
    int len = m + n;
    
    while(i<m/2){
        swap(A[i],A[m-i-1]);
        ++i;
    }
    i = 0;
    while(m + i<(m+len)/2){// i = m;
        swap(A[i+m],A[len-i-1]);
        ++i;
    }

    i = 0;
    while(i < len/2){
        swap(A[i], A[len-i-1]);
        ++i;
    }
}


void SearchExchangInsert(ElemType A[], int len, ElemType x){
    int low = 0;
    int high = len - 1;
    int mid = low + (high-low)/2;
    while(low < high){
        if(x ==  A[mid]){
            break;
        }else if(x < A[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
        mid = low + (high-low)/2;
    }
    if(x==A[mid]&&mid!=len-1){
        swap(A[mid],A[mid+1]);
        return;
    }
    if(x==A[mid]){
        return;
    }
    // A[low] < x A[high] 
    if(low >= high){
        for(int i = len;i>low+1;i--){
            A[i] = A[i-1];
        }
        A[low+1]=x;
    }    
}

int MeanSearch(ElemType A[], ElemType B[],int n){
    int l1=0,l2=0,h1=n-1,h2=n-1,m1,m2;

    while(l1 < h1 || l2 < h2){
        m1 = (l1 + h1) /2;
        m2 = (l2 + h2) /2;
        if(A[m1]==B[m2])
            return A[m1];
        if(A[m1] < B[m2]){
            if((h1 - l1 + 1) % 2==0){// 元素个数为偶数
                l1 = m1+1;
                h2 = m2;
            }else{    
                l1 = m1;
                h2 = m2;
            }
        }else{// A[m1]>B[m2]
            if((h2 - l2 + 1) % 2==0){// 元素个数为偶数
                l2 = m2+1;
                h1 = m1;
            }else{    
                l2 = m2;
                h1 = m1;
            }
        }
    }
    return A[l1] < B[l2] ? A[l1] : B[l2];
}

/*打印数组*/
void print_Arr(ElemType A[], int n){
    printf("[");
    for(int i =0 ;i<n-1;++i){
        printf(" %d,", A[i]);
    }
    if(n!=0)
        printf(" %d ]\n", A[n-1]);
    else
        printf(" ]\n");
}
