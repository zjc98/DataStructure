#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000
typedef int ElementType;
typedef int SetName;               // �ø��ڵ���±���Ϊ��������
typedef ElementType SetType[MAXN]; // ���輯��Ԫ�ش��±�0��ʼ

// ���ϲ���, ����ĳ��Ԫ�����ڵļ���
SetName Find(SetType S, ElementType X)
{
    for (; S[X] >= 0; X = S[X])
        ;
    return X;
}

// ���ϵĲ�����
void Union(SetType S, SetName Root1, SetName Root2)
{
    if(S[Root1]<S[Root2])   // ����1��Ԫ�رȼ���2��
    {
        S[Root1] += S[Root2];   // ��������1��Ԫ����
        S[Root2] = Root1;
    }
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}

// ·��ѹ������Ҫ���ҵĽڵ��ɸ��ڵ�ĺ���
SetName Find2(SetType S, ElementType X)
{
    if(S[X]<0) return X;
    else return S[X] = Find2(S, S[X]);
}