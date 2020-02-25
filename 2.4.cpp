#include <iostream>

using namespace std;

void fillarr(int* const arr, int const length, int a, int b);

void showarr(int* const arr, int const length);

void deletezero(int* arr, int& length, int k);

int main()

{

	setlocale(LC_ALL, "");

	int length, a, b, k;

	cout << "Введите размерность массива:\n";

	cin >> length;

	cout << "Введите диапазон чисел рандома от a до b\n";

	cin >> a;

	cin >> b;

	int* arr = new int[length];

	fillarr(arr, length, a, b);

	cout << "Первоначальный массив:\n";

	showarr(arr, length);

	cout << "\nВведите число, которое хотите удалить:\n";

	cin >> k;

	deletezero(arr, length, k);

	cout << endl;

	cout << "Массив без чисел: " << k << endl;

	showarr(arr, length);

	delete[]arr;

	return 0;

}

void fillarr(int* const arr, int const length, int a, int b)

{

	for (size_t i = 0; i < length; i++)

	{

		arr[i] = rand() % a - b;

	}

}

void showarr(int* const arr, int const length)

{

	for (size_t i = 0; i < length; i++)

	{

		cout << arr[i] << " ";

	}

}

void deletezero(int* arr, int& length, int k)

{

	int h = 0;

	for (size_t i = 0; i < length; i++)

	{

		while (arr[i] == k)

		{

			h = i;

			for (size_t i = h; i < length; i++)

			{

				arr[i] = arr[i + 1];

			}

			--length;

		}

	}

}
