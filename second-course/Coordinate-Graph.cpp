// Создать график с выводом на нём точки с линиями

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(0, "");

	int X, Y, x, y, key = 0;

	// Ввод значений для X и Y
	cout << "Введите X: ";
	cin >> X;
	cout << "Введите Y: ";
	cin >> Y;

	X = abs(X);
	Y = abs(Y);

	// Создание двумерного массива
	string** arr = new string * [Y * 2 + 1];
	for (int i = 0; i < Y * 2 + 1; i++)
	{
		arr[i] = new string[X * 2 + 1];
	}
	 
	// Запись в массив координатной плоскости
	for (int i = 0; i < Y * 2 + 1; i++)
	{
		if (i != Y)
		{
			for (int j = 0; j < X * 2 + 1; j++) 
			{
				if (j != X) 
				{
					arr[i][j] = "  ";
				}
				else
				{
					arr[i][j] = "# ";
				}
			}
		}
		else
		{
			for (int j = 0; j < X * 2 + 1; j++)
			{
				arr[i][j] = "# ";
			}
		}
	}

	// Ввывод массива
	for (int i = 0; i < Y * 2 + 1; i++)
	{
		for (int j = 0; j < X * 2 + 1; j++) 
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}

	while (true)
	{
		cout << "\n\nВведите координаты точки \n";
		cout << "Введите x точки: ";
		cin >> x;
		cout << "Введите y точки: ";
		cin >> y;

		// Проверка
		if (abs(x) > X or abs(y) > Y)
		{
			cout << "\nВы ввели неправильную координату точки";
			continue;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "Точка (" << x << "," << y << ")\n\n";

		// Записываем точку в массив
		if (x >= 0 and y >= 0)
		{
			arr[Y - y][X + x] = "0 ";
			// Полоса к оси x
			for (int i = 0; i < y; i++)
			{
				arr[Y - y + i][x + X] = "' ";
			}
			// Полоса к оси y
			for (int i = 0; i < x; i++)
			{
				arr[Y - y][X + x - i] = "- ";
			}
		}
		else if (x <= 0 and y > 0)
		{
			x = abs(x);
			arr[Y - y][X - x] = "0 ";
			// Полоса к оси x
			for (int i = 0; i < y; i++)
			{
				arr[Y - y + i][X - x] = "' ";
			}
			// Полоса к оси y
			for (int i = 0; i < x; i++)
			{
				arr[Y - y][X - x + i] = "- ";
			}
		}
		else if (x < 0 and y <= 0)
		{
			x = abs(x);
			y = abs(y);
			arr[Y + y][X - x] = "0 ";
			// Полоса к оси x
			for (int i = 0; i < y; i++)
			{
				arr[Y + y - i][X - x + i] = "' ";
			}
			// Полоса к оси y
			for (int i = 0; i < x; i++)
			{
				arr[Y + y][X - x + i] = "- ";
			}
		}
		else if (x > 0 and y < 0)
		{
			y = abs(y);
			arr[Y + y][x + X] = "0 ";
			// Полоса к оси x
			for (int i = 1; i < y; i++)
			{
				arr[Y + y - i][X + x] = "' ";
			}
			// Полоса к оси y
			for (int i = 0; i < x; i++)
			{
				arr[Y + y][X + x - i] = "- ";
			}
		}

		// Вывод массива
		for (int i = 0; i < Y * 2 + 1; i++)
		{
			for (int j = 0; j < X * 2 + 1; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}

		key = _getch();
		if (key == 49)
		{
			while (true) {
				cout << "Введите координаты точки \n";
				cout << "Введите X точки: ";
				cin >> x;
				cout << "Введите Y точки: ";
				cin >> y;

				// Проверка
				if (abs(x) > X or abs(y) > Y)
				{
					cout << "\nВы ввели неправильную координату точки";
					continue;
				}
				else 
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}
