#define _CRT_SECURE_NO_WARNINGS

#define	MAXV 50
#define INF 32000
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int InfoType;

typedef struct ANnode
{
	int adjvex;
	struct ANode* nextarc;
	int weight;
}ArcNode;

typedef struct Vnode
{
	InfoType info;
	struct ANode* firstarc;
}VNode;

typedef struct
{
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);

void DispAdj(AdjGraph* G);

void Destroy(AdjGraph*& G);