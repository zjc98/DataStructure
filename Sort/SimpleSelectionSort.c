#include<stdlib.h>
#include<stdio.h>

// 简单选择排序
// 时间复杂度： O(N^2)

typedef int ElementType;
void swap(ElementType *a, ElementType *b)
{
    ElementType t = *a; *a = *b; *b = t;
}

void SimpleSelectionSort(ElementType A[], int N)
{
    // 从小到大排序
    int i,j,minA;
    for(i=0;i<N-1;i++)
    {
        minA = i;  // 记录最小值位置
        for(j=i+1;j<N;j++)
        {
            if(A[j]<A[minA])
                minA = j;
        }
        swap(&A[i], &A[minA]);
    }
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    SimpleSelectionSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}