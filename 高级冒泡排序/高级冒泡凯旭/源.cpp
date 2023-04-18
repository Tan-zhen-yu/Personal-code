#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}


}

void bubble(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}


}
void bubble_sort(void* base, int sz, int width,int(* cmp)(const void* e1, const void* e2))
{

	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width,(char*)base + (j + 1) * width, width);

			}
		}
	}




}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}


int main()
{

	int arr[10] = { 9,8,7,6,5,4,3,2,1,0};
	/*bubble(arr, sizeof(arr) / sizeof(arr[0])-1);*/
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]) - 1, sizeof(arr[0]),cmp_int);






	return 0;
}