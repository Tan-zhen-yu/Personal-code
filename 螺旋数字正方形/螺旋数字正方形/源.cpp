#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define Max 100

int main()
{
	int n;
	int m = 1;
	scanf("%d", &n);
	int arr[Max][Max] = { 0 };
	int i = 0;
	int j;

	for (i; i < (n + 1) / 2; i++)
	{
		for (j = i; j < n - i; j++)
		{
			arr[i][j] = m++;
		}
	for (j = i + 1; j <= n - i-1; j++)
	{
		arr[j][n - i - 1] = m++;
	}
	for (j = n - i-2 ; j >= i; j--)
	{
		arr[n - i-1][j] = m++;
	}
	for (j = n - i-2; j > i; j--)
	{
		arr[j][i] = m++;
	}
}


	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}




	return 0;
}