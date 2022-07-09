#include<stdlib.h>
#include<stdio.h>

// 希尔排序，时间复杂度与增量序列有关，在O(N^(1~2))左右，不稳定

typedef int ElementType;

void ShellSort(ElementType A[], int N)
{
    int Sedgewick[] = {926, 505, 209, 109, 41, 19, 5, 1, 0};
    int Si, D, P, i;
    ElementType Tmp;
    for(Si=0; Sedgewick[Si]>=N; Si++);

    for(D=Sedgewick[Si];D>0;D=Sedgewick[++Si])
    {
        for(P=D;P<N;P++)
        {
            Tmp = A[P];
            for(i=P;i>=D && A[i-D]>Tmp;i-=D)
                A[i] = A[i-D];
            A[i] = Tmp;
        }
    }
}

int main()
{
    ElementType a[] = {5,3,7,4,6,4};
    int len;
    len = sizeof(a) / sizeof(a[0]);
    printf("Length of a: %d\n", len);
    ShellSort(a, len);
    for(int i=0;i<len;i++)
        printf("%d ", a[i]);
    return 0;
}