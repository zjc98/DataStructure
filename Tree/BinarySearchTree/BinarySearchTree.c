#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// �����������Ķ�̬����
typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    Position Left, Right;
};

// �����������ݹ����Ԫ��
Position FindRecursion(BinTree BST, ElementType X)
{
    if(!BST) return NULL;  // ����ʧ��
    if(X > (BST->Data)) return FindRecursion(BST->Right, X);
    else if(X < (BST->Data)) return FindRecursion(BST->Left, X);
    else return BST; 
}

// �����������ǵݹ����Ԫ��
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

// �����������ݹ������СԪ��
Position FindMin(BinTree BST)
{
    if(!BST) return NULL;  // ��Ϊ����������NULL
    else if(!BST->Left) return BST; // �ҵ�����˵㲢����
    else return FindMin(BST->Left);
}

// �����������������Ԫ��
Position FindMax(BinTree BST)
{
    if(BST)
        while(BST->Right)
        {
            BST = BST->Right;
        }
    return BST;
}

// �����������Ĳ���
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

// ������������ɾ��
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
            if(BST->Left && BST->Right)  // ���������ҽڵ�
            {
            Tmp = FindMin(BST->Right);   // �ҵ��Ҷ������ڵ�
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Right, BST->Data);
            }
            else  // ��ɾ����ֻ��һ���ڵ��û�нڵ�  
            {
                Tmp = BST;
                if(!BST->Left)  // ���ֻ���ҽڵ���޽ڵ�
                    BST = BST->Right;
                else           // ���ֻ����ڵ�
                    BST = BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}