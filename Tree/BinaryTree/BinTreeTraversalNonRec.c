#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"

// 利用堆栈用非递归方法实现二叉树的中序遍历

typedef BinTree ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

// 初始化堆栈
Stack createStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// 判断堆栈是否为空
bool isEmpty(Stack S)
{
    // if (S->Next!=NULL) return false;
    // else return true;
    return (S->Next == NULL);
}

// Push操作
bool Push(Stack S, ElementType X)
{
    Stack newNode = (Stack)malloc(sizeof(struct SNode));
    newNode->Data = X;
    newNode->Next = S->Next;
    S->Next = newNode;
    return true;
}

// Pop操作
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
        T = T->Right;  // 若T为叶节点，则T->Right为空，将弹出其父节点，若T为非叶节点，则父节点已弹出，将弹出右子节点，符合中序
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
        if(T->Right && Temp != T->Right)  // 若该节点存在右儿子，且上一个出栈的不为其右儿子，需要压栈
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
