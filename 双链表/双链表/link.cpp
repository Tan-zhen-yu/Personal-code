#define _CRT_SECURE_NO_WARNINGS

#include"link.h"


void CreateListF(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->date = a[i];
		s->next = L->next;
		s->prior = L;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
	}

}


void CreateListR(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->date = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}


int ListInsert(DLinkNode*& L, int i, ElemType e)
{
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)
		return 0;
	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->date = e;
		s->next = p->next;
		s->prior = p;
		p->next = s;
		if (p->next != NULL)
			p->next->prior = s;
		return 1;

	}


}

int ListDelete(DLinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	DLinkNode* p = L, * q;
	if (i <= 0)
		return 0;
	while (j < i - 1 && p != NULL)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else
	{
		q = p->next;
		if (q == NULL)
			return 0;
		e = q->date;
		p->next = q->next;
		if (q->next != NULL)
			q->next->prior = p;
		free(q);
		return 1;
	}
}


void reverse(DLinkNode*& L)
{
	DLinkNode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		if (L->next != NULL)
			L->next->prior = p;
		p->prior = L;
		p = q;


	}

}


void sort(DLinkNode*& L)
{
	DLinkNode* p, * pre, * q;
	p = L->next->next;
	L->next->next= NULL;
	while (p != NULL)
	{
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->date < p->date)
			pre = pre->next;
		p->next = pre->next;
		if (pre->next != NULL)
			pre->next->prior = p;
		p->prior = pre;
		pre->next = p;
		p = q;
	}
}

void DisPlayList(DLinkNode* L)
{
	DLinkNode* p =L->next;
	while (p != NULL)
	{
		
		printf(" %d ", p->date);
		
		p = p->next;
	}
	printf("\n");
}
