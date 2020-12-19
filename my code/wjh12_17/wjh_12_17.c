#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int drink = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	drink = money;
//	empty = money;
//	while (empty > 1)
//	{
//		drink += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", drink);
//	return 0;
//}


//#include<stdio.h>
//int my_strlen(const char* cp)
//{
//	const char* t = cp;
//	while (*t++);
//	return t - cp - 1;//��Ϊ*p==��\0��ʱ�����Լ�1������ʱָ��'\0'����һ���ռ䣬����ָ�����ʱ���һ��Ԫ�أ�����ټ�1�ŷ����ַ����ĳ��ȡ�
//
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int l= my_strlen(arr);
//	printf("%d\n", l);
//	return 0;
//}


//#include<stdio.h>
//#include<assert.h>
//char * my_strcpy(char * dst, const char * src)
//{
//        char * cp = dst;
// assert(dst && src);
//
// while ((*cp++ = *src++) != '\0');
//               ;     /* Copy src over dst */
//        return( dst );
//}
//
//int main()
//{
//    char str[] = "abcdefghigk";
//    char dst[]= "aaaaaaaaaaa";
//    my_strcpy(dst,str);
//    printf("src %s\n", str);
//    printf("dst %s\n", dst);
//	return 0;
//}



/*
˼·��
1. ���������±�left��right��left�����������ʼλ�ã�right�������������һ��Ԫ�ص�λ��
2. ѭ������һ�²���
 a. ���left��right��ʾ������[left, right]��Ч������b���������ѭ��
 b. left��ǰ�����ң��ҵ�һ��ż����ֹͣ
 c. right�Ӻ���ǰ�ң��ҵ�һ��������ֹͣ
 d. ���left��right���ҵ��˶�Ӧ�����ݣ��򽻻�������a��
*/
#include <stdio.h>
void fun(int arr[], int sz)
{
	int left = 0;
	int right=sz-1;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 1))
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 0))
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	fun(arr,len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}