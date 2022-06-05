#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"

// ���ö�ջ�÷ǵݹ鷽��ʵ�ֶ��������������

typedef BinTree ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

// ��ʼ����ջ
Stack createStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// �ж϶�ջ�Ƿ�Ϊ��
bool isEmpty(Stack S)
{
    // if (S->Next!=NULL) return false;
    // else return true;
    return (S->Next == NULL);
}

// Push����
bool Push(Stack S, ElementType X)
{
    Stack newNode = (Stack)malloc(sizeof(struct SNode));
    newNode->Data = X;
    newNode->Next = S->Next;
    S->Next = newNode;
    return true;
}

// Pop����
ElementType Pop(Stack S)
{
    if (isEmpty(S))
    {
        printf("The stack is empty.\n");
        return 0;
    }
    else
    {
        Stack TmpNode = S->Next;
        S->Next = TmpNode->Next;
        ElementType x = TmpNode->Data;
        free(TmpNode);
        return x;
    }
}

typedef struct TNode* Position;
typedef Position BinTree;
typedef int BTElem;
struct TNode
{
    BTElem Data;
    BinTree Left;
    BinTree Right;
};

void InorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = createStack();
    T = BT;
    while(T || !isEmpty(S))
    {
        while(T)
        {
            Push(S, T);
            T = T->Left;
        }
        T = Pop(S);
        printf("%d ", T->Data);
        T = T->Right;  // ��TΪҶ�ڵ㣬��T->RightΪ�գ��������丸�ڵ㣬��TΪ��Ҷ�ڵ㣬�򸸽ڵ��ѵ��������������ӽڵ㣬��������
    }
}

void PreorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = createStack();
    T = BT;
    while(T || !isEmpty(S))
    {
        while(T)
        {
            printf("%d ",T->Data);
            Push(S, T);
            T->Left;
        }
        T = Pop(S);
        T = T->Right;
    }
}

void PostorderTraversal(BinTree BT)
{
    BinTree T, Temp;
    Stack S = createStack();
    T = BT;
    while(T || !isEmpty(S))
    {
        while(T)
        {
            Push(S, T);
            T->Left;
        }
        T = Pop(S);
        Temp = T;
        if(T->Right && Temp != T->Right)  // ���ýڵ�����Ҷ��ӣ�����һ����ջ�Ĳ�Ϊ���Ҷ��ӣ���Ҫѹջ
        {
            Push(S, T);
            T = T->Right;
        }
        else
        {
            printf("%d ",T->Data);
            T = T->Right;
        }
    }
}
