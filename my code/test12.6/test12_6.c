#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//
//void Bubble(int arr[], int l)
//{
//	int i, j, temp;
//	for (i = 0; i < l - 1; i++)  
//	{
//		for (j = 0; j < l - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j ] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int n = 0;
//	Bubble(arr, len);
//	for (n = 0; n < len; n++)
//	{
//		printf("%d\t", arr[n]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}


//#include<stdio.h>
//int func(int i)
//{
//	int j = 0;
//	for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				return 0;
//			}
//			else
//			{
//				return 1;
//			}
//		}
//}
//
//int main()
//{
//	int i = 0;
//	
//	for (i = 100; i <= 200; i++)
//	{
//		if (func(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int year;
//	scanf("%d",&year);
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//	{
//		printf("是闰年 ");
//	}
//	else
//	{
//		printf("不是闰年");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 1;
//	int next = 0;
//	int n = 0;
//	int	i= 0;
//	scanf("%d", &n);
//	if (n > 2)
//	{
//		for (i = 3; i <= n; i++)
//		{
//			next = a + b;
//			a = b;
//			b = next;
//		}
//		printf("%d\n", next);
//	}
//	else
//	{
//		printf("%d\n", 1);
//	}
//	return 0;
//}

//#include<stdio.h>
//int fb(int n)
//{
//
//		if (n <= 2)
//		{
//			return 1;
//		}
//		else
//		{
//			return fb(n - 1) + fb(n - 2);
//		}
//	
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int res = fb(n);
//	printf("%d\n", res);
//	return 0;
//}

//#include<stdio.h>
//
//int fun(int x, int y)
//{
//	int z= x % y;
//	while (z != 0)
//	{
//		x = y;
//		y = z;
//		z = x % y;
//	}
//	return y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;
//	int res = 0;
//	scanf("%d %d", &a, &b);
//	if (a >=b)
//	{
//		 res=fun(a, b);
//	}
//	else
//	{
//		temp = a;
//		a = b;
//		b = temp;
//		res = fun(a, b);
//	}
//	printf("%d\n", res);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//#include<stdio.h>
//int fun(int x)
//{
//	int n = 0;
//	for (n = 2; n < x; n++)
//	{
//		if (x % n != 0)
//		{
//			return x;
//		}
//		//else
//		//{
//		//	return;
//		//}
//	}
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//if (fun(i)==1) 
//		//{
//			printf("%d 是素数  ", fun(i));
//	//	}
//	}
//	return 0;
//}

#include<stdio.h>
int func(int i)
{
	int j = 0;
	for (j = 2; j < i; j++)
	{
		if (i % j == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}


int main()
{
	int i = 0;

	for (i = 100; i <= 200; i++)
	{
		if (func(i) == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}