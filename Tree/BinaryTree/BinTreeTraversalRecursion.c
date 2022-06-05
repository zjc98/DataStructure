#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// ������ʵ�ֶ�������������������
// bool IsEmpty(BinTree BT): �ж϶������Ƿ�Ϊ��
// void Traversal(BinTree BT): ���������������������򡢺�������
// BinTree CreateBinTree(): ����һ���������������򴴽�����򴴽�����

typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

// ����ݹ����
void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}

// ����ݹ����
void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

// ����ݹ����
void PostorderTraversal(BinTree BT)
{
    if(BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%d ", BT->Data);
    }
}