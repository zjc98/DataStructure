#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// 二叉搜索树的动态查找
typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    Position Left, Right;
};

// 二叉搜索树递归查找元素
Position FindRecursion(BinTree BST, ElementType X)
{
    if(!BST) return NULL;  // 查找失败
    if(X > (BST->Data)) return FindRecursion(BST->Right, X);
    else if(X < (BST->Data)) return FindRecursion(BST->Left, X);
    else return BST; 
}

// 二叉搜索树非递归查找元素
Position Find(BinTree BST, ElementType X)
{
    while(BST)
    {
        if(X > (BST->Data)) BST = BST -> Right;
        else if(X < (BST->Data)) BST = BST -> Left;
        else break;
    }
    return BST;
}

// 二叉搜索树递归查找最小元素
Position FindMin(BinTree BST)
{
    if(!BST) return NULL;  // 若为空树，返回NULL
    else if(!BST->Left) return BST; // 找到最左端点并返回
    else return FindMin(BST->Left);
}

// 二叉搜索树查找最大元素
Position FindMax(BinTree BST)
{
    if(BST)
        while(BST->Right)
        {
            BST = BST->Right;
        }
    return BST;
}

// 二叉搜索树的插入
BinTree Insert(BinTree BST, ElementType X)
{
    if(!BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else
    {
        if(X < BST->Data) 
            BST->Left = Insert(BST->Left, X);
        else if(X > BST->Data) 
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}

// 二叉搜索树的删除
BinTree Delete(BinTree BST, ElementType X)
{
    Position Tmp;
    if(!BST)
        printf("Not search.\n");
    else
    {
        if(X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else
        {
            if(BST->Left && BST->Right)  // 假设有左右节点
            {
            Tmp = FindMin(BST->Right);   // 找到右儿子最大节点
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Right, BST->Data);
            }
            else  // 被删除的只有一个节点或没有节点  
            {
                Tmp = BST;
                if(!BST->Left)  // 如果只有右节点或无节点
                    BST = BST->Right;
                else           // 如果只有左节点
                    BST = BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}