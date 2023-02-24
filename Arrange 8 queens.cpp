

//int pos[10];
//int N = 0;
//bool OK(int x, int y)
//{
//	bool check = true;
//
//	for (int i = 1; i < x; i++)
//	{
//		if (pos[i] == y || abs(i - x) == abs(pos[i] - y))
//		{
//			check = false;
//			break;
//		}
//	}
//	return check;
//}
//
//void Print()
//{
//	for (int i = 1; i <= 8; i++)
//		//cout << "(" << i << "; " << pos[i] << ") - ";
//		cout << pos[i] << " ";
//	cout << endl;
//}
//
//void Try(int i, int n)
//{
//	for (int j = 1; j <= n; j++)
//	{
//		if (OK(i, j))
//		{
//			pos[i] = j;
//			if (i == n)
//			{
//				N++;
//				Print();
//			}
//			else if (i < n)
//				Try(i + 1, n);
//		}
//	}
//}
//
//int main()
//{
//	int n = 8;
//	Try(1, n);
//	cout << "\n\n\nN= " << N << endl;
//	return 0;
//}

#include <iostream>

using namespace std;

// массив используется для хранения положения 8 ферзей в каждой строке, i-й ферзь имеет позицию (i, pos[i])
int pos[10];
// Количество способов расставить 8 ферзей
int M = 0;


bool OK(int x, int y)
{
	bool check = true;

	for (int i = 1; i < x; i++)
	{
		// Проверьте, находятся ли ферзи в одном столбце: pos[i] == y
		// Проверить, находятся ли ферзи на диагонали:  abs(i - x) == abs(pos[i] - y
		if (pos[i] == y || abs(i - x) == abs(pos[i] - y))
		{
			check = false;
			break;
		}
	}
	return check;
}

void Print()
{
	// Выходная позиция 8 ферзей, i-й ферзь имеет позицию (i, pos[i])
	for (int i = 1; i <= 8; i++)
		cout << pos[i] << " ";
	cout << endl;
}


void Try(int i, int m)
{
	for (int j = 1; j <= 8; j++)
	{
		if (OK(i, j))
		{
			pos[i] = j;
			if (i == 8)
			{
				M++;
				if (M > m)
					return;
				Print();
			}
			else if (i < 8)
				Try(i + 1, m);
		}
	}
}

int main()
{
	int m;

	cout << "Количество расстановок 8 ферзей на шахматной доске, нужно найти: ";
	cin >> m;

	cout << "Выведите положение 8 ферзей на 8 рядах:\n";
	Try(1, m);
	
	if (m > M)
	 cout << "Все расстановок 8 ферзей на шахматной доске, при которых ни один из ферзей не угрожает никакому другому: " << M << endl;

	return 0;
}