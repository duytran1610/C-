#pragma once

#include <string>
#include <iostream>

using namespace std;

class City
{
	string name_;            // name of city
	string name_country_;    // belong to the country
	int population_;         // population
	float area_;             // area
public:
	City(string name, string name_country, int population, float area);
	City(const City& other);
	~City();

	string get_name() const { return name_; }
	string get_nameCountry() const { return name_country_; }
	int get_population() const { return population_; }
	float get_area() const { return area_; }
	
	// Перегрузка оператора присваивания
	City& operator = (const City& other);

	// Перегрузка оператора вывода
	friend ostream& operator<< (ostream& os, const City& c);

	// Перегрузка оператора сравнения
	friend bool operator < (const City& c1, const City& c2);

	// Функция проверки названия города
	friend bool operator == (const City& c, string name);
};