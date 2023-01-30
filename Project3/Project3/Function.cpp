#include <iostream>
#include "Rhomb.h"

// Вычисление длины отрезка, соединяющего две точки
double length(Point p1, Point p2)
{
	double dx = p1.X - p2.X;
	double dy = p1.Y - p2.Y;
	return sqrt(dx * dx + dy * dy);
}

// Принадлежат ли три точки одной прямой?
bool inLine(Point points[])
{
	double mul1 = (points[0].X - points[1].X) * (points[0].Y - points[2].Y);
	double mul2 = (points[0].X - points[2].X) * (points[0].Y - points[1].Y);

	// Если принадлежат три точки одной прямой, то (вектор AB) = k*(вектор АС). т.е. (x0 -x1)(y0 -y2) = (x0-x2)(y0-y1)
	return  mul1 == mul2;
}

//  Нахождение двух наиболее удаленных точек в массиве
void getFurthest(Point* points, int size, Point* p1, Point* p2)
{
	double maxLength = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			double l = length(points[i], points[j]);
			if (l > maxLength)
			{
				maxLength = l;
				*p1 = points[i];
				*p2 = points[j];
			}
		}
	}
}

// Создание Ромб по точкам
Rhomb* getRhomb(Point* points)
{
	double leng[4][4];
	bool check = false;
	int m, n, k, sum = 6;
	Point m_points[4];

	// Вычисление длины отрезков, соединенных из 4 точек
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			leng[i][j] = length(points[i], points[j]);
			leng[j][i] = leng[i][j];
			if (!leng[i][j])       // Если points[i] и points[j] совпадают
				return 0;
		}
	}
	for (m = 1; m < 3; m++)
	{
		for (n = m + 1; n < 4; n++)
		{
			k = sum - m - n;

			// Ромб OMKN если OM = ON , KM = OM, KN = ON
			if (leng[0][m] == leng[0][n] && leng[k][m] == leng[0][m] && leng[k][n] == leng[0][n])
			{
				m_points[0] = points[0];
				m_points[1] = points[m];
				m_points[2] = points[k];
				m_points[3] = points[n];
				return new Rhomb(m_points);
			}
		}
	}

	return 0;
}

// Меню
void Menu()
{
	std::cout << "--------------------Меню--------------------\n";
	std::cout << "Нажмите клавишу для следующих операций:\n";
	std::cout << "1. Вычисление длины отрезка, соединяющего две точки.\n";
	std::cout << "2. Принадлежат ли три точки одной прямой?.\n";
	std::cout << "3. Нахождение двух наиболее удаленных точек в массиве.\n";
	std::cout << "4. Проверка ли создать ромб по точкам.\n";
	std::cout << "5. Выход из программы\n";
}

// Введите координаты n точек
void Input(Point* points, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Введите координаты " << i + 1 << "- й точки : \n";
		std::cout << "X = ";
		std::cin >> points[i].X;
		std::cout << "Y = ";
		std::cin >> points[i].Y;
	}
	std::cout << "***********-----------**************\n";
}