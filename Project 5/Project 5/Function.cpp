#include <iostream>
#include "Function.h"
#include "Figure.h"

// Меню для выбора создания объекта
void MenuInput()
{
	std::cout << "============== Меню для создания фигур ==============\n\n";
	std::cout << "1. Создание равностороннего треуголника.\n";
	std::cout << "2. Создание круга.\n";
	std::cout << "3. Создание прямоугольника.\n";
	std::cout << "4. Создание ромба.\n";
	std::cout << "5. Создание площади.\n";
	std::cout << "------------------------------------------------------------------\n";
	std::cout << "------------------------------------------------------------------\n\n\n";
}

// Меню для операторы
void Menu()
{
	std::cout << "============== МЕНЮ ==============\n\n";
	std::cout << "1. Подсчитать количество объектов каждого типа\n";
	std::cout << "2. Вывести информацию по каждому объекту\n";
	std::cout << "3. Найти четырехугольник с максимальной площадью\n";
	std::cout << "4. Выход из программы\n";
}

// ввода объектов произвольного типа
void Input(const int& N, Figure** arr)
{
	int choose, i = 0;
	MenuInput();

	while (i < N)
	{
		std::cout << "Создание объект № " << i << std::endl;
		std::cout << "Ввода твой выбор (в диапазоне значений [1;5]): ";
		std::cin >> choose;
		Point p;
		switch (choose)
		{
		case 1:
			double l;
			std::cout << "--------->Создание равностороннего треуголника\n";
			std::cin >> p;
			std::cout << "Введите расстояние от центральной точки до вершины треугольника: ";
			std::cin >> l;
			arr[i] = new EquilTriangle(p, l);
			break;
		case 2:
			double r;
			std::cout << "--------->Создание круга\n";
			std::cin >> p;
			std::cout << "Введите радиус: ";
			std::cin >> r;
			arr[i] = new Circle(p, r);
			break;
		case 3:
			double w, h;
			std::cout << "--------->Создание прямоугольника\n";
			std::cin >> p;
			std::cout << "Введите длины ширины и высоты:\nШирина: ";
			std::cin >> w;
			std::cout << "Высота: ";
			std::cin >> h;
			arr[i] = new Rectangle(p, w, h);
			break;
		case 4:
			double great, small;
			std::cout << "--------->Создание ромба\n";
			std::cin >> p;
			std::cout << "Введите длины большой диагонали и малой диагонали:\nБольшая диагональ: ";
			std::cin >> great;
			std::cout << "Малая диагональ: ";
			std::cin >> small;
			arr[i] = new Rhomb(p, great, small);
			break;
		case 5:
			double side;
			std::cout << "--------->Создание площади\n";
			std::cin >> p;
			std::cout << "Введите длину стороны: ";
			std::cin >> side;
			arr[i] = new Square(p, side);
			break;
		}

		std::cout << std::endl;
		i++;
	}
}

// подсчитать количество объектов каждого типа
void findNumberOfType(const int& N, Figure** arr)
{
	int numbers[] = { 0,0,0,0,0 };
	for (int i = 0; i < N; i++)
	{
		if (typeid(*arr[i]) == typeid(EquilTriangle))
			numbers[0]++;
		else if (typeid(*arr[i]) == typeid(Circle))
			numbers[1]++;
		else if (typeid(*arr[i]) == typeid(Rectangle))
			numbers[2]++;
		else if (typeid(*arr[i]) == typeid(Rhomb))
			numbers[3]++;
		else
			numbers[4]++;
	}

	std::cout << "1. Подсчитать количество объектов каждого типа\n\n";
	std::cout << "===========Kоличество объектов каждого типа===========\n";
	std::cout << "количество объектов тип равносторонний треугольник: " << numbers[0] << std::endl;
	std::cout << "количество объектов тип круг: " << numbers[1] << std::endl;
	std::cout << "количество объектов тип прямоугольник: " << numbers[2] << std::endl;
	std::cout << "количество объектов тип ромб: " << numbers[3] << std::endl;
	std::cout << "количество объектов тип площадь: " << numbers[4] << std::endl;
}

// вывести информацию по каждому объекту
void ShowInfo(const int& N, Figure** arr)
{
	std::cout << "2. Вывести информацию по каждому объекту\n\n";

	for (int i = 0; i < N; i++)
	{
		std::cout << "Информация о объекте № " << i << std::endl;
		arr[i]->Show();
		std::cout << std::endl;
	}
}

// найти четырехугольник с максимальной площадью
Figure* findMaxArea(const int& N, Figure** arr)
{
	std::cout << "3. Найти четырехугольник с максимальной площадью\n\n";

	double max = 0;
	int index = 0;

	for (int i = 0; i < N; i++)
	{
		Quadrilateral* q = dynamic_cast<Quadrilateral*>(arr[i]);
		if (q && max < q->Area())
		{
			max = q->Area();
			index = i;
		}
	}

	std::cout << "Четырехугольник с максимальной площадью - это объект № " << index << std::endl;

	return arr[index];
}

// Проверить возможно создать объект типа площадь и круга при помощью функции Static
void testFunctionStatic()
{
	std::cout << "Получения квадрата с заданной длиной стороны\n";
	double side;
	std::cout << "Введите длину стороны: ";
	std::cin >> side;
	Square sq = Square::GetSquare(side);
	sq.Show();

	std::cout << "\n=================================\n";

	std::cout << "Получения круга с заданным радиусом\n";
	double r;
	std::cout << "Введите радиус: ";
	std::cin >> r;
	Circle cir = Circle::getCircle(r);
	cir.Show();
}