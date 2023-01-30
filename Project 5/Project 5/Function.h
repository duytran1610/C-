#pragma once
#include <iostream>
#include "Figure.h"

// Меню для выбора создания объекта
void MenuInput();

// Меню для операторы
void Menu();

// ввода объектов произвольного типа
void Input(const int&, Figure**);

// подсчитать количество объектов каждого типа
void findNumberOfType(const int&, Figure**);

// вывести информацию по каждому объекту
void ShowInfo(const int&, Figure**);

// найти четырехугольник с максимальной площадью
Figure* findMaxArea(const int&, Figure**);

// Проверить возможно создать объект типа площадь и круга при помощью функции Static 
void testFunctionStatic();