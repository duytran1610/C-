#pragma once
#include <iostream>

 // Точка
struct Point
{
	double X, Y;

	friend std::istream& operator >> (std::istream& is, Point& p)
	{
		std::cout << "Введите координаты центральной точки:\nX = ";
		is >> p.X;
		std::cout << "Y = ";
		is >> p.Y;
		return is;
	}
};

 // Фигура
class Figure
{
protected:
	Point Centre;                        // Центральная точка
public:
	virtual void Show() = 0;             // Печать информацию о объекте на консоль
	virtual double Area() = 0;           // Площадь фигуры
	virtual double Perimeter() = 0;      // Периметр фигуры

	// деструктор
	virtual ~Figure(){}
};

// равносторонний треугольник
class EquilTriangle : public Figure
{
	static constexpr double sqrt_3 = 1.732;      // sqrt(3)
	double length;   // расстояние от центральной точки до вершины треугольника
public:
	// конструктор
	EquilTriangle(Point, double);         

	double getSide();                     // Вернуть сторона треугольника

	virtual void Show();
	virtual double Area();
	virtual double Perimeter();

	// деструктор
	virtual ~EquilTriangle();
};

 // круг
class Circle : public Figure
{
	static Point defaultCetre;                 // Центральная точка по умолчанию
	static constexpr double Pi = 3.14;       
	double radius;                             // радиус круга
public:
	// конструктор
	Circle(Point, double);  

	static Circle getCircle(double);         // статическая функция получения круга с заданным радиусом

	virtual void Show();
	virtual double Area();
	virtual double Perimeter();

	// деструктор
	virtual ~Circle();
};
 
 // четырехугольник
class Quadrilateral : public Figure
{
public:
	// конструктор
	Quadrilateral(Point p)
	{
		Centre = p;
	}

	// деструктор
	virtual ~Quadrilateral();
};
 
 // ромб
class Rhomb : public Quadrilateral
{
	double greatDiagonal;    // большая диагональ
	double smallDiagonal;    // малая диагональ
public:
	Rhomb(Point, double, double);

	virtual void Show();
	virtual double Area();
	virtual double Perimeter();

	double getSide();       // Вернуть сторона ромба
};

 // прямоугольник
class Rectangle : public Quadrilateral
{
protected:
	double Width, Height;      // ширина, высота
public:
	Rectangle(Point, double, double);

	virtual void Show();
	virtual double Area();
	virtual double Perimeter();
};

 // площадь
class Square : public Rectangle
{
	static Point defaultCetre;            // Центральная точка по умолчанию
public:
	Square(Point, double);

	static Square GetSquare(double);      // статическая функция получения квадрата с заданной длиной стороны
	double getSide();

	virtual void Show();
};
