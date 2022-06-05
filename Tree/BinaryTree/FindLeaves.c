#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

// ���������������Ҷ�ڵ�
typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderPrintLeaves(BinTree BT)
{
    if(BT)
    {
        if(BT->Left && BT->Right)
        {
            printf("%d ", BT->Data);    
        }
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}