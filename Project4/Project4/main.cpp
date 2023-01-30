#include <iostream>
#include "String.h"



int main()
{
	int V = abs(int('N') - int('H')) % 4;  // V = 2

	String str;
	int key;
	while (1)
	{
		Menu();
		std::cout << "Нажмите клавишу: ";
		std::cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
		{
			std::cout << "---->Создание экземпляра по константной строке:\n\n";
			char* s = new char[100];
			std::cout << "Ввод строк: ";
			std::cin >> s;
			str = String(s);
			std::cout << str;
			delete[] s;
			break;
		}
		case 2:
		{
			std::cout << "---->Конкатенация строк:\n\n";
			char* s = new char[100];
			std::cout<< "Ввод строк для конкатенация: ";
			std::cin >> s;
			str += String(s);
			std::cout << "Строка после объединения:\n" << str;
			delete[] s;
			break;
		}
		case 3:
		{
			std::cout << "---->Нахождение подстроки:\n\n";
			char* s = new char[100];
			std::cout << "Ввод подстроки: ";
			std::cin >> s;

			int index = 0;
			if (str.Find(String(s), index))
			{
				std::cout << "Подстрока находится на " << index << " - й позиции строки " << str.c_str() << std::endl;
			}
			else
				std::cout << "Невозможно пойти подстроки!\n";
			delete[] s;
			break;
		}
		case 4:
		{
			std::cout << "---->Удаление подстрок:\n\n";
			char* s = new char[100];
			std::cout << str;
			std::cout << "Ввод подстроки для удаление: ";
			std::cin >> s;

			str -= String(s);
			std::cout << "Строка после удаления подстроки: \n";
			std::cout << str;
			delete[] s;
			break;
		}
		case 5:
		{
			std::cout << "---->Сравнение строк:\n\n";
			char* s = new char[100];
			std::cout << "Ввод строки для сравнение c строкой " << str.c_str() << std::endl;
			std::cin >> s;
			int compare = Compare(str, String(s));
			switch (compare)
			{
			case 0:		
				std::cout << str.c_str() << " == " << s << std::endl;
				break;
			case 1:
				std::cout << str.c_str() << " > " << s << std::endl;
				break;
			default:
				std::cout << str.c_str() << " < " << s << std::endl;
				break;
			}
			delete[] s;
			break;
		}
		case 6:
		{
			std::cout << "---->Преобразование в тип const char*:\n\n";
			const char* s = static_cast<const char*>(str);
			std::cout << s << std::endl;
			break;
		}
		case 7:
		{
			std::cout << "Выход из программы!!!\n";
			break;
		}
		default:
			std::cout << "Неправильная клавиша!!!\n";
			break;
		}

		if (key == 7)
			break;

		system("pause");
		system("cls");
	}	
	
	return 0;
}