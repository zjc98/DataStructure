#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 堆栈操作：
// Stack CreateStack(int MaxSize): 生成空堆栈，最大长度为MAXSIZE
// bool isFull(Stack S): 判断堆栈S是否已满，若堆栈已满，返回true，否则返回false
// bool Push(Stack S, ElementType X): 将元素X压入栈中，若堆栈已满，返回false，压入成功返回true
// bool isEmpty(Stack S): 判断堆栈S是否已空，若已空，返回true，否则返回false
// ElementType Pop(Stack S): 删除并返回栈顶元素，若堆栈为空，返回错误信息，否则将栈顶数据元素从堆栈中删除并返回

// 定义堆栈数据类型
typedef int ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data; // 存储元素的数组
    Position top;      // 栈顶位置
    int MaxSize;       // 堆栈最大容量
};
typedef PtrToSNode Stack;

// 初始化堆栈
Stack CreateStack()
{
    int Size = 10;
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType)malloc(Size * sizeof(ElementType));
    S->top = -1;
    S->MaxSize = Size;
    return S;
}

// 入栈操作
bool isFull(Stack S)
{
    if (S->top == (S->MaxSize - 1))
        return true;
    else
        return false;
}

bool push(Stack S, ElementType X)
{
    if (isFull(S))
    {
        printf("Stack is full, push failed.\n");
        return false;
    }
    else
    {
        S->Data[++(S->top)] = X;
        return true;
    }
}

// 出栈操作
bool isEmpty(Stack S)
{
    if (S->top == S->MaxSize - 1)
        return true;
    else
        return false;
}

#define ERROR -1
ElementType Pop(Stack S)
{
    if (isEmpty(S))
    {
        printf("Stack is empty, pop failed.\n");
        return ERROR;
    }
    else
    {
        return S->Data[(S->top)--];
    }
}

void printStack(Stack S)
{
    printf("bottom to top: ");
    for (int i = 0; i <= S->top; i++)
    {
        printf("%d  ", S->Data[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack = CreateStack();
    bool ret;
    for (int i = 1; i < 6; i++)
    {
        ret = push(stack, i * 2 + 1);
    }
    printStack(stack);
    printf("stack after pop:\n");
    ret = Pop(stack);
    printStack(stack);
    return 0;
}