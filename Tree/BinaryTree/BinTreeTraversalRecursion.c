#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 用链表实现二叉树，二叉树操作：
// bool IsEmpty(BinTree BT): 判断二叉树是否为空
// void Traversal(BinTree BT): 遍历二叉树，有先序、中序、后序三种
// BinTree CreateBinTree(): 创建一个二叉树，有先序创建与层序创建两种

typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

// 中序递归遍历
void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}

// 先序递归遍历
void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

// 后序递归遍历
void PostorderTraversal(BinTree BT)
{
    if(BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%d ", BT->Data);
    }
}