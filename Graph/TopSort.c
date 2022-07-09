#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 100;

// 对DAG(Directed Acyclic Graph)进行拓扑排序

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

    // 初始化入度
    for(V=0;V<Graph->Nv;V++)
    {
        Indegree[V] = 0;
    }

    // 遍历图，得到入度
    for(V=0;V<Graph->Nv;V++)
        for(W=Graph->G[V].FirstEdge; W ;W=W->Next)
            Indegree[W->adjV]++;

    // 将所有入度为0的顶点入列
    for(V=0;V<Graph->Nv;V++)
        if(Indegree[V] == 0)
            AddQ(Q, V);

    // 下面进入拓扑排序
    cnt=0;
    while(!isEmpty(Q))
    {
        // 弹出元素并被TopOrder记录
        V = DeleteQ(Q);
        TopOrder[cnt++] = V;

        // 更新入度
        for(W=Graph->G[V].FirstEdge;W;W=W->Next)
        {
            Indegree[W->adjV]--;
            // 若更新后的入度等于0，压入队列
            if(Indegree[W->adjV]==0)
                AddQ(Q, W->adjV);
        }
    }
    if(cnt==Graph->Nv) 
        return true;
    else
        return false;  // 说明图中有回路
}