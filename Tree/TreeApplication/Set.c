#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000
typedef int ElementType;
typedef int SetName;               // 用根节点的下标作为集合名称
typedef ElementType SetType[MAXN]; // 假设集合元素从下标0开始

// 集合查找, 查找某个元素所在的集合
SetName Find(SetType S, ElementType X)
{
    for (; S[X] >= 0; X = S[X])
        ;
    return X;
}

// 集合的并运算
void Union(SetType S, SetName Root1, SetName Root2)
{
    if(S[Root1]<S[Root2])   // 集合1的元素比集合2多
    {
        S[Root1] += S[Root2];   // 调整集合1的元素数
        S[Root2] = Root1;
    }
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}

// 路径压缩，把要查找的节点变成根节点的孩子
SetName Find2(SetType S, ElementType X)
{
    if(S[X]<0) return X;
    else return S[X] = Find2(S, S[X]);
}