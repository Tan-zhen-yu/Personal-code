#define _CRT_SECURE_NO_WARNINGS

#include"biao.h"

void fun1(GLNode* g)
{
	GLNode* g1 = g->val.sublist;
	while (g1 != NULL)
	{
		if (g1->tag == 1)
			fun1(g1);
		else
			printf("%d",g1->val.data);
		g1 = g1->link;

	}
}

void fun2(GLNode* g)
{
	if (g != NULL)
	{
		if (g->tag == 1)
			fun2(g->val.sublist);
		else
			printf("%d", g->val.data);
		fun2(g->link);
	}
}


int GLLength(GLNode* g)
{
	int n = 0;
	GLNode* g1;
	g1 = g->val.sublist;
	while (g1 != NULL)
	{
		n++;
		g1 = g1->link;
	}
	return n;
}


int GLDpenth(GLNode* g)
{
	GLNode* g1;
	int maxd = 0, dep;
	if (g->tag == 0)
		return 0;
	g1 = g->val.sublist;
	if (g1 == NULL)
		return 1;
	while (g1 != NULL)
	{
		if (g1->tag == 1)
		{
			dep = GLDpenth(g1);
			if (dep > maxd)
				maxd = dep;
		}
		g1 = g1->link;
	}
	return maxd + 1;
}

void DispGL(GLNode* g)
{
	if (g != NULL)
	{
		if (g->tag == 0)
			printf("%d", g->val.data);
		else
		{
			printf("(");
			if (g->val.sublist == NULL)
				printf("#");
			else
				DispGL(g->val.sublist);
			printf(")");
		}
		if (g->link != NULL)
			printf(",");
		DispGL(g->link);
	}
}

int Count1(GLNode* g)
{
	int n = 0;
	GLNode* g1 = g->val.sublist;
	while (g1 != NULL)
	{
		if (g1->tag == 0)
			n++;
		else
			n += Count1(g1);
		g1 = g1->link;
	}
	return n;
}

int Count2(GLNode* g)
{
	int n = 0;
	if (g != NULL)
	{
		if (g->tag == 0)
			n++;
		else
			n += Count2(g->val.sublist);
		n += Count2(g->link);
	}
	return n;
}