#include<stdlib.h>
#include<stdio.h>

typedef int ElementType;

void Swap(ElementType* a, ElementType* b)
{
    ElementType t = *a; *a=*b; *b = t;
}

void InsertionSort(ElementType A[], int N)
{
    int P, i;
    ElementType Tmp;
    for(P=1;P<N;P++)
    {
        Tmp = A[P];
        for(i=P;i>0 && A[i-1]>Tmp;i--)
            A[i] = A[i-1];
        A[i] = Tmp;
    }
}


ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if(A[Left] > A[Center])     Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])      Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])    Swap(&A[Center], &A[Right]);
    
    Swap(&A[Center], &A[Right-1]);
    return A[Right-1];
}

void QSort(ElementType A[], int Left, int Right)
{
    int Pivot, Cutoff, Low, High;
    Cutoff = 0; // 默认都用快速排序
    if(Right-Left > Cutoff)
    {
        Pivot = Median3(A, Left, Right);
        Low = Left;
        High = Right - 1;
        while(1)
        {
            while(A[++Low]<Pivot);
            while(A[--High]>Pivot);
            if(Low < High)
                Swap(&A[Low], &A[High]);
            else break;
        }
        Swap(&A[Low], &A[Right-1]);
        QSort(A, Left, Low-1);
        QSort(A, Low+1, Right);
    }
    else
        InsertionSort(A+Left, Right-Left+1);
}

void QuickSort(ElementType A[], int N)
{
    QSort(A, 0, N-1);
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    QuickSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    system("pause");
    return 0;
}
