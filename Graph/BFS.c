#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int WeightType;
typedef int Vertex;
typedef char DataType;
#define MAXSIZE 100
#define INFINITY 65535
struct MGNode
{
    int Nv;
    int Ne;
    WeightType G[MAXSIZE][MAXSIZE];
    DataType Data[MAXSIZE];
};
typedef struct MGNode* MGraph;

struct QNode;
typedef struct QNode* Queue;
Queue CreateQueue(int MaxSize);
bool AddQ(Queue Q, Vertex V);
bool isEmpty(Queue Q);
Vertex DeleteQ(Queue Q);

bool Visited[100] = {0};
void Visit(Vertex V)
{
    printf("It is visiting %d", V);
}

bool isEdge(MGraph Graph, Vertex V, Vertex W)
{
    return Graph->G[V][W] < INFINITY ? true:false;
}

void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
    Vertex W, V;
    Queue Q;

    Q = CreateQueue(MAXSIZE);   
    Visit(S);
    Visited[S] = true;
    AddQ(Q, S);

    while(!isEmpty(Q))
    {
        V = DeleteQ(Q);
        for(W=0;W<Graph->Nv;W++)
        {
            if(!Visited[W] && isEdge(Graph, V, W))
            {
                Visit(W);
                Visited[W] = true;
                AddQ(Q, W);
            }
        }
    }
}