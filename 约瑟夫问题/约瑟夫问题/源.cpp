#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define hz 10



int main()
{
	int arr[hz]={0};
	int n, m;
	
	int count = 0;
	int y = 1;
	scanf("%d%d", &n, &m);
	int N = n;
	while (n!=0&&m!=0)
	{
		int x = 0;
		count = n;
		
		int arr[hz] = {0};
		while (count != 1)
		{
			
			int y = 1;
			while (y < m)
			{
				x = (x + 1) % n;
				y++;
			}
		
			if (arr[x] == 0)
			{
				arr[x] = 1;
				count--;
				x = (x + 1) % n;
			}
		}

		for (int i = 0; i < n; i++)
		{

			printf("%d ", arr[i]);
		}

		
		scanf("%d%d", &n, &m);

	}
	














}




