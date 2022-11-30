#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

void checkValidInput() 
{
	if (cin.fail())
	{
		throw "Помилка введення";
	}
}

void checkValidParams(int n, double h, double a, double b)
{
	if (n < 3 || h <= 0 || a > b)
	{
		throw "Невірні дані";
	}
}

double calculate(double x, int n) 
{
	double y = 0;

	if (x < 0)
	{
		for (int i = 1; i <= n - 1; i++)
		{
			double sum = 0;
			for (double j = 1; j <= n; j++)
			{
				sum += j / (j * j + j);
			}
			y += sum;
		}
	}
	else if (x >= 0)
	{
		double sum = 0;
		for (int i = 1; i <= n - 1; i++)
		{
			sum += i;
		}
		y = x - sum;
	}
	return y;
}

void output(double x, int n, double a, double b, double h) 
{
	for (x = a; x <= b; x += h)
	{
		cout << "\nx= " << x << "\t" << "y = " << calculate(x, n);
	}
}

void file_is_open(double a, double b, double h, double x, int n) //відкриття файлу для запису даних
{
	ofstream fout;
	fout.open("text.txt");
	if (!fout.is_open()) //перевірка на відкриття файлу
	{
		throw "Файл не відкрився!";
	}
	else
	{ 
		fout << "a= " << a << "\t" << "b= " << b << endl; //запис даних та результатів
		fout << "h= " << h << endl;
		fout << "n= " << n << endl;
		while (x <= b)
		{
			fout << "x=" << x << "\ty=" << calculate(x, n) << endl;
			x += h;
		}
		cout << "Результати занесені до файлу" << endl;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	double a, b, h, x;
	int n;
	try
	{
		cout << "Ввести a, b: "; 
		cin >> a >> b;
		checkValidInput();

		cout << "Ввести h: "; 
		cin >> h;
		checkValidInput();

		cout << "Ввести n: "; 
		cin >> n;
		checkValidInput();

		checkValidParams(n, h, a, b);
		x = a;
		calculate(x, n);
		output(x, n, a, b, h);

		char text;
		cout << "\nЗаписати результати в файл?(y/n)" << endl;
		cin >> text;

		if (text == 'y')
		{
			file_is_open(a, b, h, x, n);
		}
		else
		{
			cout << "Результати не занесені до файлу" << endl;
		}
	}
	catch (const char* ex) 
	{
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "Невідома помилка" << endl;
		return -2;
	}

}
