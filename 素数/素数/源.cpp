#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int i, limit, m;
	printf("Enter a number:");
	scanf("%d", &i);
	if(i<=1)
	{
		printf("%d��������", i);
	}
	else  if (i == 2) {
		printf("%d������", i);
	}
	else {
		limit = sqrt(i) + 1;
		for (m = 2; m <= limit; m++)
		{
			if (i % m == 0)
			{
				break;
			}
		}
		
		
	}if (m>limit)
		printf("%d������", i);
	else
		printf("%d��������", i);
	return 0;
}