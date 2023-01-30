#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include "City.h"


// Функция для нахождения общей численности населения
int SumPopulation(vector<City> v_Citys);

// Функция поиска города с наибольшим населением
City CityMaxPopulation(vector<City> v_Citys);

// Функция сортировки городов по возрастанию численности населения
void SortCitys(vector<City>& v_Citys);

// Функция поиска города, удовлетворяющего условию площади
void FindCityByArea(vector<City> v_Citys);

// Функция поиска города по названию
void FindCityByName(vector<City> v_Citys);

// Функция поиска города по названию
void Menu();

// Функция добавления города
void AddCity(vector<City>& v_Citys);

// Функция дает информацию обо всех городах
void ShowInfoCitys(vector<City> v_Citys);

// Функция удаления города из списка
bool DeleteCity(vector<City>& v_Citys, string name);