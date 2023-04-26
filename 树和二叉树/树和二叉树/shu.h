#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#define Maxsize 50
#define MaxSons 4

typedef int ElemType;

typedef struct
{
	ElemType data;
	int parent;
}PTree[Maxsize];

typedef struct node
{
	ElemType data;
	struct node* sons[MaxSons];
}TSonNode;

typedef struct tnode
{
	ElemType data;
	struct tnode* hp;
	struct tnode* vp;

}TSBNode;

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;