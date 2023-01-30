#include <iostream>
#include "Figure.h"
#include "function.h"

Point Circle::defaultCetre{ 0,0 };
Point Square::defaultCetre{ 0,0 };

int main()
{
	int V = (int('G') + int('U')) % 8;    // V = 4
	const int N = 12;

	Figure** arr = new Figure * [N];
	Figure* p_max = 0;
	Input(N, arr);

	system("pause");
	system("cls");

	int key;
	while (1)
	{
		Menu();
		std::cout << "Нажмите клавишу: ";
		std::cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
			findNumberOfType(N, arr);
			break;
		case 2:
			ShowInfo(N, arr);
			break;
		case 3:
			p_max = findMaxArea(N, arr);
			p_max->Show();
			break;
		case 4:
			std::cout << "Выход из программы!!!\n";
			break;
		}

		if (key == 4)
			break;

		system("pause");
		system("cls");
	}

	testFunctionStatic();

	// освобождение динамической памяти.
	for (int i = 0; i < N; i++)
		delete arr[i];
	delete[] arr;
	
	return 0;
}