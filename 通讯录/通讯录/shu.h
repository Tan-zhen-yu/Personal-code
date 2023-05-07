#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define Maxsize 50
#define MaxSons 4

typedef char ElemType;

typedef struct
{
	ElemType data;
	int parent;
}PTree[Maxsize];

typedef char SqBTree[Maxsize];


typedef struct node2
{
	ElemType data;
	struct node2* sons[MaxSons];
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

typedef struct
{
	BTNode* data[Maxsize];
	int front, rear;
}SqQueue;

int TreeHeight1(TSonNode* t);

int TreeHeight2(TSBNode* t);

void CreateBTree(BTNode*& b, char* str);

void DestroyBTree(BTNode*& b);

BTNode* FindNode(BTNode* b, ElemType x);

BTNode* LchildNode(BTNode* p);

BTNode* RchildNode(BTNode* p);

int BTHeight(BTNode* b);

void DispBTree(BTNode* b);

void PreOrder1(BTNode* b);

void PreOrder2(BTNode* b);

void PreOrder3(BTNode* b);

int Nodes(BTNode* b);

void DispLeaf(BTNode* b);

void DispLeaf1(BTNode* b);

int Level(BTNode* b, ElemType x, int h);