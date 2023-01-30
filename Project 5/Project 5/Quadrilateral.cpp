#include <iostream>
#include "Figure.h"
 
// деструктор
Quadrilateral::~Quadrilateral()
{

}

// ромб
// конструктор
Rhomb::Rhomb(Point p, double g, double s) :Quadrilateral(p)
{
	greatDiagonal = (g > 0) ? g : -g;
	smallDiagonal = (s > 0) ? s : -s;
}

// Печать информацию о ромбе на консоль
void Rhomb::Show()
{
	std::cout << "----->Тип объекта: ромб\n";
	std::cout << "----->Центр: (" << Centre.X << "; " << Centre.Y << ")\n";
	std::cout << "----->Большая диагональ: " << greatDiagonal << std::endl;
	std::cout << "----->Mалая диагональ: " << smallDiagonal << std::endl;
	std::cout << "----->Переметр: " << Perimeter() << std::endl;
	std::cout << "----->Площадь: " << Area() << std::endl;
}
 
 // Площадь ромба
double Rhomb::Area()
{
	return 0.5 * greatDiagonal * smallDiagonal;
}

 // Периметр ромба
double Rhomb::Perimeter()
{
	return 4 * getSide();
}

 // Сторона ромба
double Rhomb::getSide()
{
	double dx = smallDiagonal * smallDiagonal;
	double dy = greatDiagonal * greatDiagonal;
	return 0.5 * sqrt(dx + dy);
}

// прямоугольник
// конструктор
Rectangle::Rectangle(Point p, double w, double h) : Quadrilateral(p)
{
	Width = (w > 0) ? w : -w;
	Height = (h > 0) ? h : -h;
}

// Печать информацию о прямоугольнике на консоль
void Rectangle::Show()
{
	std::cout << "----->Тип объекта: прямоугольник\n";
	std::cout << "----->Центр (пересечение двух диагоналей): (" << Centre.X << "; " << Centre.Y << ")\n";
	std::cout << "----->Ширина: " << Width << std::endl;
	std::cout << "----->Высота: " << Height << std::endl;
	std::cout << "----->Переметр: " << Perimeter() << std::endl;
	std::cout << "----->Площадь: " << Area() << std::endl;
}

// Площадь прямоугольника
double Rectangle::Area()
{
	return Width * Height;
}

// Периметр прямоугольника
double Rectangle::Perimeter()
{
	return 2 * (Width + Height);
}

// площадь
// конструктор
Square::Square(Point p, double x) : Rectangle(p, x, x){}

// Сторона площади
double Square::getSide()
{
	return Width;
}

// статическая функция получения квадрата с заданной длиной стороны
Square Square::GetSquare(double x)
{
	return Square(defaultCetre, x);
}

// Печать информацию о площади на консоль
void Square::Show()
{
	std::cout << "----->Тип объекта: площадь\n";
	std::cout << "----->Центр : (" << Centre.X << "; " << Centre.Y << ")\n";
	std::cout << "----->Сторона: " << getSide() << std::endl;
	std::cout << "----->Переметр: " << Perimeter() << std::endl;
	std::cout << "----->Площадь: " << Area() << std::endl;
}