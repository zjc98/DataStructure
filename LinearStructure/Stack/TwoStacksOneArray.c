#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 用一个数组实现两个堆栈的存取

// 创建数据结构
typedef int ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    int MaxSize;
    ElementType *Data;
    Position Top1;
    Position Top2;
};
typedef PtrToSNode Stack;

// 初始化堆栈
Stack createStack()
{
    Stack stack = (Stack)malloc(sizeof(struct SNode));
    int MaxSize = 10;
    stack->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    stack->Top1 = -1;
    stack->Top2 = MaxSize;
    stack->MaxSize = MaxSize;
    return stack;
}

// 入栈
bool Push(Stack S, ElementType X, int Tag)
{
    if ((S->Top2 - 1) == S->Top1)
    {
        printf("Stack is full\n");
        return false;
    }
    else
    {
        if (Tag == 1)
        {
            S->Data[++(S->Top1)] = X;
        }
        else
        {
            S->Data[--(S->Top2)] = X;
        }
        return true;
    }
}

// 出栈
#define ERROR -1;
ElementType Pop(Stack S, int Tag)
{
    if (Tag == 1)
    {
        if (S->Top1 == -1)
        {
            printf("Stack 1 is empty");
            return ERROR;
        }
        else
        {
            return S->Data[(S->Top1)--];
        }
    }
    if (Tag == 2)
    {
        if (S->Top2 == S->MaxSize)
        {
            printf("Stack 1 is empty");
            return ERROR;
        }
        else
        {
            return S->Data[(S->Top2)++];
        }
    }
}

void PrintStack(Stack S)
{
    printf("Stack 1:\n");
    for (int i = 0; i <= S->Top1; i++)
    {
        printf("%d ", S->Data[i]);
    }
    printf("\n");
    printf("Stack 2:\n");
    for (int i = (S->MaxSize - 1); i >= S->Top2; i--)
    {
        printf("%d ", S->Data[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack = createStack();
    bool ret;
    for (int i = 0; i < 3; i++)
    {
        ret = Push(stack, 2 * i + 1, 1);
    }
    for (int j = 0; j < 3; j++)
    {
        ret = Push(stack, -2 * j - 1, 2);
    }
    PrintStack(stack);

    int popElement = Pop(stack, 1);
    printf("Stack 1 popped\n");
    PrintStack(stack);

    popElement = Pop(stack, 2);
    printf("Stack 2 popped\n");
    PrintStack(stack);

    return 0;
}