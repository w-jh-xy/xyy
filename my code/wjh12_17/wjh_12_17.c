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
//	return t - cp - 1;//因为*p==‘\0’时，再自加1，返回时指向'\0'的下一个空间，导致指针相减时多出一个元素，因此再减1才返回字符串的长度。
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
思路：
1. 给定两个下标left和right，left放在数组的起始位置，right放在数组中最后一个元素的位置
2. 循环进行一下操作
 a. 如果left和right表示的区间[left, right]有效，进行b，否则结束循环
 b. left从前往后找，找到一个偶数后停止
 c. right从后往前找，找到一个奇数后停止
 d. 如果left和right都找到了对应的数据，则交换，继续a，
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