#define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int Sum_Solution(int n)
    {
        int sum = (int)Math.pow(n, 2) + n;
        return sum >> 1;
    }
};

//class Solution {
//public:
//    int Sum_Solution(int n)
//    {
//        bool x = n > 1 && (n += Sum_Solution(n - 1));
//        return n;
//    }
//};


//#include <iostream>
//#include<stdio.h>
//using namespace std;
//bool Isleapyear(int year)
//{
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    int m[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int day = m[month];
//    if (month == 2 && (Isleapyear(year)))
//        day = m[0];
//    return day;
//}
//int main()
//{
//    int year = 1970, month = 1, day = 1,delta=1;
//    int y = 1970, m = 1, d = 1;
//    while (scanf("%d %d %d", &year, &month, &day) != EOF)
//    {
//        y = year; m = 1; d = 1;
//        while ((y< year) || (m < month) || (d < day))
//        {
//            d++;
//            if (d == GetMonthDay(y, m) + 1)
//            {
//                m++;
//                d = 1;
//            }
//            if (m == 13)
//            {
//                y++;
//                m = 1;
//            }
//            delta++;
//        }
//        printf("%d\n", delta);
//        delta = 1;
//    }
//    return 0;
//}



//#include <iostream>
//#include<stdio.h>
//using namespace std;
//bool Isleapyear(int year)
//{
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    int m[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int day = m[month];
//    if (month == 2 && (Isleapyear(year)))
//        day = m[0];
//    return day;
//}
//int main()
//{
//    int delta = 1;
//    int date1, date2;
//    int maxy = 0, maxm = 0, maxd = 0;
//    int miny = 0, minm = 0, mind = 0;
//    while (scanf("%d%d", &date1, &date2) != EOF)
//    {
//        if (date1 > date2)
//        {
//            int tmp = date1;
//            date1 = date2;
//            date2 = tmp;
//        }
//        mind = date1 % 100; maxd = date2 % 100;
//        date1 /= 100; date2 /= 100;
//        minm = date1 % 100; maxm = date2 % 100;
//        date1 /= 100; date2 /= 100;
//        miny = date1; maxy = date2;
//        delta = 1;
//        while ((miny < maxy) || (minm < maxm) || (mind < maxd))
//        {
//            mind++;
//            if (mind == GetMonthDay(miny, minm)+1)
//            {
//                minm++;
//                mind = 1;
//            }
//            if (minm == 13)
//            {
//                miny++;
//                minm = 1;
//            }
//            delta++;
//        }
//        printf("%d\n", delta+1);
//    }
//    return 0;
//}


//#include <iostream>
//using namespace std;
//bool Isleapyear(int year)
//{
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    int m[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int day = m[month];
//    if (month == 2 && (Isleapyear(year)))
//        day = m[0];
//    return day;
//}
//int main()
//{
//    int m = 0, n = 0;
//    int _year=1970;
//    int _month=1;
//    int _day=1;
//    int mday = GetMonthDay(_year, _month);
//    scanf("%d", &m);
//    while (m--)
//    {
//        scanf("%d %d %d %d", &_year, &_month, &_day, &n);
//        n += _day;
//        _day = 0;
//        while (n > GetMonthDay(_year, _month))
//        {
//            n -= GetMonthDay(_year, _month);
//            if (_month == 12)
//            {
//                _year++;
//                _month = 1;
//            }
//            else
//            {
//                _month++;
//            }
//        }
//        _day += n;
//        printf("%04d-%02d-%02d\n", _year, _month, _day);
//    }
//    return 0;
//}

//某一年的第N天是当年的几月几号
//#include <iostream>
//using namespace std;
//bool Isleapyear(int year)
//{
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    int m[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int day = m[month];
//    if (month == 2 && (Isleapyear(year)))
//        day = m[0];
//    return day;
//}
//int main()
//{
//    int y = 0, n = 0;
//    int _year=1970;
//    int _month=1;
//    int _day=1;
//    while (scanf("%d %d", &y, &n) != EOF)
//    {
//        n -= GetMonthDay(_year, _month);
//    }
//    return 0;
//}

//一个日期加上n天之后是什么日期
//#include <iostream>
//using namespace std;
//bool Isleapyear(int year)
//{
//    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int GetMonthDay(int year, int month)
//{
//    int m[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int day = m[month];
//    if (month == 2 && (Isleapyear(year)))
//        day = m[0];
//    return day;
//}
//int main()
//{
//    int m = 0, n = 0;
//    int _year=1970;
//    int _month=1;
//    int _day=1;
//    int mday = GetMonthDay(_year,_month);
//    scanf("%d", &m);
//    
//    while (m--)
//    {
//        scanf("%d %d %d %d", &_year, &_month, &_day,&n);
//        while (_day + n > mday)
//        {
//            _month++;
//            if (_month > 12)
//            {
//                _year++;
//                _month = 1;
//            }
//            n -= mday;
//            mday = GetMonthDay(_year, _month);
//        }
//        _day += n;
//        printf("%d-%2d-%2d\n", _year, _month, _day);
//    }
//    
//    return 0;
//}