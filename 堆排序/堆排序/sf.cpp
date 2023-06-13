#define _CRT_SECURE_NO_WARNINGS

#include"sf.h"

void swap(RecType&x, RecType&y)
{
	RecType tmp = x;
	x = y;
	y = tmp;
}

void Print(RecType R[])
{
	for (int i = 0; i < MAXV; i++)
	{
		printf("%d ", R[i].key);
	}
}


void InserSort(RecType R[], int n)//÷±Ω”≤Â»ÎÀ„∑®
{
	int i, j;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)
		{
			tmp = R[i];
			j = i - 1;
			do
			{
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].key > tmp.key);
			R[j + 1] = tmp;
		}
	}
}

void BinInsertSort(RecType R[], int n)//’€∞Î≤È’“≈≈–Ú
{
	int i, j, low, high, mid;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)
		{
			tmp = R[i];
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp.key < R[mid].key)
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= high + 1; j--)
			{
				R[j + 1] = R[j];
			}
			R[high + 1] = tmp;

		}
	}
}

void ShellSort(RecType R[], int n)
{
	int i, j, d;
	RecType tmp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			tmp = R[i];
			j = i-d ;
			while (j >= 0 && tmp.key < R[j].key)
			{
				R[j+d] = R[j];
				j = j - d;
			}
			R[j+d] = tmp;
		}
		d = d / 2;
	}
}

void BubbleSort(RecType R[], int n)//√∞≈›≈≈–Ú
{
	int i, j;
	bool exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (j = n - 1; j > i; j--)
		{
			if (R[j].key < R[j - 1].key)
			{
				swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)
			return;
	}
}


int partition(RecType R[], int s, int t)//“ªÃÀ≈≈–Ú
{
	int i = s, j = t;
	RecType base = R[i];
	while (i < j)
	{
		while (j > i && R[j].key >= base.key)
		{
			j--;
		}
		if (i < j)
		{
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i].key < base.key)
		{
			i++;
		}
		if (i < j)
		{
			R[j] = R[i];
			j--;
		}
	}
	R[i] = base;
	return i;

}

void QuickSort(RecType R[], int s, int t)//øÏÀŸ≈≈–Ú
{
	int i;
	if (s < t)
	{
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);
		QuickSort(R, i + 1, t);
	}
}


void SelectSort(RecType R[], int n)//ºÚµ•—°‘Ò≈≈–Ú
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (R[j].key < R[k].key)
			{
				k = j;
			}
		}
		if (k != i)
			swap(R[i], R[k]);
	}
}

void sift(RecType R[], int low, int high)
{
	int i = low, j = 2 * i;
	RecType tmp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key)
		{
			j++;
		}
		if (tmp.key < R[j].key)
		{
			R[i] = R[j];
				i = j;
				j = 2 * i;
		}
		else
		{
			break;
		}
	}
	R[i] = tmp;
}

void HeapSort(RecType R[], int n)//∂—≈≈–Ú
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		sift(R, i, n);
	}
	for (i = n; i >= 2; i--)
	{
		swap(R[1], R[i]);
		sift(R, 1, i - 1);
	}
}
