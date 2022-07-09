#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int ElementType;

void Swap(ElementType* a, ElementType* b)
{
    ElementType t = *a; *a=*b; *b = t;
}

void BubbleSort(ElementType A[], int N)
{
    int P, i;
    bool flag;

    for(P=N-1;P>0;P--)
    {
        flag = 0;
        for(i=0;i<P;i++)
        {
            if(A[i]>A[i+1])
                Swap(&A[i], &A[i+1]);
                flag = 1;
        }
    }
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    BubbleSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}