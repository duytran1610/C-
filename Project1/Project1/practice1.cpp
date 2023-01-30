#include<iostream>
#include "limits.h"


// Функция belongsToInterval определяет, принадлежит ли значение x заданному интервалу.
bool belongsToInterval(double, double, double);

// Функция minValue возвращает меньшее из двух целочисленных аргументов
int minValue(int, int);

// Функция minValue возвращает меньшее из двух аргументов типа float
float minValue(float, float);

// Функция order возвращает порядок числа (количество знаков).
int order(long);

// Функция getLetterCode возвращает числовое представление для любого символа.
int getLetterCode(char);

// Функция showTypeInfo выводит информацию о типах (размер, максимальное значение, минимальное значение).
void  showTypeInfo();

// Функция showMenu реализовать работу пользователя с консольным меню для выбора
void showMenu();

int main()
{
	char key[20];
	while (true)
	{
		showMenu();
		std::cout << "Нажмите клавишу: ";
		std::cin >> key;
		system("cls");

		switch (key[0])
		{
		case 'b':
		{
			double x, top, bottom;
			std::cout << "Ввод значение x: ";
			std::cin >> x;
			std::cout << "Ввод нижней и верхней границей bottom и top:\n";
			std::cin >> bottom >> top;
			if (belongsToInterval(x, top, bottom))
				std::cout << "значение x принадлежит заданному интервалу\n";
			else
				std::cout << "значение x не принадлежит заданному интервалу\n";
			break;
		}
		case 'n':
		{
			long x;
			std::cout << "Ввод значение x: ";
			std::cin >> x;
			std::cout << "порядок числа: " << order(x) << std::endl;
			break;
		}
		case 't':
		{
			showTypeInfo();
			break;
		}
		case 'c':
		{
			char ch;
			std::cout << "Ввод символа: ";
			std::cin >> ch;
			std::cout << "Кодировка символа: " << getLetterCode(ch) << std::endl;
			break;
		}
		case 'm':
		{
			float a, b;
			int x, y;

			std::cout << "Ввод двух аргументов типа float:\n";
			std::cin >> a >> b;
			std::cout << "Значение меньшее из двух аргументов: " << minValue(a, b) << std::endl;

			std::cout << "Ввод двух целочисленных аргументов:\n";
			std::cin >> x >> y;
			std::cout << "Значение меньшее из двух целочисленных аргументов: " << minValue(x, y) << std::endl;
			break;
		}
		case 'e':
		{
			std::cout << "---------------Выход из программы---------------\n";
			break;
		}
		default:
			std::cout << "неправильное нажатие клавиши!\n";
			break;
		}

		if (key[0] == 'e')
			break;

		system("pause");
		system("cls");
	}

	return 0;
}

bool belongsToInterval(double x, double top, double bottom)
{
	return (x <= top) && (x >= bottom);
}

int minValue(int a, int b)
{
	return (a < b) ? a : b;
}

float minValue(float a, float b)
{
	return (a < b) ? a : b;
}

int order(long x)
{
	if (x == 0)
		return 1;
	int n = 0;
	if (x < 0)
	{
		x = -x;
	}
	
	while (x > 0)
	{
		n++;
		x /= 10;
	}
	return n;
}

int getLetterCode(char ch)
{
	return (int)ch;
}

void  showTypeInfo()
{
	std::cout << "Типы: char, int, short, long, long long\n\n";
	std::cout << "ТИП         РАЗМЕР        МАКСИМАЛЬНОЕ ЗНАЧЕНИЕ          МИНИМАЛЬНОЕ ЗНАЧЕНИЕ\n";
	std::cout << "char          " << sizeof(char) << "		        " << CHAR_MAX << "		              " << CHAR_MIN << std::endl;
	std::cout << "int           " << sizeof(int) << "		      " << INT_MAX << "		    " << INT_MIN << std::endl;
	std::cout << "short         " << sizeof(short) << "		        " << SHRT_MAX << "		            " << SHRT_MIN << std::endl;
	std::cout << "long          " << sizeof(long) << "		      " << LONG_MAX << "		    " << LONG_MIN << std::endl;
	std::cout << "long long     " << sizeof(long long) << "         " << LLONG_MAX << "	        " << LLONG_MIN << std::endl;
}

void showMenu()
{
	std::cout << "--------------------Меню--------------------\n";
	std::cout << "Нажмите клавишу для проверки функции:\n";
	std::cout << "          b - определяет, принадлежит ли значение x заданному интервалу\n";
	std::cout << "          n - порядок числа (количество знаков)\n";
	std::cout << "          t - Информация по типам\n";
	std::cout << "          m - Минимальное значение из двух аргументов\n";
	std::cout << "          с - Кодировка символа\n";
	std::cout << "          e - Выход из программы\n";
}
