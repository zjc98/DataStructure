#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;     // 顶点下标表示顶点
typedef int WeightType; // 边的权值数据类型
typedef char DataType;  // 顶点存储的数据类型

// 图的定义
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                                   // 顶点数
    int Ne;                                   // 边数
    WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
    DataType Data[MaxVertexNum];              // 顶点数据
};
typedef PtrToGNode MGraph;

// 边的定义
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)
{ /*初始化一个有VertexNum数量顶点没有边的图*/
    MGraph Graph;
    Vertex V, W;

    // 初始化图
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    // 初始化邻接矩阵
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

MGraph InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    // 若是无向图，还要插入边[v2][v1]
    Graph->G[E->V2][E->V1] = E->Weight;
    return Graph;
}

MGraph BuildGraph()
{
    // 建立一个图
    int Nv, i;
    MGraph Graph;
    Edge E;
    Vertex V;

    // 读入顶点数
    scanf("%d", &Nv);
    // 建立只有顶点的图
    Graph = CreateGraph(Nv);
    // 读入边数
    scanf("%d", &(Graph->Ne));

    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            // 读入边的参数
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    // 若顶点有数据，读入数据
    for (V = 0; V < Graph->Nv; V++)
    {
        scanf("%c", &Graph->Data[V]);
    }
    return Graph;
}

int main()
{
    MGraph mg = BuildGraph();
    system("pause");
    return 0;
}