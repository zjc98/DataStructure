#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

// 利用队列实现二叉树的层序遍历
typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

// Queue操作
typedef BinTree ElementType;
typedef struct Node* PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
struct QNode
{
    Position rear, front;
    int MaxSize;
};
typedef struct QNode* Queue;

bool IsEmpty(Queue Q)
{
    return (Q->front==NULL);
}

ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;

    if(IsEmpty(Q))
    {
        printf("Illegal Delete\n");
        return -1;
    }
    else
    {
        FrontCell = Q->front;
        if(Q->front==Q->rear)   // 队列中只有一个成员
        {
            Q->front=Q->rear=NULL;
        }
        else
        {
            Q->front = Q->front->Next;
        }
        FrontElem = FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }
}

bool AddQ(Queue Q, ElementType X)
{
    if(Q->front == NULL)
    {
        Position Add = (Position)malloc(sizeof(struct Node));
        Add->Data = X;
        Add->Next = NULL;
        Q->front = Q->rear = Add;
    }
    else
    {
        Position Add = (Position)malloc(sizeof(struct Node));
        Add->Data = X;
        Add->Next = NULL;
        Q->rear->Next = Add;
        Q->rear = Add;
    }
    
    return true;
}

Queue CreateQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    // Q->front = Q->rear = (Queue)malloc(sizeof(struct Node));
    Q->front = NULL;
    for(int i = 0;i < 5;i++)
    {
        AddQ(Q, 2*i+3);
    }
    return Q;
}

void LevelorderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    AddQ(Q, BT);
    while(!IsEmpty(Q))
    {
        T = DeleteQ(Q);
        printf("%d ", T->Data);
        if(T->Left) AddQ(Q, T->Left);
        if(T->Right) AddQ(Q, T->Right);
    }
}