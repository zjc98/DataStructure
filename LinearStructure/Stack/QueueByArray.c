#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ������ʵ��ѭ������
// ���л���������
// Queue CreateQueue(int MaxSize): ���ɿն��У����ߴ�ΪMaxSize
// bool IsFull(Queue Q): �ж�Q�Ƿ�������true������falseδ��
// bool AddQ(Queue Q, ElementType X): ��Ԫ��Xѹ�����Q�У��ɹ�����true��ʧ�ܷ���false
// bool IsEmpty(Queue Q): �ж�Q�Ƿ�գ����շ���true�����򷵻�false
// ElementType DeleteQ(Queue Q): ɾ�������ض���ͷԪ�أ�������Ϊ�գ����ش�����Ϣ�����򷵻�ɾ����Ԫ��
// ��������ָ�룺
// front��ָ�����ͷ����һ��Ԫ�ص�ǰһ������
// rear��ָ�����β�����һ����Ԫ�ص�����

// �������
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