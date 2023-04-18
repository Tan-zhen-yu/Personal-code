#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fj(int brr[], int n)
{
	int j = 0;
	while (n != 0)
	{
		brr[j] = n % 10;
		n = n / 10;
		j++;
	}
	brr[j] = -1;
	j--;
	for (int i = 0; i <= j; i++, j--)
	{
		int t = brr[i];
		brr[i] = brr[j];
		brr[j] = t;
	}
}



int main()
{
	int brr[10];
	char arr1[] = { "- -- -----" };
	char arr2[] = { "|   ||| ||" };
	char arr3[] = { "||||| ||||" };
	char arr4[] = { "  ----- --" };
	char arr5[] = { "| |   | | " };
	char arr6[] = { "|| || ||||" };
	char arr7[] = { "- -- -- --" };
	char* crr[7] = { arr1,arr2,arr3,arr4,arr5,arr6,arr7 };
	int s = 0;
	int n = 0;
	int j = 0;
	int i = 0;

	scanf("%d%d", &s, &n);

	while (s != 0 && n != 0)
	{
		fj(brr, n);
		
			
			while (j < 7)
			{
				for (i = 0; brr[i] > 0; i++)
				{
					if (crr[j][brr[i]] == '-')
						printf(" %c ", crr[j][brr[i]]);
					else if (crr[j][brr[i]] == '|')
						if(j==1||j==4)
						printf("%c ", crr[j][brr[i]]);
						else if(j==2||j==5)
							printf(" %c", crr[j][brr[i]]);
				
				}
				if(j==0||j==2||j==5||j==3)
				printf("\n");
				
				
				
				j++;
			}
			
		
		scanf("%d%d", &s, &n);
	} 



	return 0;
}