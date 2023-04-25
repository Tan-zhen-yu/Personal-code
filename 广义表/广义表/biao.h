#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;
typedef struct lnode
{
	int tag;
	union
	{
		ElemType data;
		struct lnode* sublist;
	}val;
	struct lnode*link;
}GLNode;

void fun1(GLNode* g);

void fun2(GLNode* g);

int GLLength(GLNode* g);

int GLDpenth(GLNode* g);

void DispGL(GLNode* g);

int Count1(GLNode* g);

int Count2(GLNode* g);