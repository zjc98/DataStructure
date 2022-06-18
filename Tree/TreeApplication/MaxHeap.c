#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// 堆的操作：
// MaxHeap CreateHeap(int MaxSize): 创建空的最大堆，其最大长度为MaxSize
// bool isFull(MaxHeap H): 判断最大堆H是否已满，若是返回true，否返回false
// bool isEmpty(Maxheap H): 判断最大堆H是否已空
// bool Insert(MaxHeap H, ElementType X): 将元素X插入最大堆H，若堆已满，返回false，插入成功返回true
// ElementType DeleteMax(MaxHeap H): 删除并返回H中的最大元素

typedef int ElementType;
typedef struct HNode *Heap;
struct HNode
{
    ElementType *Data; // 存储数据的数组
    int size;          // 堆中当前的元素数
    int capacity       // 堆的最大容量
};
typedef Heap MaxHeap;

#define MAXDATA 1000 // 设定堆中的最大元素
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
            // 选取孩子节点中较大的一个
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

// 最大堆的建立:先根据输入顺序建立完全二叉树，然后从最后一个有子节点的节点开始进行下滤
void PercDown(MaxHeap H, int p)
{
    // 将H中以H->Data[p]为根的子堆调整为最大堆
    int Parent,Child;
    ElementType X;

    X = H->Data[p];
    for(Parent=p;Parent*2 < H->size;Parent=Child)
    {
        // 确定子节点
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