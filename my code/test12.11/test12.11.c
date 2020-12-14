//#include<stdio.h>
//int main()
//{
//	int arr[] = { 0,1,3,2,4,5,16,7,8,11};
//	int max = 0;
//	int i = 0;
//	int b = 0;
//	for (i = 0; i<9; i++)
//	{
//		if (arr[i] > arr[i+1])
//		{
//			arr[i + 1] = arr[i];
//		}
//	}
//	max = arr[i];
//	printf("%d\n", max);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}