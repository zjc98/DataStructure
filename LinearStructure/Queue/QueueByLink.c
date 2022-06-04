#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 用不带头结点的链表实现队列

typedef int ElementType;
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

void PrintQueue(Queue Q)
{
    Position p = Q->front;
    while(p->Next!=NULL)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("%d\n", p->Data);
}

int main()
{
    Queue q = CreateQueue();
    PrintQueue(q);

    int deleteData;
    deleteData = DeleteQ(q);
    printf("Delete data:%d\n", deleteData);

    printf("After delete: \n");
    PrintQueue(q);

    system("pause");
    return 0;
}