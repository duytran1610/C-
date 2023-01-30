#include "City.h"

// Конструктор
City::City(string name, string nameCountry, int population, float area)
{
	name_ = name;
	name_country_ = nameCountry;
	population_ = population;
	area_ = area;
}

// Конструктор
City::City(const City& other)
{
	name_ = other.name_;
	name_country_ = other.name_country_;
	population_ = other.population_;
	area_ = other.area_;
}

// Деструктор
City::~City()
{
	
}

// Перегрузка оператора присваивания
City& City::operator = (const City& other)
{
	if (&other == this) return *this;

	name_ = other.name_;
	name_country_ = other.name_country_;
	population_ = other.population_;
	area_ = other.area_;

	return *this;
}

// Оператор вывода
ostream& operator<< (ostream& os, const City& c)
{
	os << "Город: " << c.name_ << " (" << c.name_country_ << ")\n"; 
	os << "Население: " << c.population_ << "\n";
	os << "Площадь: " << c.area_ << "\n";
	os << "--------------------------------\n\n";

	return os;
}

// Перегрузка оператора сравнения
// Для функция max_element
bool operator < (const City& c1, const City& c2)
{
	return c1.population_ < c2.population_;
}

// Функция проверки названия города
// Для функция find
bool operator == (const City& c, string name)
{
	return c.name_ == name;
}
