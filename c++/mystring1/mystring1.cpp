#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<deque>
#include<string.h>
#include<assert.h>

namespace wjh
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str)+1];
			strcpy(_str, str);
		}

		string(const string& s):_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s); //借助构造函数
				swap(_str, tmp._str);
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

		static void swap(char* s1, char* s2)
		{
			std::swap(s1, s2);

		}

	private:
		char* _str;
	};



//class string
//{
//public:
//	string(const char* str = "") //构造函数，构造一个
//	{
//		if (str == nullptr)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);  //为什么不用memcpy()
//	}
//
//	string(const string& s)
//	{
//		_str = new char[strlen(_str) + 1];
//		strcpy(_str, s._str);
//	}
//
//	string& operator=(const string& s)
//	{
//		if (this != &s)
//		{
//			delete[]_str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//
//	~string()
//	{
//		delete[]_str;
//		_str = nullptr;
//	}
//private:
//	char* _str;
//};

}

void main()
{
	wjh::string s1 = "abc";
	wjh::string s2;
	s2 = s1;
}