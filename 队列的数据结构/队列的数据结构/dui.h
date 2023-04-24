#pragma once

#define Maxsize 50

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct
{
	ElemType data[Maxsize];
	int front, rear;
}SqQueue;


typedef struct
{
	ElemType data[Maxsize];
	int front;
	int count;
}QuType;

typedef struct qnode
{
	ElemType data;
	struct qnode* next;
}DataNode;

typedef struct
{
	DataNode* front;
	DataNode* rear;
}LinkQuNode;

void InitQueue(SqQueue*& q);

void DestoryQueue(SqQueue*& q);

bool QueueEmpty(SqQueue* q);

bool EnQueue(SqQueue*& q, ElemType e);

bool DeQueue(SqQueue*& q, ElemType& e);

void InitQueue1(SqQueue*& q);

void DestoryQueue1(SqQueue*& q);

bool QueueEmpty1(SqQueue* q);

bool EnQueue1(SqQueue*& q, ElemType e);

bool DeQueue1(SqQueue*& q, ElemType& e);

int Count1(SqQueue* q);

void InitQueue2(QuType*& qu);

bool EnQueue2(QuType*& qu, ElemType x);

bool DeQueue2(QuType*& qu, ElemType& x);

bool QueueEmpty2(QuType* qu);

void InitQueue3(LinkQuNode* q);

void DestroyQueue3(LinkQuNode*& q);

bool QueueEmpty3(LinkQuNode* q);

bool EnQueue3(LinkQuNode*& q, ElemType e);

bool DeQueue3(LinkQuNode*& q, ElemType& e);

void number(int n);