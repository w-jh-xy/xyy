#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int revers(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else 
//	{
//		revers(str+1);
//	}
//	printf("%c  ", *str);
//}
//int main()
//{
//	char* p = "abcd";
//	revers(p);
//	
//	return 0;
//}

//#include <stdio.h>
//
//int sum(int input)
//{
//	if (input > 9)
//	{
//		return input % 10 + sum(input / 10);
//		
//	}
//	else 
//	{
//		return input;
//	}
//	
//}
//
//int main()
//{
//	int input;
//	scanf("%d", &input);
//	printf("%d\n", sum(input));
//	return 0;
//}


//#include <stdio.h>
//
//int cf(int n,int k)
//{
//	if (k > 0)
//	{
//		return n*cf(n,k-1);
//	}
//	else
//	{
//		return 1;
//	}
//
//}
//
//int main()
//{
//	int n;
//	int k;
//	scanf("%d%d", &n,&k); 
//	int rs = cf(n, k);
//	printf("%d\n", rs);
//	return 0;
//}



//int fib(int n)
//{
//	int result;
//	int preres;
//	int nextres;
//	result = preres = 1;
//	while (n > 2)
//	{
//		
//	
//	}
//
//
//
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    printf("%d\n", strlen("c:\test\121"));
//    printf("%s\n","\121");
//    return 0;
//}
//
//#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
//int max(int x, int y)
//{
//    int c = 0;
//    if (x > y)
//    {
//        c = x;
//        printf("最大值: %d", c);
//    }
//    else
//    {
//        c = y;
//        printf("最大值: %d", c);
//    }
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int m = 0;
//    printf("请输入两个数字：\n");
//    scanf("a = %d b = %d\n", &a, &b);
//    max(a, b);
//    return 0;
//}

//
//#include<stdio.h>
//
//int main()
//{
//	int sum = 0;
//	int i = 0;
//	int res = 1;
//	for (i = 1; i <= 10; i++)
//	{
//		res = res * i;
//		sum = res + sum;
//	}
//	
//	printf("%d\n",sum);
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int max = (a>b)?(a):(b);
//	printf("%d\n", max);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}