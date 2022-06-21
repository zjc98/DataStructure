#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;     // �����±��ʾ����
typedef int WeightType; // �ߵ�Ȩֵ��������
typedef char DataType;  // ����洢����������

// ͼ�Ķ���
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;                                   // ������
    int Ne;                                   // ����
    WeightType G[MaxVertexNum][MaxVertexNum]; // �ڽӾ���
    DataType Data[MaxVertexNum];              // ��������
};
typedef PtrToGNode MGraph;

// �ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)
{ /*��ʼ��һ����VertexNum��������û�бߵ�ͼ*/
    MGraph Graph;
    Vertex V, W;

    // ��ʼ��ͼ
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    // ��ʼ���ڽӾ���
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

MGraph InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    // ��������ͼ����Ҫ�����[v2][v1]
    Graph->G[E->V2][E->V1] = E->Weight;
    return Graph;
}

MGraph BuildGraph()
{
    // ����һ��ͼ
    int Nv, i;
    MGraph Graph;
    Edge E;
    Vertex V;

    // ���붥����
    scanf("%d", &Nv);
    // ����ֻ�ж����ͼ
    Graph = CreateGraph(Nv);
    // �������
    scanf("%d", &(Graph->Ne));

    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            // ����ߵĲ���
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    // �����������ݣ���������
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