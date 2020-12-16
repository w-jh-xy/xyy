//#include<stdio.h>
//void init(int arr1[],int sz,int num)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr1[i] = num;
//	}
//	return;
//}
//
//void print(int arr2[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//}
//
//void reverse(int arr3[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr3[left];
//		arr3[left] = arr3[right];
//		arr3[right] = tmp;
//		left++;
//		right--;
//	}	
//}


#include<stdio.h>
void exch(int X[], int Y[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int tmp = X[i];
		X[i] = Y[i];
		Y[i] = tmp;
	}
}
int main()
{
	int A[5] = { 1,2,3,4,5 };
	int B[5] = { 6,7,8,9,10 };
	int len = sizeof(A) / sizeof(A[0]);
	exch(A, B, len);
	for (int i = 0; i < len; i++)
	{
		printf( "%d ",A[i] );
	}
	printf("\n");
	for (int j = 0; j < len; j++)
	{
		printf( "%d ",B[j] );
	}
	return 0;
}
