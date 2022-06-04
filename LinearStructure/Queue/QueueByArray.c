#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 用数组实现循环队列
// 队列基本操作：
// Queue CreateQueue(int MaxSize): 生成空队列，最大尺寸为MaxSize
// bool IsFull(Queue Q): 判断Q是否已满，true已满，false未满
// bool AddQ(Queue Q, ElementType X): 将元素X压入队列Q中，成功返回true，失败返回false
// bool IsEmpty(Queue Q): 判断Q是否空，若空返回true，否则返回false
// ElementType DeleteQ(Queue Q): 删除并返回队列头元素，若队列为空，返回错误信息，否则返回删除的元素
// 设置两个指针：
// front：指向队列头，第一个元素的前一个索引
// rear：指向队列尾，最后一个有元素的索引

// 定义队列
typedef int Position;
typedef int ElementType;
typedef struct QNode *PtrToQNode;
struct QNode
{
    Position front, rear;
    ElementType *Data;
    int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = Q->rear = 0;
    Q->MaxSize = MaxSize;
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    return Q;
}

bool IsFull(Queue Q)
{
    return (Q->rear + 1) % Q->MaxSize == Q->front;
}

bool AddQ(Queue Q, ElementType X)
{
    if (IsFull(Q))
    {
        printf("Queue is full, illegal add\n");
        return false;
    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->MaxSize;
        Q->Data[Q->rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->front == Q->rear);
}

ElementType QDelete(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue is empty, illegal delete\n");
        return -1;
    }
    else
    {
        Q->front = (Q->front + 1) % Q->MaxSize;
        return Q->Data[Q->front];
    }
}

void PrintQueue(Queue Q)
{
    Position p = (Q->front + 1)%Q->MaxSize;
    printf("Queue elements: ");
    while (p != Q->rear)
    {
        printf("%d ", Q->Data[p]);
        p = (p+1)%Q->MaxSize;
    }
    printf("%d ", Q->Data[p]);
    printf("\n");
}

int main()
{
    Queue q = CreateQueue(5);
    bool ret;
    int data;
    for (int i = 0; i < 4; i++)
    {
        ret = AddQ(q, 2 * i + 3);
    }
    printf("q:\n");
    PrintQueue(q);

    data = QDelete(q);
    data = QDelete(q);
    printf("after delete:\n");
    PrintQueue(q);

    ret = AddQ(q,100);
    ret = AddQ(q,100);
    printf("after add:\n");
    PrintQueue(q);

    free(q);
    system("pause");
    return 0;
}