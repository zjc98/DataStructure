#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// 构造Huffman Tree
typedef struct HTNode* HuffmanTree;
struct HTNode{
    int Weight;
    HuffmanTree Left;
    HuffmanTree Right;
};

typedef struct HNode* MinHeap;
typedef HuffmanTree ElementType ;
struct HNode
{
    ElementType* Data;
    int size;
    int capacity;
};
MinHeap DeleteMin(MinHeap H)    // 删除最小堆中最小的元素
{
    ElementType Min, X;
    int Parent, Child;
    if(H->size==0) return NULL;  // 若堆为空，返回NULL
    else{
        Min = H->Data[1];
        X = H->Data[H->size--];
        for(Parent=1;Parent*2<=H->size;Parent=Child)
        {
            Child = Parent*2;
            if((Child!=H->size)&&(H->Data[Child] > H->Data[Child+1]))
                Child++;
            if(X <= H->Data[Child]) break;
            else H->Data[Parent] = H->Data[Child];
        }
        H->Data[Parent] = X;
        return Min;
    }
}
MinHeap BuildHeap(MinHeap H);     // 按权值调整最小堆
MinHeap Insert(MinHeap H1, MinHeap H2);  // 将H2插入H1中

// 利用最小堆构造Huffman Tree
HuffmanTree Huffman(MinHeap H)
{
    // 最小堆中的ElementType是HuffmanTree
    int i,N;
    HuffmanTree T;

    BuildHeap(H);  // 按权值将H调整为最小堆

    N = H->size;
    for(i=1;i<N;i++)
    {
        T = (HuffmanTree)malloc(sizeof(struct HTNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    return DeleteMin(H);

}