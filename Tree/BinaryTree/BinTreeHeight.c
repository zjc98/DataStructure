#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

// �ݹ�ʵ������������ĸ߶�
typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

int GetHeight(BinTree BT)
{
    int HL, HR, MaxH;
    if(BT)
    {
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        MaxH = HL>HR?HL:HR;
        return (MaxH + 1);
    }
    else return 0;
}