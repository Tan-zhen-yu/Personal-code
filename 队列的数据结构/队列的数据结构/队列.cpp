#define _CRT_SECURE_NO_WARNINGS
#include"dui.h"

//////////////普通队列
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

void DestoryQueue(SqQueue*& q)
{
	free(q);
}

bool QueueEmpty(SqQueue* q)
{
	return (q->front == q->rear);
}

bool EnQueue(SqQueue*& q, ElemType e)
{
	if (q->rear == Maxsize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;

}

bool DeQueue(SqQueue*& q, ElemType& e)
{
	if (q->rear == q->front)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}


/////////////////环形队列


void InitQueue1(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

void DestoryQueue1(SqQueue*& q)
{
	free(q);
}

bool QueueEmpty1(SqQueue* q)
{
	return (q->front == q->rear);
}

bool EnQueue1(SqQueue*& q, ElemType e)
{
	if ((q->rear+1)%Maxsize == q->front)
		return false;
	q->rear = (q->rear + 1) % Maxsize;
	q->data[q->rear] = e;
	return true;

}

bool DeQueue1(SqQueue*& q, ElemType& e)
{
	if (q->rear == q->front)
		return false;
	q->front = (q->front + 1) % Maxsize;
	e = q->data[q->front];
	return true;
}


int Count1(SqQueue* q)
{
	return (q->rear - q->front + Maxsize) % Maxsize;
}


//////////////改进环形队列



void InitQueue2(QuType*& qu)
{
	qu = (QuType*)malloc(sizeof(QuType));
	qu->front = 0;
	qu->count = 0;
}

bool EnQueue2(QuType*& qu, ElemType x)
{
	int rear;
	if (qu->count == Maxsize)
		return false;
	else
	{
		rear = (qu->front + qu->count) % Maxsize;
		rear = (rear + 1) % Maxsize;
		qu->data[rear] = x;
		qu->count++;
		return true;
	}
}

bool DeQueue2(QuType*& qu, ElemType& x)
{
	if (qu->count == 0)
		return false;
	else
	{
		qu->front = (qu->front + 1) % Maxsize;
		x = qu->data[qu->front];
		qu->count--;
		return true;
	}
}

bool QueueEmpty2(QuType* qu)
{
	return(qu->count == 0);
}


//////////队列的链式储存结构

void InitQueue3(LinkQuNode* q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

void DestroyQueue3(LinkQuNode*&q)
{
	DataNode* pre = q->front, * p;
	if (pre != NULL)
	{
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		
			free(pre);
	}
		free(q);
}

bool QueueEmpty3(LinkQuNode* q)
{
	return (q->rear == NULL);
}

bool EnQueue3(LinkQuNode*& q, ElemType e)
{
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
	return true;
}

bool DeQueue3(LinkQuNode*& q, ElemType& e)
{
	DataNode* t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = t->next;
	e = t->data;
	free(t);
	return true;
}

////////算法设计，求解报数问题

void number(int n)
{
	int i;
	ElemType e;
	SqQueue* q;
	InitQueue(q);
	for (i = 1; i <= n; i++)
	{
		EnQueue1(q, i);
	}
	printf("报数出列顺序: ");
	while (!QueueEmpty1(q))
	{
		DeQueue1(q, e);
		printf("%d", e);
		if (!QueueEmpty1(q))
		{
			DeQueue1(q, e);
			EnQueue1(q, e);
		}
		printf("\n");
		DestoryQueue1(q);
	}

}