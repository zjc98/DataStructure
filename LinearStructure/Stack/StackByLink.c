#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 用链表实现堆栈，插入与删除只能在栈顶实现，方便起见，在栈顶加一空节点

// 定义Stack结构体
typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

// 初始化堆栈
Stack createStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// 判断堆栈是否为空
bool isEmpty(Stack S)
{
    // if (S->Next!=NULL) return false;
    // else return true;
    return (S->Next == NULL);
}

// Push操作
bool Push(Stack S, ElementType X)
{
    Stack newNode = (Stack)malloc(sizeof(struct SNode));
    newNode->Data = X;
    newNode->Next = S->Next;
    S->Next = newNode;
    return true;
}

// Pop操作
ElementType Pop(Stack S)
{
    if (isEmpty(S))
    {
        printf("The stack is empty.\n");
        return 0;
    }
    else
    {
        Stack TmpNode = S->Next;
        S->Next = TmpNode->Next;
        ElementType x = TmpNode->Data;
        free(TmpNode);
        return x;
    }
}

void PrintStack(Stack S)
{
    Stack p = S->Next;
    while(p!=NULL)
    {
        printf("%d ",p->Data);
        p = p->Next;
    }
    printf("\n");
}

int main()
{
    Stack stack = createStack();
    bool ret;
    for(int i =1;i<6;i++)
    {
        ret = Push(stack, 2*i+1);
    }
    PrintStack(stack);
    ElementType data = Pop(stack);
    printf("The popped data: %d\n", data);
    printf("Stack after pop: \n");
    PrintStack(stack);

    return 0;
}