#include<stdlib.h>
#include<stdio.h>

// 堆排序，时间复杂度：O(NlogN), 不稳定
typedef int ElementType;
void swap(ElementType *a, ElementType *b)
{
    ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N)
{
    // 将N个元素的数组A中以A[p]为根的子堆调整为最大堆
    // 根节点从0开始
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
    A[parent] = X;  // 此时的parent相当于child
}

void HeapSort(ElementType A[], int N)
{
    int i;
    // 建立最大堆
    for(i=(N-1)/2;i>=0;i--)
        PercDown(A, i, N);

    // 删除最大堆顶
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