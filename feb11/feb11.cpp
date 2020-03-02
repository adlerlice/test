#include"iostream"

#include "cstdlib"

#include"ctime"

#include "fstream"

using namespace std;

void fillarr(int* const arr, int const length, int a, int b);

void showarr(int* const arr, int const length);

void deletek(int* arr, int& length, int const k);

void check(int& n);

void check(int& n)//количество чисел в файле

{

	int value;

	string path = "D:\\moa-195\\yaziki_progi\\2_sem\\input.txt";

	ifstream F;

	F.open(path);//открываем файл для чтения

	if (F.is_open())

	{

		F >> value;

		while (!F.eof())//проверяем, достигнут ли конец файла

		{

			F >> value;//считываем значение из файла

			if (value % 2 != 0)

				n++;

		}

		cout << "Количество нечетных чисел в файле:" << n << endl;

	}

	F.close();

}

int main()

{

	cout << "1)" << endl;

	setlocale(LC_ALL, "russian");

	int n = 0, i = 0, t;

	check(n);

	int* a = new int[n];

	string path = "D:\\moa-195\\yaziki_progi\\2_sem\\input.txt";

	ifstream F;

	F.open(path);

	if (!F.is_open())

	{

		cout << "Ошибка открытия файла\n";

	}

	else

	{

		cout << "Файл открыт\n";

	}

	while (!F.eof())

	{

		F >> t;//считываем

		if (t % 2 != 0) {

			a[i] = t;

			i++;

		}

	}

	cout << endl;

	F.close();

	//упорядочить по убыванию

	for (int i = 0; i < n - 1; i++)

	{

		for (int j = 0; j < n - i - 1; j++)

		{

			if (a[j] < a[j + 1]) {

				// меняем элементы местами

				int temp = a[j];

				a[j] = a[j + 1];

				a[j + 1] = temp;

			}

		}

	}

	cout << "Массив из нечетных чисел: ";

	for (int i = 0; i < n; i++)

	{

		if (a[i] % 2 != 0)

		{

			cout << a[i] << " ";

		}

	}

	cout << endl;

	cout << "2)" << endl;

	int A, b, k, length;

	cout << "\nВведите размерность массива:\n";

	cin >> length;

	int* arr = new int[length];

	cout << "Введите диапазон чисел рандома от a до b\n";

	cin >> A;

	cin >> b;

	fillarr(arr, length, A, b);

	cout << "Первоначальный массив:\n";

	showarr(arr, length);

	cout << "\nВведите число, которое хотите удалить\n";

	cin >> k;

	deletek(arr, length, k);

	cout << endl;

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