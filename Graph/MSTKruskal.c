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
//     MST = ������ֻ����Graph->Nv����С������;
//     while(MST->Ne < Graph->Nv-1 && Graph��E���Ϸǿ�)
//     {
//          ��E��ѡ����С���۱�(V,W)  ������С�����
//          �Ӽ�����ɾ����(V,W)
//          if((V,W)��ѡȡ��MST�в����ɻ�·)  �ò��鼯Findʵ��
//              ��(V,W)�ı����뵽MST��       �ò��鼯��Union���
//          else
//              ���׶�����(V,W);
//     }
//     if(MST->Ne < Graph->Nv-1)
//          return ERROR
//     else
//          return ��СȨ�غ�
}