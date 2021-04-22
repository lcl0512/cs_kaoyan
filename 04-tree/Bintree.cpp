#include "Bintree.h"
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
void initBinTree(BinTree& T, ElemType* arr, int n){
    if(arr == NULL || n < 1){
        printf("error...");
        return;
    }
    T = (BinTree) malloc(sizeof(BinNode));
    T->left = NULL;
    T->right = NULL;
    T->data = arr[0];
    std::queue<BinNode*> que;
    que.push(T);
    for(int i=1;i<n;){
        if(!que.empty()){
            BinNode* node = que.front();
            que.pop();
            BinNode* leftNode = (BinNode*) malloc(sizeof(BinNode));
            leftNode->left = NULL;
            leftNode->right = NULL;
            leftNode->data = arr[i];
            node->left = leftNode;
            que.push(leftNode);
            ++i;
            if(i<n){
                BinNode* rightNode = (BinNode*) malloc(sizeof(BinNode));
                rightNode->left = NULL;
                rightNode->right = NULL;
                rightNode->data = arr[i];
                node->right = rightNode;
                que.push(rightNode);
                ++i;
            }
        }
    }

}

void preorder(const BinTree& T, void (*visit)(BinNode*)){
    if(T!=NULL){
        visit(T);
        preorder(T->left, visit);
        preorder(T->right, visit);
    }
}

void preorder2(const BinTree& T, void (*visit)(BinNode*)){
    std::stack<BinTree> st;
    BinTree p = T;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            visit(p);
            st.push(p);
            p = p->left;
        }else{
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
}
void postorder(const BinTree& T, void (*visit)(BinNode*)){
    if(T!=NULL){
        postorder(T->left, visit);
        postorder(T->right, visit);
        visit(T);
    }
}
void postorder2(const BinTree& T, void (*visit)(BinNode*)){
    std::stack<BinTree> st;
    BinTree p = T, q = NULL;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            st.push(p);
            p = p->left;
        }else{
            p = st.top();
            if(p->right==NULL || p->right==q){
                visit(p);
                q = p;
                st.pop();
                p = NULL;
            }else{
                p = p->right;
            }
        }
    }

}
void inorder(const BinTree& T, void (*visit)(BinNode*)){
    if(T!=NULL){
        inorder(T->left, visit);
        visit(T);
        inorder(T->right, visit);
    }
}

void inorder2(const BinTree& T, void (*visit)(BinNode*)){
    std::stack<BinTree> st;
    BinTree p = T;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            st.push(p);
            p = p->left;
        }else{
            p = st.top();
            st.pop();
            visit(p);
            p = p->right;
        }
    }
}
void levelOrder(BinTree& T, void (*visit)(BinNode*)){
    std::queue<BinNode*> que;
    BinTree p;
    que.push(T);
    while(!que.empty()){
        p = que.front();// 访问队首
        que.pop();// 队首出队
        visit(p);
        if(p->left!=NULL)
            que.push(p->left);
        if(p->right!=NULL)
            que.push(p->right);
    }
}
