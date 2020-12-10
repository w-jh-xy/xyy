#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int strlen(const char *str)
//{
//	if (*str=='\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1+strlen(str+1);
//	}
//}
//int main()
//{
//	char *p = "abcd";
//	int len = strlen(p);
//	printf("%d\n", len);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char* p = "abcd";
//	int len =0;
//	while(*p!= '\0')
//	{
//		len++;
//		p++;
//	}
//	printf("%d\n", len);
//	return 0;
//}


#include<stdio.h>
int max(int x, int y)
{
    int c = 0;
    if (x > y)
    {
        c = x;
        printf("最大值: %d", c);
    }
    else
    {
        c = y;
        printf("最大值: %d", c);
    }
    return c;
}

int main()
{
    int a = 0;
    int b = 0;
    int m = 0;
    printf("请输入两个数字：\n");
    scanf("%d %d", &a,&b);
    max(a, b);
    return 0;
}