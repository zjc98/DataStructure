#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define ERROR -1
#define INFINITY 65535

struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef struct GNode* LGraph;

#define MAXSIZE 100
struct VNode
{
    struct AdjVNode* FirstEdge;
};
typedef struct VNode AdjList[MAXSIZE];

typedef int WeightType;
typedef int Vertex; 
struct AdjVNode
{
    Vertex AdjV; 
    WeightType Weight;
    struct AdjVNode* Next;
};

struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef struct ENode* Edge;

struct MGNode
{
    int Nv;
    int Ne;
    WeightType G[MAXSIZE][MAXSIZE];
};
typedef struct MGNode* MGraph;
LGraph CreateGraph(int Nv);
bool Insert(LGraph G, Edge E);


Vertex FindMinDist(MGraph G, WeightType dist[]);
// prim实现最小生成树，由于MST是稀疏图，用LGraph表示
int Prim(MGraph Graph, LGraph MST)
{
    // 将最小生成树保存为MST，并返回最小权重和
    WeightType dist[MAXSIZE], TotalWeight;
    Vertex parent[MAXSIZE], V, W;
    int VCount;
    Edge E;

    // 初始化，默认起始点坐标是0
    for(V=0;V<Graph->Nv;V++)
    {
        // 默认起始点是0，将0的邻接点距离赋到dist中，0的非邻接点默认为INFINITY
        dist[V] = Graph->G[0][V];
        parent[V] = 0;  // 暂且定义所有点的父节点都是0
    }

    TotalWeight = 0;
    VCount = 0;

    // 创建包含所有顶点但没有边的图，稀疏图用邻接表
    MST = CreateGraph(Graph->Nv);
    E = (Edge)malloc(sizeof(struct ENode));

    // 将初始点收录进MST
    dist[0] = 0;
    parent[0] = -1;  // 设置树根
    VCount++;

    while(1)
    {
        V = FindMinDist(Graph, dist);   // 找到未被收录顶点中dist最小者
        if (V == ERROR)
        {
            /* 若V不存在，则算法结束 */
            break;
        }

        // 将V收录进MST
        E->V1 = parent[V];
        E->V2 = V;
        E->Weight = dist[V];
        Insert(MST, E);
        TotalWeight += dist[V];
        dist[V] = 0;
        VCount++;

        for(W=0;W<Graph->Nv;W++)
        {
            if(dist[W]!=0 && dist<INFINITY)
                if(Graph->G[V][W] < dist[W])
                {
                    parent[W] = V;
                    dist[W] = Graph->G[V][W];
                }
        }    
    }
    if(VCount < Graph->Nv) return ERROR;
    return TotalWeight;
}

Vertex FindMinDist(MGraph G, WeightType dist[])
{
    Vertex V, MinV;
    WeightType MinDist;

    MinDist = INFINITY;
    for(V=0;V<G->Nv;V++)
    {
        if(dist[V]!=0 && dist[V]<MinDist)
        {
            MinDist = dist[V];
            MinV = V;
        }
    }
    if(MinDist < INFINITY) return MinV;
    else return ERROR;
}
