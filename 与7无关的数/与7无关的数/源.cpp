#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int j = 0;
	int n = 0;
	int i = 0;
	int x = 0;
	int t = 0;
	int sum = 0;
	scanf("%d", &n);
	
	for (j=1;j<=n;j++)
	{
		t = 1;
		int arr[10];
		int q = j;
		i = 0;
		while (q > 0)
		{
			arr[i] = q % 10;
			q = q / 10;
			i++;
		}
		for (int p = 0; p < 10; p++)
		{
			if (arr[p] == 7)
				t = 0;
		}

		if (j % 7 == 0)
			t = 0;
		if (t != 0)
			sum = sum + pow(j, 2);
	}  
	printf("%d", sum);








	return 0;
}