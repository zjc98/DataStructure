#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// ������ջ
typedef double ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

// ��ʼ����ջ
Stack createStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// �ж϶�ջ�Ƿ�Ϊ��
bool isEmpty(Stack S)
{
    // if (S->Next!=NULL) return false;
    // else return true;
    return (S->Next == NULL);
}

// Push����
bool Push(Stack S, ElementType X)
{
    Stack newNode = (Stack)malloc(sizeof(struct SNode));
    newNode->Data = X;
    newNode->Next = S->Next;
    S->Next = newNode;
    return true;
}

// Pop����
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


// ���ö�ջʵ�ֱ��ʽ��ֵ
// �����Ҷ����׺���ʽ�ĸ���
// ��׺���ʽ����֮���ÿո����

#define MAXOP 100    // ���������п��ܵ���󳤶�
#define INFINITY 1e9 // ����������
// �����Դ˶�Ӧ����������������ַ�����β
typedef enum
{
    num,
    opr,
    end
} Type;

Type GetOp(char *Expr, int *start, char *str)
{
    // ��*start��ʼ������һ�����󣬲��������ַ�����
    int i = 0;

    // �������ʽ�ո�
    while ((str[0] = Expr[(*start)++]) == ' ')
        ;
    // ��ʱstr[0]��Ϊ�ո�*startָ��ո��ڶ���Ԫ�ص�λ��

    while (str[i] != ' ' && str[i] != '\0')
    {
        str[++i] = Expr[(*start)++];
    }

    // ��������β����start-1��ָ����ʽ�ַ������һλ
    if (str[i] == '\0')
        *start--;

    // ��ʾ����Ϊ����
    else if (isdigit(str[0]) || isdigit(str[1]))
        return num;

    // ��ʾ����Ϊ�����
    else
        return opr;
}

ElementType PosifixExp(char* Expr)
{
    Stack S;
    Type T;
    ElementType Op1, Op2;
    char str[MAXOP];
    int start = 0;

    S = createStack();
    Op1 = Op2 = 0;
    while((T = GetOp(Expr, start, str))!=end)
    {
        if(T==num) Push(S, atof(str));
        else
        {
            if(!isEmpty(S)) Push(S, atof(str));
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int b;
    int i = 0;
    while ((b = a[i++]) == 1)
        ;
    printf("b: %d ", b);
    printf("i: %d ", i);
}