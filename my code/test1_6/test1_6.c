#include<stdio.h>

int cmp(const void* p1, const void* p2)   //cmp函数返回值代表相邻值的大小关系
{
	return (*(int*)p1 - *(int*)p2);
}

void _swap(const void* p1, const void* p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)  //先强转为char型去解读逐bit位进行交换
	{
		char temp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = temp;
	}
}

void my_qsort(void* base, size_t count, size_t size, int(*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)   //cmp函数判断相邻值得大小
			{
				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);  //_swap函数进行值交换
			}
		}
	}
}

int main()
{
	//int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	char* arr[] = { "aaaa","cccc","dddd","bbbb" };
	//double arr[] = {1.1,1.5,3.0,2.8,9.6,5.6,7.333,4.21};
	int i = 0;
	int num = sizeof(arr)/sizeof(arr[0]);
	my_qsort(arr, num,sizeof(int),cmp);   //my_qsort函数需要传起始地址、元素个数、元素类型、比较函数名（即函数指针）
	for (i = 0; i < num; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
	return 0;
}