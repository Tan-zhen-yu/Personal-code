#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


int main()
{
	int i = 0;
	char arr1[3];
	char arr2[3];
	int n = 0;
	int j=0;
	int k=0;
	int w, h, x, z;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%2s%2s", arr1, arr2);
			j = abs(arr1[0] - arr2[0]);
			k = abs(arr1[1] - arr2[1]);
			if (j == 0 && k == 0)
			{
				printf("0 0 0 0\n");
				continue;
			}
			else
			{
				w = (j > k) ? j : k;
				if (j == 0 || k == 0 || j == k)
				{
					h = 1;
				}
				else
				{
					h = 2;
				}
				if (j == k)
				{
					x = 1;
				}
				else if ((j + k) % 2 != 0)
				{
					x = -1;
				}
				else
				{
					x = 2;
				}
				if (j == 0 || k == 0)
				{
					z = 1;
				}
				else
				{
					z = 2;
				}

			}
			if (x < 0)
			{
				printf("%d %d %d Inf\n",w,h,z);
			}
			else
			{
				printf("%d %d %d %d\n", w, h, z, x);
			}
	}
	return 0;
}