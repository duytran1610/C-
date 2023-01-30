#pragma once
//  тип Point
struct Point;

//  тип «Ромб»
class Rhomb;

// Меню
void Menu();

// Введите координаты n точек
void Input(Point* points, int n);

// Вычисление длины отрезка, соединяющего две точки
double length(Point p1, Point p2);

// Принадлежат ли три точки одной прямой?
bool inLine(Point points[]);

//  Нахождение двух наиболее удаленных точек в массиве
void getFurthest(Point* points, int size, Point* p1, Point* p2);

// Создание Ромб по точкам
Rhomb* getRhomb(Point* points);


struct Point
{
	double X, Y;
};

class Rhomb
{
	Point m_Vertices[4];                     // вершины ромба
public:
	Rhomb(Point points[]);                   // Конструктор
	double Permeter();                       // Вычислить периметр ромба
	double Area();                           // вычислить площадь ромба
	void PrintVertices();                    // печать координаты вершин ромба
	double LengthSideOfRhomb();              // длина стороны ромба
	void ShowInfo();                         // печать информации ромба (вершины, длина стороны, площадь, периметр)
};
