#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// 建立堆栈
typedef double ElementType;
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


// 利用堆栈实现表达式求值
// 从左到右读入后缀表达式的各项
// 后缀表达式对象之间用空格隔开

#define MAXOP 100    // 操作数序列可能的最大长度
#define INFINITY 1e9 // 代表正无穷
// 类型以此对应运算数、运算符、字符串结尾
typedef enum
{
    num,
    opr,
    end
} Type;

Type GetOp(char *Expr, int *start, char *str)
{
    // 从*start开始读入下一个对象，并保存在字符串中
    int i = 0;

    // 跳过表达式空格
    while ((str[0] = Expr[(*start)++]) == ' ')
        ;
    // 此时str[0]不为空格，*start指向空格后第二个元素的位置

    while (str[i] != ' ' && str[i] != '\0')
    {
        str[++i] = Expr[(*start)++];
    }

    // 若读到结尾，则start-1，指向表达式字符串最后一位
    if (str[i] == '\0')
        *start--;

    // 表示对象为数字
    else if (isdigit(str[0]) || isdigit(str[1]))
        return num;

    // 表示对象为运算符
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