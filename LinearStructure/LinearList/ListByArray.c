#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���Ա�List���Ķ�����ʵ��
// ���Ա�Ļ���������
// List MakeEmpty()����ʼ��һ���ձ�
// ElementType FindKth(List L, int i): ����ָ����λ��i������L�е���ӦԪ��
// Position Find(List L, ElementType X): ��֪X������L����X��ͬ�ĵ�һ��Ԫ�ص��������������򷵻ش�����Ϣ
// bool Insert(List L, ElementType X, int i): ��L��ָ��λ��iǰ����һ����Ԫ��X���ɹ�����true��ʧ�ܷ���false
// bool Delete(List L, int i): ��L��ɾ��ָ��λ��i��Ԫ�أ��ɹ�����true��ʧ�ܷ���false
// int Length(List): �������Ա���L�ĳ���

// ��˳��洢��������ʵ�����Ա�

// �������Ա�
#define MAXSIZE 100 // ��������
typedef int Position;
typedef int ElementType;
typedef struct LNode *PtrToLNode;

struct LNode
{
    Position Last; // ָ����������һ���������ձ�Ϊ-1
    ElementType Data[MAXSIZE];
};
typedef PtrToLNode List;

// ��ʼ�����Ա�
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// ��������Ϊi��Ԫ��
ElementType FindKth(List L, Position i)
{
    return L->Data[i-1];
}

// ����Ԫ��
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

// ����Ԫ��
bool Insert(List L, ElementType X, int i)
{
    // ��i��Ԫ�ص�����Ϊi-1
    // �жϱ��Ƿ���
    if (L->Last == MAXSIZE - 1)
    {
        printf("List is full");
        return false;
    }

    // �жϲ���Ϸ���
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

// ɾ��ָ��λ���Ԫ��
bool Delete(List L, int i)
{
    // λ��i��Ԫ�ص��±�Ϊi-1
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

// �������Ա�ĳ���
int Length(List L)
{
    return L->Last+1;
}

// ��ӡ���Ա�
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
    // ����FindKth����ӡ�ڶ�����
    ElementType secend = FindKth(list, 2);
    printf("The second number is %d\n", secend);
    // ����Find��Ѱ��7
    Position pos = Find(list, 7);
    printf("The index of 7 is %d\n", pos);
    // ����Insert���ڵ�4��λ�ò���99
    bool ret2 = Insert(list, 99, 4);
    printf("Insert 99 in the fourth place:\n");
    PrintList(list);
    // ����Delete��ɾ����������
    printf("After delete the third element:\n");
    bool ret3 = Delete(list,3);
    PrintList(list);
}