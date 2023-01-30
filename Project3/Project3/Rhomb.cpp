#include <iostream>
#include "Rhomb.h"

// Конструктор
Rhomb::Rhomb(Point points[])
{
	for (int i = 0; i < 4; i++)
		m_Vertices[i] = points[i];
}

// Вычислить периметр ромба
double Rhomb::Permeter()
{
	return 4 * LengthSideOfRhomb();
}

// вычислить площадь ромба
double Rhomb::Area()
{
	double AC = length(m_Vertices[0], m_Vertices[2]);
	double BD = length(m_Vertices[1], m_Vertices[3]);
	return AC * BD /2;
}

// печать координаты вершин ромба
void Rhomb::PrintVertices()
{
	for (int i = 0; i < 4; i++)
		std::cout << i + 1 << "-я вершина ромба: (" << m_Vertices[i].X << "; " << m_Vertices[i].Y << ")\n";
}

// длина стороны ромба
double Rhomb::LengthSideOfRhomb()
{
	return length(m_Vertices[0], m_Vertices[1]);
}

// печать информации ромба (вершины, длина стороны, площадь, периметр)
void Rhomb::ShowInfo()
{
	std::cout << "вершин ромба:\n";
	PrintVertices();
	std::cout << "длина стороны ромба: " << LengthSideOfRhomb() << std::endl;
	std::cout << "периметр ромба: " << Permeter() << std::endl;
	std::cout << "площадь ромба: " << Area() << std::endl;
}
