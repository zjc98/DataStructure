#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// ����Huffman Tree
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
MinHeap DeleteMin(MinHeap H)    // ɾ����С������С��Ԫ��
{
    ElementType Min, X;
    int Parent, Child;
    if(H->size==0) return NULL;  // ����Ϊ�գ�����NULL
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
MinHeap BuildHeap(MinHeap H);     // ��Ȩֵ������С��
MinHeap Insert(MinHeap H1, MinHeap H2);  // ��H2����H1��

// ������С�ѹ���Huffman Tree
HuffmanTree Huffman(MinHeap H)
{
    // ��С���е�ElementType��HuffmanTree
    int i,N;
    HuffmanTree T;

    BuildHeap(H);  // ��Ȩֵ��H����Ϊ��С��

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