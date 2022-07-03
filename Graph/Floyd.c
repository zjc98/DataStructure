#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int WeightType;
typedef int Vertex;
#define MAXSIZE 100
struct MGNode
{
    int Nv;
    int Ne;
    WeightType G[MAXSIZE][MAXSIZE];
};
typedef struct MGNode* MGraph;

bool Floyd(MGraph Graph, WeightType D[][MAXSIZE], Vertex path[][MAXSIZE])
{
    Vertex i,j,k;

    for(i=0; i<Graph->Nv; i++)
        for(j=0; j<Graph->Nv; j++)
        {
            D[i][j] = Graph->G[i][j];
            path[i][j] = -1;
        }
    
    for(k=0; k<Graph->Nv; k++)
        for(i=0; i<Graph->Nv; i++)
            for(j=0; j<Graph->Nv;j++)
                if(D[i][j] > D[i][k]+D[k][j])
                    {
                        D[i][j] = D[i][k]+D[k][j];
                        if(i==j && D[i][j]<0)      // 若发现负值圈
                            return false;
                        path[i][j] = k;
                    }
    return true;
}