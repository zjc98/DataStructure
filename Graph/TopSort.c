#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 100;

// ��DAG(Directed Acyclic Graph)������������

typedef int Vertex;
typedef LGraph;
typedef PrtToAdjVNode;
typedef Queue;
Queue CreateQueue(int size);
bool AddQ(Queue Q, Vertex V);
bool isEmpty(Queue Q);
Vertex DeleteQ(Queue Q);
bool TopSort(LGraph Graph, Vertex TopOrder[])
{
    Vertex V;
    PrtToAdjVNode W;
    int Indegree[Graph->V], cnt;
    Queue Q = CreateQueue(Graph->Nv);

    // ��ʼ�����
    for(V=0;V<Graph->Nv;V++)
    {
        Indegree[V] = 0;
    }

    // ����ͼ���õ����
    for(V=0;V<Graph->Nv;V++)
        for(W=Graph->G[V].FirstEdge; W ;W=W->Next)
            Indegree[W->adjV]++;

    // ���������Ϊ0�Ķ�������
    for(V=0;V<Graph->Nv;V++)
        if(Indegree[V] == 0)
            AddQ(Q, V);

    // ���������������
    cnt=0;
    while(!isEmpty(Q))
    {
        // ����Ԫ�ز���TopOrder��¼
        V = DeleteQ(Q);
        TopOrder[cnt++] = V;

        // �������
        for(W=Graph->G[V].FirstEdge;W;W=W->Next)
        {
            Indegree[W->adjV]--;
            // �����º����ȵ���0��ѹ�����
            if(Indegree[W->adjV]==0)
                AddQ(Q, W->adjV);
        }
    }
    if(cnt==Graph->Nv) 
        return true;
    else
        return false;  // ˵��ͼ���л�·
}