#include<stdlib.h>
#include<stdio.h>

// 归并排序，时间复杂度：NlogN, 空间复杂度NlogN

typedef int ElementType;

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
    // 将A[L]~A[R-1] 与A[R]~A[RightEnd]归并成一个有序的序列
    int LeftEnd, Num, Tmp, i;
    LeftEnd = R-1;
    Num = RightEnd - L + 1;
    Tmp = L;
    while(L<=LeftEnd && R <=RightEnd)
    {
        if(A[L]<=A[R])   TmpA[Tmp++] = A[L++];
        else    TmpA[Tmp++] = A[R++];
    }

    while(L<=LeftEnd)   
        TmpA[Tmp++] = A[L++];
    while(R<=RightEnd)
        TmpA[Tmp++] = A[R++];

    for(i=0;i<Num;i++, RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
    int Center;
    if(L<RightEnd)
    {
        Center = (L + RightEnd) / 2;
        Msort(A, TmpA, L, Center);
        Msort(A, TmpA, Center+1, RightEnd);
        Merge(A, TmpA, L, Center+1, RightEnd);
    }
}

void MergeSort(ElementType A[], int N)
{
    ElementType* TmpA;
    TmpA = (ElementType *)malloc(N*sizeof(ElementType));
    if(TmpA!=NULL)
    {
        Msort(A, TmpA, 0, N-1);
        free(TmpA);
    }
    else
        printf("空间不足");
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    MergeSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}
