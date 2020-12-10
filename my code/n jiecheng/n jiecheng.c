#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}
int main()
{
	int num=0;
	scanf("%d",&num);
	printf("%d\n", factorial(num));
	return 0;
}