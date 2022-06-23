#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

// 边的定义
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

// 邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;            // 邻接点下标
    WeightType Weight;      // 边权重
    PtrToAdjVNode Next;     // 指向下一个邻接点的指针
};

// 顶点表头节点的定义
typedef struct VNode *PtrToVNode;
struct VNode
{
    PtrToAdjVNode FirstEdge;    // 边表头指针
    DataType Data;              //  存顶点数据
};
typedef struct VNode AdjList[MaxVertexNum];  // AdjList是邻接表类型

// 图节点的定义
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;         // 图的顶点数
    int Ne;         // 图的边数
    AdjList G;      // 图的邻接表
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    // 初始化一个有VertexNum个顶点但没有边的图
    LGraph Graph;
    Vertex V;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    
    // 初始化邻接表的头指针
    for(V=0;V<VertexNum;V++)
    {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;

    // 将V2插入V1的表头
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;       // 断开原本第一个顶点，接到新顶点的后面

    // 无向图需要再建立一个节点，并插入V2
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    int Nv, i;
    Edge E;
    Vertex V;

    // 读入顶点数
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);

    // 读入边数
    scanf("%d", &(Graph->Ne));
    if((Graph->Ne)!=0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++)
        {
            // 读入边的数据，分别是起点、终点、权重
            scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
            InsertEdge(Graph, E);
        }
    }

    // 读入顶点的数据
    for(i=0;i<Nv;i++)
    {
        scanf("%c", &(Graph->G[V].Data));
    }

    return Graph;
}

int main()
{
    LGraph lg = BuildGraph();
    system("pause");
    return 0;
}