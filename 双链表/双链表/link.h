#pragma once
#include<stdio.h>
#include<malloc.h>
#define ElemType int 
#define Maxsize 20

typedef struct DNode
{
	ElemType date;
	struct DNode* prior;
	struct DNode* next;

}DLinkNode;


void CreateListF(DLinkNode* &L, ElemType a[], int n);

void CreateListR(DLinkNode*& L, ElemType a[], int n);

int ListInsert(DLinkNode*& L, int i, ElemType e);

int ListDelete(DLinkNode*& L, int i, ElemType& e);

void reverse(DLinkNode*& L);

void sort(DLinkNode*& L);

void DisPlayList(DLinkNode* L);
