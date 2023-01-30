#include "Function.h"



int SumPopulation(vector<City> v_Citys)
{
	if (v_Citys.size() > 0)
	{
		int sum;
		vector<int> v(v_Citys.size());

		transform(v_Citys.begin(), v_Citys.end(), v.begin(), [](const City& c) {return c.get_population(); });
		sum = accumulate(v.begin(), v.end(), 0);

		return sum;
	}

	return 0;
}

City CityMaxPopulation(vector<City> v_Citys)
{
	if (v_Citys.size() > 0)
	{
		auto it = max_element(v_Citys.begin(), v_Citys.end());	
			return *it;
	}
	return City("", "", 0, 0);
}

void SortCitys(vector<City>& v_Citys)
{
	sort(v_Citys.begin(), v_Citys.end(), [](const City& c1, const City& c2) {return c1.get_population() < c2.get_population(); });	
}

void FindCityByArea(vector<City> v_Citys)
{
	float area;

	cout << "Введите площадь: ";
	cin >> area;

	auto it = find_if(v_Citys.begin(), v_Citys.end(), [area](const City& c) {return c.get_area() >= area; });

	if (it != v_Citys.end())
	{
		cout << "Информация о городах площадью более " << area << ":\n";
		cout << *it;
	}		
	else
		cout << "Не могу найти город, соответствующий вашим требованиям!\n";
}

void FindCityByName(vector<City> v_Citys)
{	
	string name;
	
	cout << "Введите название города, информацию о котором вы хотите найти: ";
	cin >> name;

	auto it = find(v_Citys.begin(), v_Citys.end(), name );

	if (it != v_Citys.end())
		cout << *it;
	else
		cout << "Не могу найти этот город в списке!\n";
}

void Menu()
{
	std::cout << "--------------------Меню--------------------\n";
	std::cout << "Нажмите клавишу для следующих операций:\n";
	std::cout << "1. Добавление город в список.\n";
	std::cout << "2. Удаление город из списка.\n";
	std::cout << "3. Распечение информацию обо всех городах в списке.\n";
	std::cout << "4. Сортировка городов в списке по приросту населения.\n";
	std::cout << "5. Найдите город с самым большим населением.\n";
	std::cout << "6. Подсчитать общую численность населения городов в списке.\n";
	std::cout << "7. Найти информацию о городе в списке.\n";
	std::cout << "8. Найдите город, площадь которого больше заданного числа.\n";
	std::cout << "9. Выход из программы\n";
}

void AddCity(vector<City>& v_Citys)
{
	string name;
	string name_country;
	int population;
	float area;

	cout << "Введите название города: ";
	cin >> name;

	cout << "Введите название страны: ";
	cin >> name_country;

	cout << "Введите население города (количество): ";
	cin >> population;

	cout << "Введите площадь города: ";
	cin >> area;

	v_Citys.push_back(City(name, name_country, population, area));
}

void ShowInfoCitys(vector<City> v_Citys)
{
	if (v_Citys.size() > 0)
		for_each(v_Citys.begin(), v_Citys.end(), [](const City& c) {cout << c; });
	else
		cout << "Список городов пуст!\n";
}

bool DeleteCity(vector<City>& v_Citys, string name)
{
	if (v_Citys.size() > 0)
	{
		for (int i = 0; i < v_Citys.size(); i++)
		{
			if (v_Citys[i].get_name() == name)
			{
				v_Citys.erase(v_Citys.begin() + i);
				return true;
			}
		}
	}
	else
	{
		cout << "Список городов пуст!\n";
	}

	return false;
}