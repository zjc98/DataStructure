#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

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
#define ZERO 1.0E-10  // ����0
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
    while ((str[0] = Expr[(*start)++]) == ' ');
    // ��ʱstr[0]��Ϊ�ո�*startָ��ո��ڶ���Ԫ�ص�λ��

    while (str[i] != ' ' && str[i] != '\0')
    {
        str[++i] = Expr[(*start)++];
    }

    // ��������β����start-1��ָ����ʽ�ַ������һλ
    if (str[i] == '\0')
        *start--;

    str[i] = '\0';   // ����һ������Ļ�ȡ
    if(i==0) return end; 

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
    while((T = GetOp(Expr, &start, str))!=end)
    {
        if(T==num) Push(S, atof(str));
        else
        {
            if(!isEmpty(S)) Op2 = Pop(S);
            else Op1 = INFINITY;
            if(!isEmpty(S)) Op1 = Pop(S);
            else Op2 = INFINITY;
            switch(str[0])
            {
                case '+': Push(S, Op1+Op2);break;
                case '*': Push(S, Op1*Op2);break;
                case '-': Push(S, Op1-Op2);break;
                case '/': 
                    if(fabs(Op2) > ZERO) Push(S, Op1/Op2);
                    else{
                        printf("Illegal Calculate\n");
                        Op2 = INFINITY;
                    }
                    break;
                default:
                    printf("Unkonw Operator: %s", str);
                    Op2 = INFINITY;
                    break;                  
            }
            if(Op2>=INFINITY) break;
        }
    }
    if(Op2<INFINITY)
    {
        if(!isEmpty(S)) Op2 = Pop(S);
        else Op2 = INFINITY;
    }
    free(S);
    return Op2;
}

int main()
{
    char Expr[MAXOP];
    ElementType f;

    gets(Expr);    // 1.2 1.3 + 2 4.2 * -
    f = PosifixExp(Expr);
    if(f<INFINITY)
    printf("%.4f\n", f);
    else
    printf("Wrong Expression.\n");
    system("pause");
    return 0;
}