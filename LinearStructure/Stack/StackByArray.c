#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��ջ������
// Stack CreateStack(int MaxSize): ���ɿն�ջ����󳤶�ΪMAXSIZE
// bool isFull(Stack S): �ж϶�ջS�Ƿ�����������ջ����������true�����򷵻�false
// bool Push(Stack S, ElementType X): ��Ԫ��Xѹ��ջ�У�����ջ����������false��ѹ��ɹ�����true
// bool isEmpty(Stack S): �ж϶�ջS�Ƿ��ѿգ����ѿգ�����true�����򷵻�false
// ElementType Pop(Stack S): ɾ��������ջ��Ԫ�أ�����ջΪ�գ����ش�����Ϣ������ջ������Ԫ�شӶ�ջ��ɾ��������

// �����ջ��������
typedef int ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data; // �洢Ԫ�ص�����
    Position top;      // ջ��λ��
    int MaxSize;       // ��ջ�������
};
typedef PtrToSNode Stack;

// ��ʼ����ջ
Stack CreateStack()
{
    int Size = 10;
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType)malloc(Size * sizeof(ElementType));
    S->top = -1;
    S->MaxSize = Size;
    return S;
}

// ��ջ����
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

// ��ջ����
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