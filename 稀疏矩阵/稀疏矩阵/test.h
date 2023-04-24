#pragma once
#include<stdio.h>
#include<malloc.h>

#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3
#define Maxsize 30

typedef int ElemType;

typedef struct
{
	int r;
	int c;
	ElemType d;
}TupNode;

typedef struct
{
	int rows;
	int cols;
	int nums;
	TupNode data[Maxsize];
}TSMatrix;


void CreateMat(TSMatrix& t, ElemType A[ROW][COL]);

bool Value(TSMatrix& t, ElemType x, int i, int j);

void DispMat(TSMatrix t);

bool Assign(TSMatrix t, ElemType& x, int i, int j);

void TranTat(TSMatrix t, TSMatrix& tb);

void DisPlayarr(TSMatrix t);