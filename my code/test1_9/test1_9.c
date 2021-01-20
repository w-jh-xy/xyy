/*有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。 */
//#include<stdio.h>
//
//int findnum(int arr[][3], int x, int y, int f)
//{
//	/*for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			if (arr[i][j] == f)
//			{
//				return 1;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//	}*/
//	int i = 0, j = x - 1;
//	while (j >= 0 && i < y)
//	{
//		if (arr[i][j] < f)
//		{
//			i++;
//		}
//		else if (arr[i][j] > f)
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[][3] = { {1,3,5},{3,5,7},{5,7,9} };
//	if (findnum(arr, 3, 3, 2))
//	{
//		printf("It has been found!\n");
//	}
//	else
//	{
//		printf("It has not been found!\n");
//	}
//	return 0;
//}

#include<stdio.h>
void* my_memmove(void * dest,const void * src,size_t num)
{
	void* ret = dest;
	if (dest <= src || (char*)src + num)   //目的地址不溢出
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + num - 1;
		src = (char*)src + num - 1;
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
}
int main()
{

	return 0;
}