#include <iostream>
#include "Rhomb.h"


int main()
{
	int V = (int('N') + int('H')) % 11;   // V = 7

	Point* points;
	int key;
	while (true)
	{
		Menu();
		std::cout << "Нажмите клавишу: ";
		std::cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
		{
			points = new Point[2];
			std::cout << "---->Вычисление длины отрезка, соединяющего две точки:\n\n";
			Input(points, 2);
			std::cout << "Длина отрезка, соединяющего две точки: " << length(points[0], points[1]) << std::endl;
			delete[] points;
			break;
		}
		case 2:
		{
			points = new Point[3];
			std::cout << "---->Принадлежат ли три точки одной прямой?\n\n";
			Input(points, 3);
			if (inLine(points))
				std::cout << "Три точки принадлежат одной прямой!\n";
			else 
				std::cout << "Три точки не принадлежат одной прямой!\n";
			delete[] points;
			break;
		}
		case 3:
		{
			int n;
			Point p1, p2;
			std::cout << "---->Нахождение двух наиболее удаленных точек в массиве.\n\n";
			std::cout << "Введите количество точек в массиве: ";
			std::cin >> n;
			points = new Point[n];
			Input(points, n);
			getFurthest(points, n, &p1, &p2);
			std::cout << "Два наиболее удаленных точек в массиве: ";
			std::cout << "(" << p1.X << "; " << p1.Y << ") и (" << p2.X << "; " << p2.Y << ")\n";
			delete[] points;

			break;
		}
		case 4:
		{
			points = new Point[4];
			Rhomb* pr;
			std::cout << "---->Проверка ли создать ромб по точкам.\n\n";
			Input(points, 4);
			pr = getRhomb(points);
			if (pr)
			{
				std::cout << "Возможно создать ромб по точкам!\n";
				pr->ShowInfo();
				delete pr;
			}
			else
			{
				std::cout << "Невозможно создать ромб по точкам!!!\n";
			}
			delete[] points;
			break;
		}
		case 5:
		{
			std::cout << "Выход из программы!!!\n";
			break;
		}
		default:
			std::cout << "Неправильная клавиша!!!\n";
			break;
		}

		if (key == 5)
			break;

		system("pause");
		system("cls");
	}

	
	return 0;
}

