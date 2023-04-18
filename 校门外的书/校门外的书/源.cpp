#define _CRT_SECURE_NO_WARNINGS
#define Maxtree 305

#include<stdio.h>

int main()
{
	int arr[Maxtree]={0};
	int x, y;
	int m, n;
	scanf("%d%d", &n, &m);
	for (int j = 0; j < m; j++)
	{
		
		
			scanf("%d%d", &x,&y);
			while (x <= y)
			{
				arr[x-1] = 1;
				x++;
			}

		
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}







	return 0;
}