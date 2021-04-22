#include <cstdio>
#include "Bintree.h"
#include <cstdlib>
#include <ctime>
void print(BinNode* node){
    printf("%3d",node->data);
}
int main()
{
    srand(time(NULL));
    const int n = 10;
    BinTree T;
    ElemType A[n];
    printf("-------------原始数据-------------\n");
    for(int i = 0;i<n;++i){
        A[i] = rand() % 20; 
        printf("%3d", A[i]);
    }
    printf("\n");
    printf("-------------层次遍历-------------\n");
    initBinTree(T, A, n);
    levelOrder(T, print);
    printf("\n");
    printf("-------------先序遍历-------------\n");
    preorder(T, print);
    printf("\n");
    preorder2(T, print);
    printf("\n");

    printf("-------------中序遍历-------------\n");
    inorder(T, print);
    printf("\n");
    inorder2(T, print);
    printf("\n");
    printf("-------------后序遍历-------------\n");
    postorder(T, print);
    printf("\n");
    postorder2(T, print);
    printf("\n");

    return 0;
}

