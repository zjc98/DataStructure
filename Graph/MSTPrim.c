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
// primʵ����С������������MST��ϡ��ͼ����LGraph��ʾ
int Prim(MGraph Graph, LGraph MST)
{
    // ����С����������ΪMST����������СȨ�غ�
    WeightType dist[MAXSIZE], TotalWeight;
    Vertex parent[MAXSIZE], V, W;
    int VCount;
    Edge E;

    // ��ʼ����Ĭ����ʼ��������0
    for(V=0;V<Graph->Nv;V++)
    {
        // Ĭ����ʼ����0����0���ڽӵ���븳��dist�У�0�ķ��ڽӵ�Ĭ��ΪINFINITY
        dist[V] = Graph->G[0][V];
        parent[V] = 0;  // ���Ҷ������е�ĸ��ڵ㶼��0
    }

    TotalWeight = 0;
    VCount = 0;

    // �����������ж��㵫û�бߵ�ͼ��ϡ��ͼ���ڽӱ�
    MST = CreateGraph(Graph->Nv);
    E = (Edge)malloc(sizeof(struct ENode));

    // ����ʼ����¼��MST
    dist[0] = 0;
    parent[0] = -1;  // ��������
    VCount++;

    while(1)
    {
        V = FindMinDist(Graph, dist);   // �ҵ�δ����¼������dist��С��
        if (V == ERROR)
        {
            /* ��V�����ڣ����㷨���� */
            break;
        }

        // ��V��¼��MST
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
