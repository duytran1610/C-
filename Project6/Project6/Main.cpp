#include <iostream>
#include <vector>
#include <string>
#include "City.h"
#include "Function.h"

using namespace std;

int main()
{
	int V = (int('N') + int('H')) % 7;            // V = 3
	
	// список городов
	vector<City> v;

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
			cout << "------->Добавление город в список.\n\n";
			AddCity(v);
			break;
		case 2:
		{
			string name;

			cout << "------->Удаление город из списка.\n\n";
			cout << "Введите название города, который хотите удалить из списка: ";
			cin >> name;

			if (DeleteCity(v, name))
			{
				cout << "Удалить успешно!\n";
				cout << "Список городов после удаления:\n";
				ShowInfoCitys(v);
			}				
			else
				cout << "Удалить не успешно!\n";
			break;
		}
		case 3:
			cout << "------->Распечение информацию обо всех городах в списке.\n\n";
			ShowInfoCitys(v);
			break;
		case 4:
			cout << "------->Сортировка городов в списке по приросту населения.\n\n";
			SortCitys(v);
			cout << "Список городов после сортировки:\n\n";
			ShowInfoCitys(v);
			break;
		case 5: 
		{
			cout << "------->Найдите город с самым большим населением.\n\n";
			City c = CityMaxPopulation(v);
			cout << "Информация о городе с самым большим населением в списке: \n";
			cout << c;
			break;
		}
		case 6:
			cout << "------->Подсчитать общую численность населения городов в списке.\n\n";
			cout << "Общая численность населения городов в списке: " << SumPopulation(v) << endl;
			break;
		case 7:
			cout << "------->Найти информацию о городе в списке.\n\n";
			FindCityByName(v);
			break;
		case 8:
			cout << "------->Найдите город, площадь которого больше заданного числа.\n\n";
			FindCityByArea(v);
			break;
		case 9:
			std::cout << "Выход из программы!!!\n";
			break;
		}

		if (key == 9)
			break;

		system("pause");
		system("cls");
	}



	return 0;
}