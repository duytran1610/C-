#include <iostream>
#include "matrix.h"


int main()
{
	int V = int('N') % 8;     // вариант 6
	int** pp, * p;
	int N, key;

	std::cout << "введите размер матрицы: ";
	std::cin >> N;

	pp = new int* [N];
	pp[0] = new int[N * N];
	p = pp[0];
	for (size_t i = 1; i != N; i++)
	{
		pp[i] = pp[i - 1] + N;
	}
	for (size_t i = 0; i < N * N; i++)
	{
		*p++ = rand() % 10;
	}
	p = 0;
	

	while (true)
	{
		ShowMenu();
		std::cout << "Нажмите клавишу: ";
		std::cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
		{
			OutputMatrix(pp, N, p);
			break;
		}
		case 2:
		{
			IntputMatrix(pp, N, p);
			break;
		}
		case 3:
		{ 
			// cin >> ..
			unsigned int i, j;
			int res = 0;
			p = pp[0];
			while (true)
			{
				std::cout << "Умножение строки : ";
				std::cin >> i;
				std::cout << "на столбец: ";
				std::cin >> j;
				if (i >= N || j >= N)
				{
					std::cout << "Нужно ввести значение строки и столбца между на интервале [0; " << N << "]!\n\n";
				}
				else
					break;
			}
			// Вывод матрицы на консоль
			std::cout << "--------Matrix----------\n";
			for (int i = 0; i < N * N; i++)
			{
				if (i % N == 0)
				{
					std::cout << std::endl;
				}
				std::cout << *p++ << "\t";
			}
			p = pp[0];
			std::cout << "\n\n\n";

			res = OperatorMatrix(N, p, i, j);
			std::cout << "=========> Умножение строки на столбец: " << res << std::endl;

			p = 0;
			break;
		}
		case 4:
		{
			CreateNewMatrix(pp, N, p);
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

	Freeing(pp, N);

	return 0;
}

void ShowMenu()
{
	std::cout << "--------------------Меню--------------------\n";
	std::cout << "Нажмите клавишу для следующих операций при работе матицами:\n";
	std::cout << "1. Вывод матрицы на консоль.\n";
	std::cout << "2. Ввод матрицы построчно с консоли.\n";
	std::cout << "3. Операция с матрицами или векторами (варианта 6: Умножение строки на столбец).\n";
	std::cout << "4. Создать новое измерение для матрицы со значениями по умолчанию.\n";	
	std::cout << "5. Выход из программы\n";
}
void CreateNewMatrix(int**& pp, int& N, int* p)
{
	Freeing(pp, N);
	std::cout << "введите новый размер матрицы: ";
	std::cin >> N;

	pp = new int* [N];
	pp[0] = new int[N * N];
	p = pp[0];
	for (size_t i = 1; i != N; i++)
	{
		pp[i] = pp[i - 1] + N;
	}
	for (size_t i = 0; i < N * N; i++)
	{
		*p++ = rand() % 10;
	}
}

void IntputMatrix(int** pp, int N, int* p)
{
	int i;
	std::cout << "Ввод матрицы построчно с консоли:\n";

	for (i = 0, p = pp[0]; i < N * N; i++, p++)
	{
		if (i % N == 0)
		{
			std::cout << "введите значение элементов строки: " << i / N << std::endl;
		}
		std::cin >> *p;
	}
}

void OutputMatrix(int** pp, int N, int* p)
{
	int i;
	std::cout << "Вывод матрицы (или вектора) на консоль.\n";

	for (i = 0, p = pp[0]; i < N * N; i++, p++)
	{
		if (i % N == 0)
		{
			std::cout << std::endl;
		}
		std::cout << *p << "\t";
	}

	std::cout << "\n\n\n";
}

int OperatorMatrix(int N, int *p, int i, int j)
{
	int res = 0;
	// Умножение строки на столбец
	
	for (int k = 0; k < N; k++)
		res += *(p + (i * N + k)) * *(p + (k * N + j));

	return res;
}

void Freeing(int** pp, int N)
{
	delete[] pp[0];
	delete[] pp;
}