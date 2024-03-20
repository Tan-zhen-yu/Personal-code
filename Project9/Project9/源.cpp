#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<malloc.h>
using namespace std;

//�鲢����
void merge(int arr[], int l, int mid, int r) {
	int* B = (int*)malloc((r - l + 2) * sizeof(int));
	int i = l;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j])
			B[k++] = arr[i++];
		else
			B[k++] = arr[j++];
	}

	while (i <= mid)
		B[k++] = arr[i++];

	while (j <= r)
		B[k++] = arr[j++];

	for (i = l, k = 0; i <= r; i++)
		arr[i] = B[k++];

	


	/********end**************/
}

//�ݹ�
static void mergeSort(int arr[], int l, int r) {
	/********begin************/
	if (l < r)
	{
		int mid;
		mid = (l + r) / 2;                              //�����м�λ��
		mergeSort(arr, l, mid);                               //������A[left:mid]�е�Ԫ�ؽ��й鲢����
		mergeSort(arr, mid + 1, r);                          //������A[mid+1:right]�е�Ԫ�ؽ��й鲢����
		merge(arr, l, mid, r);                            //���кϲ�����
	}

	/********end**************/
}

//�鲢������������
void mergeSort(int arr[], int n) {
	//�������Ϊ�ջ�ֻ��һ��Ԫ�أ�����Ҫ����
	if (arr == NULL || n < 2) {
		return;
	}
	mergeSort(arr, 0, n - 1);
}


int main() {
	int n;
	scanf("%d", &n);
	int *arr=(int*)malloc(n*(sizeof(int)));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	mergeSort(arr, n);

	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}
