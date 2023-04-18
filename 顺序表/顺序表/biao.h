#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define Maxsize 50
#define false 1;

typedef char ElemType;

struct Date
{
	char num[20];
	char sex[5];
	char name[8];
};

struct Date date[Maxsize];
typedef struct
{
	struct Date date[Maxsize];
	int length;
}Sqlist;

#include<stdio.h>
#include<malloc.h>
#include<string.h>

void CreateList(Sqlist* L, ElemType(*a1)[Maxsize], ElemType(*a2)[Maxsize], ElemType(*a3)[Maxsize], int n);

void InitList(Sqlist*  L);

void DestoryList(Sqlist* L);

int ListEmpty(Sqlist* L);

int ListLenth(Sqlist* L);

void DispList(Sqlist* L);



int LocateElem1(Sqlist* L, ElemType(*a1)[Maxsize]);

int LocateElem2(Sqlist* L, ElemType(*a1)[Maxsize]);

int  ListInsert(Sqlist* L, int i, ElemType(*a1)[Maxsize], ElemType(*a2)[Maxsize], ElemType(*a3)[Maxsize]);

int ListDelete(Sqlist*   L, int i);

void partition2(Sqlist*  L, int n);

void PX(Sqlist *  L, int n);

