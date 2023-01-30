#include <iostream>
#include "Figure.h"

 // конструктор
Circle::Circle(Point p, double r)
{
	Centre = p;
	radius = (r > 0) ? r : -r;
}
 
 // статическая функция получения круга с заданным радиусом
Circle Circle::getCircle(double r)
{
	return Circle(defaultCetre, r);
}

 // Печать информацию о круге на консоль
void Circle::Show()
{
	std::cout << "----->Тип объекта: круг\n";
	std::cout << "----->Центр круга: (" << Centre.X << "; " << Centre.Y << ")\n";
	std::cout << "----->Радиус круга: " << radius << std::endl;
	std::cout << "----->Переметр: " << Perimeter() << std::endl;
	std::cout << "----->Площадь: " << Area() << std::endl;
}
 
 // Периметр круга
double Circle::Perimeter()
{
	return 2 * Pi * radius;
}

 // Площадь круга
double Circle::Area()
{
	return Pi * radius * radius;
}
 
 // деструктор
Circle::~Circle()
{

}