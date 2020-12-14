#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("********************************\n");
//	printf("*************1.play*************\n");
//	printf("*************0.exit*************\n");
//	printf("********************************\n");
//}
//
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("请输入猜的数字：");
//		scanf("%d", &input);
//		if (input > random_num)
//		{
//			printf("你猜大了\n");
//		}
//		else if(input<random_num)
//		{
//			printf("你猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，你猜对了！\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//		do
//		{
//			menu();
//			printf("请选择>:");
//			scanf("%d",&input);
//			switch (input)
//			{
//			case 1:
//				game();
//				break;
//			case 0:
//				break;
//			default:
//				printf("选择错误！请重新输入！\n");
//				break;
//			}
//		} while (input);
//		return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0])-1;
//	int mid = 0;
//	int key = 7;
//	while (left<=right) 
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if(arr[mid]>key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (left <= right)
//		printf("找到了，下标是%d\n", mid);
//	else
//		printf("找不到\n");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int num = 0;
//	scanf("%d%d",&m,&n);
//	int i = 32;
//	while (i--)
//	{
//		int x = 0;
//		int y = 0;
//		x = m % 2;
//		y = n % 2;
//		m = m / 2;
//		n = n / 2;
//		if (1 == (x ^ y))
//		{
//			num++;
//		}
//	}
//	printf("%d\n", num);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int op = 0;
//	int jp = 0;
//	scanf("%d",&a);
//	//printf("奇 偶\n");
//	for (int i = 0; i < 32; i++)
//	{
//		op = a % 2;
//		a = a / 2;
//		if (i % 2 == 0)
//		{
//			printf("偶 ");
//			printf("%d  ", op);
//			//printf("\n");
//		}
//		else
//		{
//			jp = op;
//			printf("%d  ", jp);
//			printf("\n");
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int fun(int x)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (1 == (x & 1))
//		{
//			count++;
//		}
//		x = x >> 1;
//	}
//	return count;
//}
//int main()
//{
//	int input = 0;
//	int count = 0;
//	scanf("%d",&input);
//	count = fun(input);
//	printf("%d\n", count);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d\n", a, b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int res = 0;
//	scanf("%d", &n);
//	if (0 == n)
//	{
//		res = 1;
//	}
//	else
//	{
//		res = 2 << (n - 1);
//	}
//	printf("2的%d次方是：%d\n", n,res);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int* p = arr;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//void fun(int a, int b)
//{
//    a = a + b;
//    b = a - b;
//    a = a - b; 
//    printf("%d %d\n", a, b);  
//}
//int main()
//{
//    int x = 0;
//    int y = 0;
//    scanf("%d%d",&x,&y);
//    fun(x, y);
//    return 0;
//}


//#include<stdio.h>
//void fun(char* ch1)
//{
//	int i, len;
//	len = strlen(ch1);
//	for (i = len - 1; i >= 0; i--)
//	{
//		printf("%c", ch1[i]);
//		
//	}
//	printf("\n");
//}
//int main()
//{
//	char str[] = "abcd";
//	printf("%s\n", str);
//	fun(str);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//	int sn = a + 11 * a + 111 * a + 1111 * a + 11111 * a;
//	printf("%d\n", sn);
//	return 0;
//}

//#include<stdio.h>
//int fun(int num,int times)
//{
//	int res = 1;
//	for (int i = 0; i < times; i++)
//	{
//		res *= num;
//	}
//	return res;
//}
//int main()
//{
//	for (int i = 10; i <= 100000; i++)
//	{
//		int wei = 1;
//		int sum = 0;
//		int temp = i;
//		while (temp / 10) //计算数字的位数
//		{
//			wei++;
//			temp /= 10;
//		}
//		temp = i;
//		for (int j = 0; j < wei; j++)  //计算各位数的n次方之和
//		{
//			sum += fun(temp % 10, wei);
//			temp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d为水仙花数\n", i);
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int n=13;
//	int i;
//	int j;
//	for (i = 1; i <= (n + 1) / 2; ++i)
//	{
//		for (j = 1; j <= n + 1 - 2 * i; ++j)
//		{
//			printf(" ");
//		}
//
//		for (j = 1; j <= 2 * i - 1; ++j)
//		{
//			printf("* ");
//		}
//
//		printf("\n");
//	}
//
//	for (i = 1; i <= (n - 1) / 2; ++i)
//	{
//		for (j = 1; j <= 2 * i; ++j)
//		{
//			printf(" ");
//		}
//
//		for (j = 1; j <= n - 2 * i; ++j)
//		{
//			printf("* ");
//		}
//
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>  
//int main()
//{
//    int n, j, i;      /*i为行数,j为每行中的项数*/
//    n = 13;
//        for (i = 1; i <= n / 2 + 1; i++)   /*打印上三角，（包括中间行）*/
//        {
//            for (j = 1; j <= n / 2 + i; j++)
//            {
//                if (j >= n / 2 - i + 2)
//                    printf(" *");
//                else
//                    printf("  ");
//            }
//            printf("\n");
//        }
//        for (i = n / 2; i >= 1; i--)  /*打印下三角，（不包括中间行）*/
//        {                             /*将i改为倒序*/
//            for (j = 1; j <= n / 2 + i; j++) 
//                if (j >= n / 2 - i + 2)
//                    printf(" *");
//                else
//                    printf("  ");
//            printf("\n");
//        }
//    return 0;
//}

int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;
	empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return 0;
}