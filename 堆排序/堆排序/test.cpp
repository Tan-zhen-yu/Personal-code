#define _CRT_SECURE_NO_WARNINGS

#include"sf.h"





int main()
{
	int j = MAXV;
	RecType arr[MAXV];
	for (int i = 0; i <MAXV; i++)
	{
		arr[i].key = j;
		j--;
	}
	Print(arr);
    HeapSort(arr, 10);
	printf("\n");

		Print(arr);




	return 0;
}