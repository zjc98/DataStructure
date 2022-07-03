#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int WeightType;
#define MAXSIZE 100
struct MGraphNode
{
    int Nv;
    int Ne;
    WeightType G[100][100];
};
typedef struct MGraphNode* MGraph;

typedef int Vertex;
#define INFINITY 65535
#define ERROR -1
Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{
    Vertex MinV, V;
    int MinDist;
    MinDist = INFINITY;

    for(V=0;V<Graph->Nv;V++)
    {
        if(collected[V]==false && dist[V]<MinDist)
        {
            MinDist = dist[V];
            MinV = V;
        }
    }
    if(MinDist < INFINITY)
        return MinV;
    else return ERROR;
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
    int collected[MAXSIZE];
    Vertex V, W;

    // ��ʼ��dist���ڽӾ����в����ڵı���INFINITY��ʾ
    for(V=0;V<Graph->Nv;V++)
    {
        dist[V] = Graph->G[S][V];
        if(dist[V] < INFINITY)
            path[V] = S;
        else
            path[V] = -1;
        collected[V] = false;
    }

    // �Ƚ�������뼯��
    dist[S] = 0;
    collected[S] = true;

    while(1)
    {
        // V��δ���붥���е���Сֵ
        V = FindMinDist(Graph, dist, collected);
        if(V==ERROR) break;  // ����������Сֵ�ˣ����㷨����
        collected[V] = true;
        for(W=0; W<Graph->Nv; W++)
        {
            if(collected[W]==false && Graph->G[V][W]<INFINITY)
            {
                if(Graph->G[V][W]<0)  // ���и���
                    return false;
                // ������VʹW��С�������dist[W]��path[W]
                if(dist[V]+Graph->G[V][W] < dist[W])
                {
                    dist[W] = dist[V] + Graph->G[V][W];
                    path[W] = V;
                }
            }
        }
    }
    return true;
}