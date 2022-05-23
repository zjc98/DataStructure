#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 用链式存储实现线性表

// 定义线性表
typedef struct LNode *PtrToLNode;
typedef int ElementType;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
typedef PtrToLNode Position;

// 求表长
int Length(List L)
{
    int cnt = 0; // 初始化计数器
    Position p = L;
    while (p != NULL)
    {
        p = p->Next;
        cnt++;
    }
    return cnt;
}

// 按序号查找, 返回第K个值
#define ERROR -1
ElementType FindKth(List L, int K)
{
    Position p = L;
    int cnt = 1;
    while (p && cnt < K)
    {
        p = p->Next;
        cnt++;
    }
    if (p && cnt == K)
        return p->Data;
    else
        return ERROR;
}

// 查找表中是否含有元素X，若有返回表的位置，若无，返回-1
// #define ERROR NULL
Position Find(List L, ElementType X)
{
    List p = L;
    while (p->Data != X && p)
    {
        p = p->Next;
    }
    if (p == NULL)
        return NULL;
    else
        return p;
}

// 在第i个节点插入数据X
List Insert(List L, ElementType X, int i)
{
    List tmp = (List)malloc(sizeof(struct LNode));
    tmp->Data = X;
    if (i == 1)
    {
        tmp->Next = L;
        return tmp;
    }
    else
    {
        List p = L;
        int cnt = 1;

        while (p && cnt < i - 1)
        {
            p = p->Next;
            cnt++;
        }
        if (p == NULL || cnt != i - 1)
        {
            printf("Insert position is illegal\n");
            return NULL;
        }
        else
        {
            tmp->Next = p->Next;
            p->Next = tmp;
            return L;
        }
    }
}

// Delete，删除第i个节点
bool Delete(List L, int i)
{
    List p = L;
    int cnt = 1;
    while (p && cnt < i - 1)
    {
        p = p->Next;
        cnt++;
    }
    if (p == NULL || (cnt != i - 1) || (p->Next == NULL))
    {
        printf("Delete position is illegel\n");
        return false;
    }
    else
    {
        List tmp = p->Next;
        p->Next = tmp->Next;
        free(tmp);
        return true;
    }
}

List initList()
{
    // 生成线性表
    List L = (List)malloc(sizeof(struct LNode));
    List p = L;
    int i;
    for (i = 0; i < 5; i++)
    {
        List tmp = (List)malloc(sizeof(struct LNode));
        tmp->Next = NULL;

        p->Data = 2 * i + 1;
        p->Next = tmp;
        p = p->Next;
    }
    p->Data = 2 * i + 1;
    return L;
}

void PrintList(List L)
{
    List p = L;
    while (p != NULL)
    {
        printf("%d  ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

int main()
{
    // 生成一个线性表
    List L = initList();
    printf("List: \n");
    PrintList(L);

    // 测试Length
    printf("The length is the List is: %d\n", Length(L));

    // 测试FindKth
    printf("Return the second data: \n");
    ElementType sec = FindKth(L, 2);
    printf("The second data is %d\n", sec);

    // 测试Find
    Position pos = Find(L, 7);
    printf("The address of 7 is at %d, and the data is %d\n", pos, pos->Data);

    // 测试Insert
    L = Insert(L, 10, 3);
    printf("Insert 10 in the third node:\n");
    PrintList(L);

    // 测试Delete
    bool ret = Delete(L, 3);
    printf("List after Delete the third node:\n");
    PrintList(L);

    return 0;
}