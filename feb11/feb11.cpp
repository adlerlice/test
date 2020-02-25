#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void showarr(int* const arr, int const length);
void fillarrws(int* const arr1, int* const arr2, int const length);
void fillarr(int* const arr, int const length, int a, int b);
void first_show(int* const arr1, int const length);
void odd_sort(int* const arr1, int* const arr2, int const length, int& key);
void bubble_sort(int*& arr2, int const length);
void second_show(int* const arr2, int const length, int& key);
void deletek(int* arr, int& length, int const k);
int prompt_menu_item();
int main()
{
	setlocale(LC_ALL, "");
	int length, a, b, i, k, key = 0;
	cout << "Введите размерность массива:\n";
	cin >> length;
	int* arr = new int[length];
	int* arr1 = new int[length];
	int* arr2 = new int[length];
	int variant = prompt_menu_item();
	switch (variant) {
	case 1:
		fillarrws(arr1, arr2, length);
		first_show(arr1, length);
		cout << endl;
		odd_sort(arr1, arr2, length, key);
		bubble_sort(arr2, length);
		second_show(arr2, length, key);
		delete[]arr;
		delete[]arr1;
		delete[]arr2;
		break;
	case 2:

		cout << "Введите диапазон чисел рандома от a до b\n";
		cin >> a;
		cin >> b;
		cin >> k;
		fillarr(arr, length, a, b);
		cout << "Первоначальный массив:\n";
		showarr(arr, length);
		cout << "Введите число, которое хотите удалить\n";
		deletek(arr, length, k);
		cout << endl;
		showarr(arr, length);
		delete[]arr;
		delete[]arr1;
		delete[]arr2;
		break;

	default:
		cerr << "Вы выбрали неверный вариант" << endl;
		exit(EXIT_FAILURE);
	}

}
void fillarrws(int* const arr1, int* const arr2, int const length)
{
	string path = "D:\\who\\r.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) cout << "Ошибка открытия файла\n";
	else cout << "Файл открыт\n";
	for (size_t i = 0; i < length; i++)
	{
		fin >> arr1[i];
		fin >> arr2[i];
	}
	fin.close();

}
void first_show(int* const arr1, int const length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr1[i] << " ";
	}
}

void odd_sort(int* const arr1, int* const arr2, int const length, int& key)
{
	for (size_t i = 0; i < length; i++)
	{
		while (arr1[i] % 2 != 0)
		{
			arr2[i] = arr1[i];
			cout << arr1[i] << " ";
			key++;
			break;
		}

	}
	cout << endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr2[i] << " ";
	}
}

void bubble_sort(int*& arr2, int const length)
{
	int temp;
	for (size_t i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++) {
			if (arr2[j] > arr2[j + 1]) {
				// меняем элементы местами
				temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
}
void second_show(int* const arr2, int const length, int& key)
{
	cout << endl;
	for (size_t i = 0; i < key; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
}
int prompt_menu_item()
{
	// Выбранный вариант менюж
	int variant;
	cout << "Выберите вариант\n" << endl;
	cout << "1. Сформировать динамический одномерный массив \n"
		<< "2. Заполнить динамический массив\n"
		<< "3. выйти\n" << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}
void fillarr(int* const arr, int const length, int a, int b)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % a - b;
	}
}
void deletek(int* arr, int& length, int const k)
{
	int h;
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
void showarr(int* const arr, int const length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
}

