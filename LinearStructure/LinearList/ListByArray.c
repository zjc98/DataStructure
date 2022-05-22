#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 线性表（List）的定义与实现
// 线性表的基本操作：
// List MakeEmpty()：初始化一个空表
// ElementType FindKth(List L, int i): 根据指定的位序i，返回L中的相应元素
// Position Find(List L, ElementType X): 已知X，返回L中与X相同的第一个元素的索引，不存在则返回错误信息
// bool Insert(List L, ElementType X, int i): 在L的指定位序i前插入一个新元素X，成功返回true，失败返回false
// bool Delete(List L, int i): 从L中删除指定位序i的元素，成功返回true，失败返回false
// int Length(List): 返回线性表中L的长度

// 用顺序存储，即数组实现线性表

// 定义线性表
#define MAXSIZE 100 // 定义最大表长
typedef int Position;
typedef int ElementType;
typedef struct LNode *PtrToLNode;

struct LNode
{
    Position Last; // 指向存数的最后一个索引，空表为-1
    ElementType Data[MAXSIZE];
};
typedef PtrToLNode List;

// 初始化线性表
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// 查找索引为i的元素
ElementType FindKth(List L, Position i)
{
    return L->Data[i-1];
}

// 查找元素
#define ERROR -1
Position Find(List L, ElementType X)
{
    Position i = 0;
    while (i <= L->Last && L->Data[i] != X)
    {
        i++;
    }
    if (i > L->Last)
        return ERROR;
    else
        return i;
}

// 插入元素
bool Insert(List L, ElementType X, int i)
{
    // 第i个元素的索引为i-1
    // 判断表是否满
    if (L->Last == MAXSIZE - 1)
    {
        printf("List is full");
        return false;
    }

    // 判断插入合法性
    if (i < 1 || i > L->Last + 2)
    {
        printf("Insert Position is illegal");
        return false;
    }

    for (int j = L->Last; j >= i - 1; j--)
    {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i - 1] = X;
    L->Last++;
    return true;
}

// 删除指定位序的元素
bool Delete(List L, int i)
{
    // 位序i的元素的下标为i-1
    if (i<1 || i>L->Last+1) 
    {
        printf("The order is illegal");
        return false;
    }
    for(int j=i;j<=L->Last;j++)
    {
        L->Data[j-1]=L->Data[j];
    }
    L->Last--;
    return true;
}

// 返回线性表的长度
int Length(List L)
{
    return L->Last+1;
}

// 打印线性表
void PrintList(List L)
{
    for(int j = 0;j<=L->Last;j++)
    {
        printf("%d  ", L->Data[j]);
    }
    printf("\nList Length = %d\n", Length(L));
}

int main()
{
    List list = MakeEmpty();
    for (int i = 1; i < 6; i++)
    {
        int num = i * 2 + 1;
        bool ret = Insert(list, num, i);
    }
    PrintList(list);
    // 测试FindKth，打印第二个数
    ElementType secend = FindKth(list, 2);
    printf("The second number is %d\n", secend);
    // 测试Find，寻找7
    Position pos = Find(list, 7);
    printf("The index of 7 is %d\n", pos);
    // 测试Insert，在第4个位置插入99
    bool ret2 = Insert(list, 99, 4);
    printf("Insert 99 in the fourth place:\n");
    PrintList(list);
    // 测试Delete，删除第三个数
    printf("After delete the third element:\n");
    bool ret3 = Delete(list,3);
    PrintList(list);
}