#ifndef BINTREE_h
#define BINTREE_h
typedef int ElemType;
typedef struct BinNode{
    ElemType data;
    struct BinNode *left;
    struct BinNode *right;
}BinNode,*BinTree;
// 按层次建立二叉树
void initBinTree(BinTree& T, ElemType* arr, int n);
void preorder(const BinTree& T, void (*visit)(BinNode*));
void preorder2(const BinTree& T, void (*visit)(BinNode*));

void postorder(const BinTree& T, void (*visit)(BinNode*));
void postorder2(const BinTree& T, void (*visit)(BinNode*));

void inorder(const BinTree& T, void (*visit)(BinNode*));
void inorder2(const BinTree& T, void (*visit)(BinNode*));

void levelOrder(BinTree& T, void (*visit)(BinNode*));
#endif

