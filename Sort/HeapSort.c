#include<stdlib.h>
#include<stdio.h>

// ������ʱ�临�Ӷȣ�O(NlogN), ���ȶ�
typedef int ElementType;
void swap(ElementType *a, ElementType *b)
{
    ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N)
{
    // ��N��Ԫ�ص�����A����A[p]Ϊ�����Ӷѵ���Ϊ����
    // ���ڵ��0��ʼ
    int parent, child;
    ElementType X;
    X = A[p];
    for(parent=p;parent*2+1<N;parent=child)
    {
        child = parent * 2 + 1;
        if((child!=N-1) && (A[child+1] > A[child]))
            child ++;
        if(X >= A[child]) break;
        else
            A[parent] = A[child];
    }
    A[parent] = X;  // ��ʱ��parent�൱��child
}

void HeapSort(ElementType A[], int N)
{
    int i;
    // ��������
    for(i=(N-1)/2;i>=0;i--)
        PercDown(A, i, N);

    // ɾ�����Ѷ�
    for(i=N-1; i>0; i--)
    {
        swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    HeapSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}