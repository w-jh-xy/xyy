#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//void leftspin(char* str, int sz, int num)
//{
//	int tmp = 0;
//	int i, j;
//	num %= sz;
//	for (i = 0; i < num; i++)
//	{
//		tmp = str[0];
//		for (j = 0; j < sz - 1; j++)
//		{
//			str[j] = str[j + 1];
//		}
//		str[j] = tmp;
//	}
//}
//int main()
//{
//	char str[] = {"ABCD"};
//	int len = strlen(str);
//	int num = 0;
//	scanf("%d", &num);
//	leftspin(str,len,num);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", str[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int Is_spin(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; 
//	strcpy(tmp, src);
//	strcat(tmp, src); 
//	return strstr(tmp, find) != NULL; 
//}
//int main()
//{
//	char str1[] = { "ABCD" };
//	char str2[] = { "BCDD" };
//	int len = strlen(str1);
//	int x=Is_spin(str1,str2, len);
//	printf("%d\n", x);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf(" % d % d", a + b, c);
//	return 0;
//}

//#include<stdio.h>
//void YangHuiTriangle(int n)
//{
//	int arr[30][30] = { 1 };
//	int i, j;
//	for (i = 1; i < n; i++)
//	{
//		arr[i][0] = 1;
//		for (j = 1; j <= i; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		putchar('\n');
//	}
//}
//int main()
//{
//	int n = 10;
//	YangHuiTriangle(n);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int murder[4] = { 0 }; 
//	for (int i = 0; i < 4; i++) 
//	{
//		murder[i] = 1; 
//		if ((murder[0] != 1) +
//			(murder[2] == 1) +
//			(murder[3] == 1) +
//			(murder[3] != 1) == 3)
//		{
//			break; 
//		}
//		murder[i] = 0; 
//	}
//	putchar('A' + i); 
//	return 0;
//}

//#include<stdio.h>
//int int_cmp(const void* p1, const void* p2)
//{
//    return (*(int*)p1 - *(int*)p2);
//}
//void _swap(void* p1, void* p2, int size)
//{
//    int i = 0;
//    for (i = 0; i < size; i++)
//    {
//        char tmp = *((char*)p1 + i);
//        *((char*)p1 + i) = *((char*)p2 + i);
//        *((char*)p2 + i) = tmp;
//    }
//}
//void bubble(void* base, int count, int size, int(*cmp)(void*, void*))
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < count - 1; i++)
//    {
//        for (j = 0; j < count - i - 1; j++)
//        {
//            if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//            {
//                swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//            }
//        }
//    }
//}
//int main()
//{
//    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//    int i = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int width = sizeof(int);
//    bubble(arr, sz, width, int_cmp);
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    return 0;
//}




#include<stdio.h>
void myqsort(void* base, size_t nitems, size_t size, int(*compar)(const void*, const void*))
{
    int i, j;
    char* st = (char*)base; //void *不方便加减，用char *加减轻松且字节跳转为1，方便控制。
    char tmp[16]; //考虑到long double类型，临时空间做成16字节比较保险

    for (i = 0; i < nitems - 1; i++)
    {
        for (j = 0; j < nitems - 1 - i; j++) //冒泡常用循环头
        {
            if (compar(st + j * size, st + (j + 1) * size)) //比较的时候跳转注意乘size
            {
                memcpy(tmp, st + j * size, size); //交换操作用memcpy完成就不会出问题。
                memcpy(st + j * size, st + (j + 1) * size, size);
                memcpy(st + (j + 1) * size, tmp, size);
            }
        }
    }
}