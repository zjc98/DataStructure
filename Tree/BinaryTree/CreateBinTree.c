#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

// ���ö��в������ɶ�����
typedef int ElementType;
typedef struct TNode* BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

#define NoInfo 0

typedef BinTree QElementType;
typedef struct Node* PtrToNode;
struct Node{
    QElementType Data;
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

QElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    QElementType FrontElem;

    // if(IsEmpty(Q))
    // {
    //     printf("Illegal Delete\n");
    //     return NULL;
    // }
    FrontCell = Q->front;
    if(Q->front==Q->rear)   // ������ֻ��һ����Ա
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
    // else
    // {
    //     FrontCell = Q->front;
    //     if(Q->front==Q->rear)   // ������ֻ��һ����Ա
    //     {
    //         Q->front=Q->rear=NULL;
    //     }
    //     else
    //     {
    //         Q->front = Q->front->Next;
    //     }
    //     FrontElem = FrontCell->Data;
    //     free(FrontCell);
    //     return FrontElem;
    // }
}

bool AddQ(Queue Q, QElementType X)
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
    return Q;
}



BinTree CreateBinTree()
{
    BinTree BT, T;
    ElementType Data;
    Queue Q = CreateQueue();
    scanf("%d", &Data);
    if(Data!=NoInfo)
    {
        // ������ڵ㵥Ԫ���������
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = NULL;
        BT->Right = NULL;
        AddQ(Q, BT);
    }
    else return NULL;  // �����ڵ�Ϊ0�����ؿ���

    while(!IsEmpty(Q))
    {
        T = DeleteQ(Q);
        scanf("%d", &Data);
        if(Data!=NoInfo)
        {
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = NULL;
            T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        
        scanf("%d", &Data);
        if(Data!=NoInfo)
        {
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = NULL;
            T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
    }
    return BT;
}

int main()
{
    BinTree bt = CreateBinTree();
    system("pause");
    return 0;
}