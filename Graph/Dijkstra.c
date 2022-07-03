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

    // 初始化dist，邻接矩阵中不存在的边用INFINITY表示
    for(V=0;V<Graph->Nv;V++)
    {
        dist[V] = Graph->G[S][V];
        if(dist[V] < INFINITY)
            path[V] = S;
        else
            path[V] = -1;
        collected[V] = false;
    }

    // 先将起点收入集合
    dist[S] = 0;
    collected[S] = true;

    while(1)
    {
        // V是未收入顶点中的最小值
        V = FindMinDist(Graph, dist, collected);
        if(V==ERROR) break;  // 若不存在最小值了，则算法结束
        collected[V] = true;
        for(W=0; W<Graph->Nv; W++)
        {
            if(collected[W]==false && Graph->G[V][W]<INFINITY)
            {
                if(Graph->G[V][W]<0)  // 若有负边
                    return false;
                // 若收入V使W变小，则更新dist[W]与path[W]
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