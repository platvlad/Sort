#include <iostream>
#include "string.h"
using namespace std;
const int MinCapacity = 4;
String :: String( char *str)
{
        my_capacity = MinCapacity;
		my_size = strlen(str);
		while (my_capacity < (my_size + 1))
		{
			my_capacity *= 2;
		}
		my_str = new char[my_capacity];
		for (int i = 0; i < my_size; ++i)
			my_str[i] = str[i];
}
String :: String()
{
	my_size = 0;
	my_capacity = MinCapacity;
	my_str = NULL;
}
String :: ~String()
{
	delete [] my_str;
}
int String :: size()
{
	return my_size;
}
int String :: capacity()
{
	return my_capacity;
}
bool String :: empty()
{
	return (my_size == 0);
}
void String :: clear()
{
	delete [] my_str;
	my_size = 0;
	my_capacity = MinCapacity;
}
String :: String (const String &obj)
{
	my_size = obj.my_size;
	my_capacity = obj.my_capacity;
	my_str = new char[my_capacity];
	for (int i = 0; i <= my_size; ++i)
	{
		my_str[i] = obj.my_str[i];
	}
}
String & String :: operator = (const String &obj)
{
	my_size = obj.size;
	my_capacity = obj.capacity;
	my_str = new char[my_capacity];
	for (int i = 0; i <= my_size; ++i)
	{
		my_str[i] = obj.my_str[i];
	}
	return *this;
}
void String :: push_back (char c)
{
	
	if (my_size == (my_capacity - 1))
		my_capacity *= MinCapacity;
	char * r = new char[my_capacity];
	for (int i = 0; i < my_size; ++i)
	{
		r[i] = my_str[i];
	}
	r[my_size] = c;
	r[my_size + 1] = '\0';
    ++my_size;
	delete [] my_str;
	my_str = r;
}
void String :: pop_back ()
{
	
	delete &my_str[my_size-1];
	if ((my_capacity > 2*my_size) && (my_capacity > MinCapacity))
	{
		my_capacity /= 2;
		char *r = new char[my_capacity];
		for (int i = 0; i <= my_size-1; ++i)
		{
			r[i] = my_str[i];
		}
		delete [] my_str;
		my_str = r;
	}
	--my_size;

}
void String :: insert(int pos, const char *str)
{
	int n = strlen(str);
	while (my_capacity < (my_size + n +1))
	{
		my_capacity *= 2;
	}
	char * r = new char[my_capacity];
	for (int i = 0; i < pos; ++i)
	{
		r[i] = my_str[i];
	}
	for (int i = 0; i < n; ++i)
	{
		r[pos + i] = str[i];
	}
	for (int i = pos; i <= my_size; ++i)
	{
		r[pos + n + i] = my_str[i];
	}
	delete [] my_str;
	my_str = r;
	my_size += n;
}
void String :: erase(int pos, int len = 1)
{
	while ( my_capacity >= 2*(my_size - len + 1) && (my_capacity > MinCapacity))
	{
		my_capacity /= 2;
	}
	char *r = new char[my_capacity];
	for (int i = 0; i < pos; ++i)
	{
		r[i] = my_str[i];
	}
	for (int i = pos + len; i <= my_size; ++i)
	{
		r[i - len] = my_str[i];
	}
	delete [] my_str;
	my_str = r;
	my_size -= len;
}

String  String :: operator + (String s)  //что-то тут не так, возможно
{
	String P;
	P.my_size = s.my_size + my_size;
	int n = strlen(s.my_str);
	P.my_capacity = my_capacity;
	while (P.my_capacity < (my_size + n +1))
	{
		P.my_capacity *= 2;
	}
	//char *r = new char[my_capacity];
	delete [] P.my_str;
	P.my_str = new char[my_capacity];
	for (int i = 0; i < my_size - s.my_size; ++i)
	{
		P.my_str[i] = my_str[i];
	}
	for (int i = my_size - s.my_size; i <= my_size; ++i)
	{
		P.my_str[i] = s.my_str[i - my_size];
	}
	return P;
}

String String :: operator += (String s)
{
	while (my_capacity < (my_size + s.my_size + 1))
	{
		my_capacity *= 2;
	}
	char * r = new char[my_capacity];
	for (int i = 0; i < my_size; ++i)
	{
		r[i] = my_str[i];
	}
	for (int i = my_size; i <= (my_size + s.my_size); ++i)
	{
		r[i] = s.my_str[i - my_size];
	}
	delete [] my_str;
	my_str = r;
	return *this;
}

char String :: operator [] (int n)
{
	return my_str[n];
}

String :: String (const String &obj)
{
	my_size = obj.my_size;
	my_capacity = obj.my_capacity;
	my_str = new char[my_capacity];
	for (int i = 0; i <= my_size; ++i)
	{
		my_str[i] = obj.my_str[i];
	}
}
String & String :: operator =(const String &obj)
{
	my_size = obj.my_size;
	my_capacity = obj.my_capacity;
	my_str = new char[my_capacity];
	for (int i = 0; i <= my_size; ++i)
	{
		my_str[i] = obj.my_str[i];
	}
	return *this;
}
