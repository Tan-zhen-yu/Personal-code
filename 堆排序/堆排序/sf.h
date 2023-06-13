#pragma once
#include<stdio.h>

#define MAXV 20

typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

void ShellSort(RecType R[], int n);

void Print(RecType R[]);

void BubbleSort(RecType R[], int n);

void QuickSort(RecType R[], int s, int t);

void HeapSort(RecType R[], int n);

void SelectSort(RecType R[], int n);

void BinInsertSort(RecType R[], int n);

void InserSort(RecType R[], int n);