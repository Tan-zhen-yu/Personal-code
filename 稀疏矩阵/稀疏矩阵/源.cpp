#include "test.h"


int main()
{
	
	ElemType arr[ROW][COL]={0};
	arr[1][2] = 1;
	arr[0][2] = 2;
	TSMatrix t;
	TSMatrix tb;
	CreateMat(t, arr);
	 DisPlayarr(t);
	 DispMat(t);
	 Value(t, 6, 0, 1);
	 DisPlayarr(t);
	 DispMat(t);
	

}