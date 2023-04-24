#include"test.h"


void CreateMat(TSMatrix& t, ElemType A[ROW][COL])
{
	t.rows = ROW;
	t.cols = COL;
	t.nums = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (A[i][j] != 0)
			{
				t.data[t.nums].r = i;
				t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j];
				t.nums++;
			}
		}
	}
}

bool Value(TSMatrix& t, ElemType x, int i, int j)
{
	int k = 0;
	int k1;
	if (i >= t.rows || j > t.cols)
	{
		return false;
	}
	else
	{
		while (k<t.nums && i>t.data[k].r)
			k++;
		while (k<t.nums && i == t.data[k].r && j>t.data[k].c)
			k++;
		if (t.data[k].r == i && i == t.data[k].c == j)
			t.data[k].d = x;
		else
		{
			for (k1 = t.nums - 1; k1 >= k; k1--)
			{
				t.data[k1 + 1].r = t.data[k1].r;
				t.data[k1 + 1].c = t.data[k1].c;
				t.data[k1 + 1].d = t.data[k1].d;
			}
			t.data[k].r = i;
			t.data[k].c = j;
			t.data[k].d = x;
			t.nums++;
		}
		return true;
	}
} 


bool Assign(TSMatrix t, ElemType& x, int i, int j)
{
	int k = 0;
	if (i >= t.rows || j >= t.cols)
		return false;
	else
	{
		while (k<t.nums && i>t.data[k].r)
			k++;
		while (k<t.nums && i>t.data[k].c)
			k++;
		if (t.data[k].r == i && t.data[k].c == j)
			x = t.data[k].d;
		else
			x = 0;
		return true;
	}
}

void DispMat(TSMatrix t)
{
	int k;
	if (t.nums <= 0)
		return;
	printf("\tÐÐ\tÁÐ\tÖµ\n");
	printf("\t-----------------\n");
	for (k = 0; k < t.nums; k++)
		printf("\t%d\t%d\t%d\n", t.data[k].r+1, t.data[k].c+1, t.data[k].d);
}

void TranTat(TSMatrix t, TSMatrix& tb)
{
	int k, k1 = 0, v;
	tb.rows = t.cols; tb.cols = t.rows; tb.nums = t.nums;
	if (t.nums != 0)
	{
		for (v = 0; v < t.cols; v++)
		{
			for (k = 0; k < t.nums; k++)
			{
				tb.data[k1].r = t.data[k].c;
				tb.data[k1].c = t.data[k].r;
				tb.data[k1].d = t.data[k].d;
				k1++;
			}
		}
	}
}

void DisPlayarr(TSMatrix t)
{
	int k = 0;
	
	

		for (int i=0; i < t.cols; i++)
		{
			for (int j=0; j < t.rows; j++)
			{
				if (i != t.data[k].r || j != t.data[k].c)
					printf("*");
				else
				{
					printf("%d", t.data[k].d);
					k++;
				}
			}
			printf("\n");
		}
		
		printf("\n");

}