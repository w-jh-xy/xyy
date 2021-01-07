#include<stdio.h>

int cmp(const void* p1, const void* p2)   //cmp��������ֵ��������ֵ�Ĵ�С��ϵ
{
	return (*(int*)p1 - *(int*)p2);
}

void _swap(const void* p1, const void* p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)  //��ǿתΪchar��ȥ�����bitλ���н���
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
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)   //cmp�����ж�����ֵ�ô�С
			{
				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);  //_swap��������ֵ����
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
	my_qsort(arr, num,sizeof(int),cmp);   //my_qsort������Ҫ����ʼ��ַ��Ԫ�ظ�����Ԫ�����͡��ȽϺ�������������ָ�룩
	for (i = 0; i < num; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
	return 0;
}