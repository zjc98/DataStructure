#include<stdlib.h>
#include<stdio.h>
typedef int ElementType;

// 简单插入排序，平均时间复杂度：O(N^2)

void InsertionSort(ElementType A[], int N)
{
    int p, i;
    ElementType Tmp;
    for(p=1;p<N;p++)
    {
        Tmp = A[p];  // 取出未排序序列中的第一个元素
        for(i=p;i>0 && A[i-1]>Tmp;i--)
        {
            A[i] = A[i-1];
        }
        A[i] = Tmp;
    }
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    InsertionSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}