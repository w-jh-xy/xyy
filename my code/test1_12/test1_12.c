#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<assert.h>
//VALID 表示结果合法
//INVALID 表示结果非法
enum State
{
    VALID,//0
    INVALID//1
};
//默认结果可能非法，当正确转换后再改为合法
enum State state = INVALID;

int my_atoi(const char* str)
{
    int flag = 1;
    long long ret = 0;//定义为比int存储范围更大的类型，防止判断溢出时出错
    assert(str);
    state = INVALID;
    //用isspace函数判断字符是否为空，并跳过空白字符
    while (isspace(*str))
    {
        str++;
    }
    if (*str == '\0')
    {
        return 0;
    }
    //跳过正负号
    if (*str == '+')
    {
        str++;
    }
    else if (*str == '-')
    {
        flag = -1;
        str++;
    }
    //开始转换数字字符直到非数字字符
    while (isdigit(*str))
    {
        ret = ret * 10 + flag *(*str - '0');
        if ((ret > INT_MAX) || (ret < INT_MIN))
        {
            return 0;
        }
        str++;
    }
    //正常停止
    if(*str == '\0')
    {
        state = VALID;
        return (int)ret;
    }
    else
    {
        //遇到非数字字符
        return (int)ret;
    }
}

int main()
{
    //char* p = "-1212212121212";
    char* p = "-12";
    printf("%d\n", my_atoi(p));
    return 0;
}

//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//int my_atoi(const char* str)
//{
//	assert(str != NULL);
//	//跳过空格  如果是 ‘  4194’这种情况
//	while (isspace(*str))//用函数isspace判断是否为空白字符
//      {
//          str++;
//      }
//	int flag = 1;// 符号位 
//	if (*str == '-')
//	{
//		flag = -1;  //如果有-  则置-1   看是否是负数
//		str++;  //str++ 判断后面的字符是否是数字
//	}
//
//	else if (*str == '+')
//		str++;  // str++ 判断后面的字符是否是数字
//	long long res = 0;
//	while (*str != '\0')
//	{
//		if(*str < '0' || *str>'9')// 如果是个字符 无效的字符串
//			break; //直接跳出 
//		res = res * 10 + flag * (*str - '0');//字符4是52-字符0就是真的数字4了   字符0是48 
//		if(res > INT_MAX || res < INT_MAX)  //判断这个数是否超出整形范围  若超范围了 返回0
//			return 0;
//		
//	}
//	str++;
//	return res;
//}
//int main()
//{
//	char* str = "-4194";
//	int res1 = atoi(str);
//	printf("res1=%d\n", res1);
//	int res2 = my_atoi(str);
//	printf("res2=%d\n", res2);
//    system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <assert.h>
//
////定义两个枚举常量来表示状态
//enum STATE
//{
//    VALID, //合法
//    INVALID,//非法
//};
//enum STATE state = INVALID;
//int my_atoi(const char* str)
//{
//    int flag = 1;
//    long long ret = 0;//定义为比int存储范围还要大的类型，防止后面判断溢出时出错。
//    //空指针
//    assert(str);
//    //空字符串
//    if (*str == '\0')
//    {
//        return 0;
//    }
//    //空白字符
//    while (isspace(*str))//用函数isspace判断是否为空白字符
//    {
//        str++;
//    }
//    //遇到正负号
//    if (*str == '-')
//    {
//        flag = -1;
//        str++;
//    }
//    if (*str == '+')
//    {
//        str++;
//    }
//    //
//    while (*str)
//    {
//        //if (*str >= '0'&&*str <= '9')
//        if (isdigit(*str))//用函数isdigit判断是否为数字字符
//        {
//            ret = ret * 10 + flag * (*str - '0');
//            //判断是否溢出
//            if (ret > INT_MAX || ret < INT_MIN)
//            {
//                return ret;
//            }
//        }
//        //异常字符
//        else
//        {
//            break;
//        }
//        str++;
//    }
//    state = VALID;
//    return ret;
//}
//int main()
//{
//    char* p = "12345";
//    char* q = " -12345";
//    int ret = my_atoi(p);
//    int ret2 = my_atoi(q);
//    printf("%d\n", ret);
//    printf("%d\n", ret2);
//    system("pause");
//    return 0;
//}