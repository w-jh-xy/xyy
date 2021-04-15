#include<iostream>
//#include<vld.h>
#include<assert.h>
#include<time.h>
#include<windows.h>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = m[month];
		if (month == 2 && (isleapyear(year)))
		{
			day += 1;
		}
		return day;
	}

	bool isleapyear(int year)    //判断是否为闰年
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (judgeDate())
			//cout << "非法日期" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	bool judgeDate()  //判断是否为合法日期
	{
		return (_year < 1 || ((_month < 1) || _month > 12) || (_day < 1) ||
			_day>GetMonthDay(_year, _month));
	}

	// 拷贝构造函数
    // d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 析构函数
	~Date()
	{

	}

	//Date& opeator<<(int year, int month, int day)
	//{

	//}

	// 日期+=天数
	Date& operator+=(int day)
	{
		int mday = GetMonthDay(_year, _month);
		while (_day + day > mday)
		{
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
			day -= mday;
			mday = GetMonthDay(_year, _month);
		}
		_day += day;
		return *this;
	}

	// 日期+天数
	Date operator+(int day)
	{
		Date tmp = *this;
		int mday = GetMonthDay(tmp._year, tmp._month);
		while (tmp._day + day > mday)
		{
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
			day -= mday;
			mday = GetMonthDay(tmp._year, tmp._month);
		}
		tmp._day += day;
		return tmp;
	}

	// 日期-天数
	Date operator-(int day)
	{
		Date tmp = *this;
		while (day > 0 && day >= tmp._day)
		{
			day -= tmp._day;
			 tmp._month--;
			 if (tmp._month < 1)
			 {
				 tmp._year--;
				 tmp._month = 12;
			 }
			 tmp._day = GetMonthDay(tmp._year, tmp._month); 
		}
		tmp._day -= day;
		return tmp;
	}

	// 日期-=天数
	Date& operator-=(int day)
	{
		while (day > 0 && day >= _day)
		{
			day -= _day;
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		_day -= day;
		return *this;
	}

	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	// 后置--
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		return ((_year > d._year) || ((_year == d._year) && (_month > d._month)) || 
			((_year == d._year) && (_month == d._month) && (_day > d._day)));
	}

	// ==运算符重载
	bool operator==(const Date& d)
	{
		return ((d._year == _year) && (d._month == _month) && (d._day == _day));
	}

	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		return ((_year >= d._year) || ((_year >= d._year) && (_month >= d._month)) ||
			((_year >= d._year) && (_month >= d._month) && (_day >= d._day)));
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++min;
			++day;
		}
		return day * flag;
	}

	//蔡勒公式
	int week()
	{
		int w = 0;
		int y = _year;
		int m = _month;
		if (m == 1 || m == 2)
		{
			m = _month + 12;
			y = _year - 1;
		}
		w = _day + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400;
		w = w % 7 + 1;
		return w;
	}

private:

	int _year;

	int _month;

	int _day;

};


int main()
{
	Date d1(2021, 4, 26);
	Date d2(2021, 3, 26);
	//d2 = d1 - 106;
	//d1 -= 106;
	int x = d1 < d2;
	cout << x << endl;
	return 0;
}







