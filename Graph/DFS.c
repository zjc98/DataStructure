#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int Vertex;
typedef struct LGNode* PtrToLGNode;
typedef int WeightType;
typedef char DataType;
struct LGNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToLGNode LGraph;

typedef struct AdjNode* PtrToAdjNode;
struct AdjNode
{
    Vertex AdjV;
    WeightType Weight;
    struct AdjNode* Next;
};

struct VNode
{
    DataType Data;
    PtrToAdjNode FirstEdge;
};
typedef struct VNode AdjList[];

void Visit(Vertex V)
{
    printf("It is visiting %d", V);
}

bool Visited[100] = {0};
void DFS(LGraph Graph, Vertex V, void(*Visit)(Vertex))
{
    PtrToAdjNode W;
    
    Visit(V);
    Visited[V] = true;

    for(W=Graph->G[V].FirstEdge;W;W=W->Next)
    {
        if(!Visited[W->AdjV])
            DFS(Graph, W->AdjV, Visit);
    }
}