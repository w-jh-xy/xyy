#include<stdio.h>

void* my_memmove(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else  //�ռ��ص�
	{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return (ret);
}



char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	
	char* stra = (char*)str1;
	char* strb = (char*)str2;
	char* s1 = NULL;
	if (*str2 == '\0')
			return NULL;
	while (*str1)
	{
		s1 = stra;
		strb = str2;
		while (*s1 && *strb && (*s1 == *strb)) //���str1��str2���������������
		{
			s1++;
			strb++;
		}
		if (*strb == '\0')  //���str2������������str1��ͬ���򷵻�str1��λ��
			return stra;
		stra++;  //���str2û�н������в���ͬ������ʱ��str1����
	}   //���str1��������û���ҵ���str2��ͬ������
}

char* my_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* s1 = dest;
	while (*s1)  //�ҵ�destĩβ��\0���ڴ˲���src
	{
		s1++;
	}
	while (*src)
	{
		*s1 = *src;
		s1++;
		src++;
	}
	return dest;
}

char* my_strncat(char* dest, const char* src,size_t n)
{
	assert(dest);
	assert(src);
	char* s1 = dest;
	while (*dest)  //�ҵ�destĩβ��\0���ڴ˲���src
	{
		dest++;
	}
	while (n--)
	{
		if (*src == '\0')
			break;
		else
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	return s1;
}

int my_strcmp(const char* str1, const char* str2)
{
	while (*str1++ == *str2++)
	{
		if (*str1 == '\0')
			return 0;
	}
	return (int)(*str1 - *str2);
}


char* my_strcpy(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* s = dest;
	while (*src) 
	{
		*s = *src;
		s++;
		src++;
	}
	return dest;
}

char* my_strncpy(char* dest, const char* src, size_t n)
{
	assert(dest);
	assert(src);
	char* s = dest;
	while (n--)
	{
		if (*src == '\0')
			break;
		*dest = *src;
		dest++;
		src++;
	}
	return s;
}

int my_strlen(const char* str)
{
	assert(str);
	char* s = str;
	while (*s)
	{
		s++;
	}
	return s - str - 1;
}

unsigned int my_strlen1(const char* str)
{
	asseert(str);
	if (*str == '\0')
		return 0;
	return 1 + my_strlen1(str + 1);
}