#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// �ѵĲ�����
// MaxHeap CreateHeap(int MaxSize): �����յ����ѣ�����󳤶�ΪMaxSize
// bool isFull(MaxHeap H): �ж�����H�Ƿ����������Ƿ���true���񷵻�false
// bool isEmpty(Maxheap H): �ж�����H�Ƿ��ѿ�
// bool Insert(MaxHeap H, ElementType X): ��Ԫ��X��������H����������������false������ɹ�����true
// ElementType DeleteMax(MaxHeap H): ɾ��������H�е����Ԫ��

typedef int ElementType;
typedef struct HNode *Heap;
struct HNode
{
    ElementType *Data; // �洢���ݵ�����
    int size;          // ���е�ǰ��Ԫ����
    int capacity       // �ѵ��������
};
typedef Heap MaxHeap;

#define MAXDATA 1000 // �趨���е����Ԫ��
MaxHeap CreateHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType *)malloc(sizeof(ElementType) * (MaxSize + 1));
    H->size = 0;
    H->capacity = MaxSize;
    H->Data[0] = MAXDATA;

    return H;
}

bool isFull(MaxHeap H)
{
    return (H->size == H->capacity);
}

bool Insert(MaxHeap H, ElementType X)
{
    int i;
    if (isFull(H))
    {
        printf("Heap is full.\n");
        return 0;
    }
    else
    {
        i = ++(H->size);
        for (; X > H->Data[i / 2]; i /= 2)
        {
            H->Data[i] = H->Data[i / 2];
        }
        H->Data[i] = X;
        return true;
    }
}

bool isEmpty(MaxHeap H)
{
    return (H->size == 0);
}

ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, X;
    if (isEmpty(H))
    {
        printf("Heap is empty.\n");
        return -1;
    }
    else
    {
        MaxItem = H->Data[1];
        X = H->Data[H->size--];
        for (Parent = 1; Parent * 2 <= H->size; Parent = Child)
        {
            // ѡȡ���ӽڵ��нϴ��һ��
            Child = Parent * 2;
            if ((Child != H->size) && (H->Data[Child] < H->Data[Child + 1]))
                Child ++;
            
            if(X >= H->Data[Child]) break;
            else H->Data[Parent] = H->Data[Child];
        }
        H->Data[Parent] = X;
        return MaxItem;
    }
}

// ���ѵĽ���:�ȸ�������˳������ȫ��������Ȼ������һ�����ӽڵ�Ľڵ㿪ʼ��������
void PercDown(MaxHeap H, int p)
{
    // ��H����H->Data[p]Ϊ�����Ӷѵ���Ϊ����
    int Parent,Child;
    ElementType X;

    X = H->Data[p];
    for(Parent=p;Parent*2 < H->size;Parent=Child)
    {
        // ȷ���ӽڵ�
        Child = Parent * 2;
        if((Child!=H->size) && (H->Data[Child]<H->Data[Child+1]))
            Child++;
        
        if(X > H->Data[Child]) break;
        else H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

void BuildHeap(MaxHeap H)
{
    int i;
    for(i=H->size/2;i>0;i--)
        PercDown(H, i);
}