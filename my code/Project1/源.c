#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int num = 0;
	int jg = 1;
	int i = 0;
	scanf("%d", &num);
	for (i = num; i >= 1; i--)
	{
		jg = jg * i;
	}
	printf("%d\n", jg);
	return 0;
}