#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

// �ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

// �ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;            // �ڽӵ��±�
    WeightType Weight;      // ��Ȩ��
    PtrToAdjVNode Next;     // ָ����һ���ڽӵ��ָ��
};

// �����ͷ�ڵ�Ķ���
typedef struct VNode *PtrToVNode;
struct VNode
{
    PtrToAdjVNode FirstEdge;    // �߱�ͷָ��
    DataType Data;              //  �涥������
};
typedef struct VNode AdjList[MaxVertexNum];  // AdjList���ڽӱ�����

// ͼ�ڵ�Ķ���
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;         // ͼ�Ķ�����
    int Ne;         // ͼ�ı���
    AdjList G;      // ͼ���ڽӱ�
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    // ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
    LGraph Graph;
    Vertex V;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    
    // ��ʼ���ڽӱ��ͷָ��
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

    // ��V2����V1�ı�ͷ
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;       // �Ͽ�ԭ����һ�����㣬�ӵ��¶���ĺ���

    // ����ͼ��Ҫ�ٽ���һ���ڵ㣬������V2
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

    // ���붥����
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);

    // �������
    scanf("%d", &(Graph->Ne));
    if((Graph->Ne)!=0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++)
        {
            // ����ߵ����ݣ��ֱ�����㡢�յ㡢Ȩ��
            scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
            InsertEdge(Graph, E);
        }
    }

    // ���붥�������
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