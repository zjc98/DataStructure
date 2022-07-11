#include<stdlib.h>
#include<stdio.h>

#define MaxDigit 4
#define Radix 10
typedef int ElementType;

// ͰԪ�ؽڵ�
typedef struct Node *PtrToNode;
struct Node{
    int Key;
    PtrToNode Next;
};

// Ͱͷ�ڵ�
struct HeadNode{
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D)
{
    int d, i;
    for(i=1;i<=D;i++){
        d = X % Radix;
        X /= Radix;
    }
    return d;
}

void LSDRadixSort(ElementType A[], int N)
{
    int D, Di, i;
    Bucket B;
    PtrToNode tmp, p, List=NULL;

    // ��ʼ��Ͱ
    for(i=0;i<Radix;i++)
        B[i].head = B[i].tail = NULL;
    // ��ԭʼ������������ʼ����List
    for(i=0; i<N; i++)
    {
        tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->Key = A[i];
        tmp->Next = List;
        List = tmp;
    }

    // ���濪ʼ����
    for(D=1;D<=MaxDigit;D++)
    {
        // �����Ƿ���Ĺ���
        p = List;
        while (p)
        {
            Di = GetDigit(p->Key, D);
            tmp = p; p = p->Next;
            tmp->Next = NULL;
            if(B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else
            {
                B[Di].tail->Next = tmp;
                B[Di].tail = tmp;
            }     
        }
        
        // �������ռ��Ĺ���
        List = NULL;
        for(Di=Radix-1;Di>=0;Di--)
        {
            if(B[Di].head)
            {
                B[Di].tail->Next = List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL;
            }
        }
    }

    // ��List����A[]���ͷſռ�
    for(i=0;i<N;i++)
    {
        tmp = List;
        List = List->Next;
        A[i] = tmp->Key;
        free(tmp);
    }   
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    LSDRadixSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}
