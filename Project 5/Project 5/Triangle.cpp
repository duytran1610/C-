#include <iostream>
#include "Figure.h"

 // Конструктор
EquilTriangle::EquilTriangle(Point p, double l)
{
	Centre = p;
	length = (l > 0) ? l : -l;
}

 // Печать информацию о треугольнике на консоль
void EquilTriangle::Show()
{
	std::cout << "----->Тип объекта: равносторонний треугольник\n";
	std::cout << "----->Сторона треугольника: " << getSide() << std::endl;
	std::cout << "----->Переметр: " << Perimeter() << std::endl;
	std::cout << "----->Площадь: " << Area() << std::endl;
}

 // Вернуть сторона треугольника
double EquilTriangle::getSide()
{
	return sqrt_3 * length;
}

 // Периметр треугольника
double EquilTriangle::Perimeter()
{
	return 3 * getSide();
}
 
 // Площадь треугольника
double EquilTriangle::Area()
{
	double area = 0.5 * sin(120) * pow(getSide(), 2);
	return 3 * area;
}
 
 // деструктор
EquilTriangle::~EquilTriangle()
{
	
}