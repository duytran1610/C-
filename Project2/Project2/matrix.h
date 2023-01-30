#pragma once

// Консольное меню для работы матрицами (ввод, вывод, операция)
void ShowMenu();

// Вывод матрицы (или вектора) на консоль
void OutputMatrix(int**, int, int*);

// Ввод матрицы (или вектора) с консоли
void IntputMatrix(int**, int, int*);

// Умножение строки на столбец
int  OperatorMatrix(int, int*, int, int);

// освобождение динамической памяти
void Freeing(int**, int);

// создать новое измерение для матрицы со значениями по умолчанию
void CreateNewMatrix(int**&, int&, int*);