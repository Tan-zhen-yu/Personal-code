#define _CRT_SECURE_NO_WARNINGS

#include"arc.h"

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV],int n,int e)
{
	int i, j;
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < G->n; i++)
	{
		G->adjlist[i].firstarc = NULL;
	}
	for (i = 0; i < G->n; i++)
	{
		for (j = G->n - 1; j >= 0; j--)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[j].firstarc;
				G->adjlist[i].firstarc = p;
			}

		}
	}
	G->n = n; G->e = e;

}

void DispAdj(AdjGraph* G)
{
	int i; ArcNode* p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		{
			printf("%3d:",i);
		}
		while (p != NULL)
		{
			printf("%3d[%3d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("\n");

	}

}

void Destroy(AdjGraph*& G)
{
	ArcNode* pre, * p;
	for (int i = 0; i < G->n; i++)
	{
		pre = G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}