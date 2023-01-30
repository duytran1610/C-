#pragma once
#include <iostream>
#include "String.h"

// Функция для Сравнение строк
int Compare(const String& str1, const String& str2)
{
	const char* p1 = str1.m_Str;
	const char* p2 = str2.m_Str;

	while (*p1 == *p2)
	{
		p1++;
		p2++;
	}

	if (*p1 == *p2)
		return 0;
	else if (*p1 > *p2)
		return 1;
	else
		return -1;
}

// Перегрузку операция <
bool operator<(const String & str1, const String& str2)
{
	int check = Compare(str1, str2);
	return check == -1;
}

// Перегрузку операция ==
bool operator==(const String& str1, const String& str2)
{
	int check = Compare(str1, str2);
	return check == 0;
}

// Перегрузку операция >
bool operator>(const String& str1, const String& str2)
{
	int check = Compare(str1, str2);
	return check == 1;
}

// Перегрузку операция <<
std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << "Информация о данных:\nCтрока: " << s.m_Str << "\nРазмер: " << s.m_Size << "\n";
	return os;
}

// Menu
void Menu()
{
	std::cout << "--------------------Меню--------------------\n";
	std::cout << "Нажмите клавишу для следующих операций:\n";
	std::cout << "1. Создание экземпляра по константной строке.\n";
	std::cout << "2. Конкатенация строк.\n";
	std::cout << "3. Нахождение подстроки.\n";
	std::cout << "4. Удаление подстрок.\n";
	std::cout << "5. Сравнение строк.\n";
	std::cout << "6. Преобразование в тип const char*.\n";
	std::cout << "7. Выход из программы\n";
}