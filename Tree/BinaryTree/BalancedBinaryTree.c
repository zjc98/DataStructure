#include <stdlib.h>
#include <stdio.h>

// ƽ�������
typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef int ElementType;
struct AVLNode
{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Max(int a, int b)
{
    return a > b ? a : b;
}

int GetHeight(AVLTree T);
// ƽ��������Ĳ��룬���ҷ��ص������AVL
AVLTree Insert(AVLTree T, ElementType X)
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 1;
        T->Left = T->Right = NULL;
    }

    // ����������������Ҫ����
    else if (X < T->Data)
    {
        T->Left = Insert(T->Left, X);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
            if(X < T->Left->Data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
    }

    // ����������������Ҫ����
    else if(X > T->Data)
    {
        T->Right = Insert(T->Right, X);
        if(GetHeight(T->Right) - GetHeight(T->Left) == 2)
            if(X > T->Right->Data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
    }
    T -> Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;

    return T;
}

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left), A->Height) + 1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}