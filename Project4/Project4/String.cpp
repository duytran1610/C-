#include <iostream>
#include "String.h"
#include "Visual Leak Detector/include/vld.h"

// конструктор
String::String() :m_Str(nullptr), m_Size(0){}

// конструктор по константной строке (const char*)
String::String(const char* str):String()
{
	if (strlen(str) > 0)
	{
		m_Size = strlen(str);
		m_Str = new char[m_Size + 1];
		for (int i = 0; i <= m_Size; i++)
			m_Str[i] = str[i];
	}
}

// конструктор копирования
String::String(const String& other):String()
{
	if (other.m_Size > 0)
	{
		m_Size = other.m_Size;
		m_Str = new char[m_Size + 1];
		for (int i = 0; i <= m_Size; i++)
			m_Str[i] = other.m_Str[i];
	}
}

// метод получит значение поля m_Size
int String::getSize() const
{
	return m_Size;
}

// метод получит значение поля m_Str
const char* String::c_str()
{
	return m_Str;
}

// операция присваивания
String& String::operator=(const String& other)
{
	if (&other == this) return *this;
	delete[] m_Str;

	m_Size = other.m_Size;
	if (m_Size == 0)
	{
		m_Str = nullptr;
		return *this;
	}

	m_Str = new char[m_Size + 1];
	for (int i = 0; i <= m_Size; i++)
		m_Str[i] = other.m_Str[i];

	return *this;
}

// операция преобразование в тип const char*
String::operator const char* ()
{
	return m_Str;
}

// опрация конкатенация строк
String& String::operator+=(const String& other)
{
	if (!other.m_Size) return *this;

	int i = m_Size;
	m_Size += other.m_Size;
	const char* str = m_Str;
	m_Str = new char[m_Size + 1];
	StrCopy(str, i);
	
	for (int j = i; j <= m_Size; j++)
		m_Str[j] = other.m_Str[j - i];
	m_Str[m_Size] = '\0';
	delete[] str;

	return *this;
}

// операция удаление подстрок
String& String::operator-=(const String& other)
{
	if (other.m_Size == 0)
		return *this;

	int index = 0;
	if (Find(other, index))
	{
		m_Size -= other.m_Size;
		const char* str = m_Str;
		m_Str = new char[m_Size + 1];
		StrCopy(str, index);

		for (int i = index; i <= m_Size; i++)
		{
			m_Str[i] = str[i + other.m_Size];
		}
		delete[] str;
	}
	else
		std::cout << "-------->Невозможно найти подстрок, чтобы удалит!<---------\n\n";

	return *this;
}

// деструктор
String::~String()
{
	delete[] m_Str;
}

// операция копи данный
void String::StrCopy(const char* in, int size)
{
	int i = 0;
	char* out = m_Str;

	while (i++ < size)
	{
		*out++ = *in++;
	}
}

// операция нахождение подстроки
bool String::Find(const String& source, int& index)
{
	if (m_Size < source.m_Size)
		return 0;
	if (source.m_Size == 0)
		return 1;

	const char* p_Str = m_Str;
	const char* p_Source = source.m_Str;
	int n = m_Size - source.m_Size;

	for (int i = 0; i <= n; i++)
	{
		int j = 0;
		while (p_Str[i + j] == p_Source[j])
		{
			if (j == source.m_Size - 1)
			{
				index = i;
				return 1;
			}
			j++;
		}
	}

	return 0;
}