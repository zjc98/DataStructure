#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef struct GNode* LGraph;

typedef int Vertex;
typedef int WeightType;
struct AdjNode
{
    Vertex V;
    struct AdjNode* Next;
    WeightType Weight;
};

struct VNode
{
    struct AdjNode* FirstEdge;
};
typedef struct VNode AdjList[];

int Kruskal(LGraph Graph, LGraph MST)
{
//     MST = 不含边只含有Graph->Nv的最小生成树;
//     while(MST->Ne < Graph->Nv-1 && Graph的E集合非空)
//     {
//          从E中选择最小代价边(V,W)  引入最小堆完成
//          从集合中删除边(V,W)
//          if((V,W)的选取在MST中不构成回路)  用并查集Find实现
//              将(V,W)的边纳入到MST中       用并查集的Union完成
//          else
//              彻底丢弃边(V,W);
//     }
//     if(MST->Ne < Graph->Nv-1)
//          return ERROR
//     else
//          return 最小权重和
}