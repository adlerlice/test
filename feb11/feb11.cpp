#include <iostream> 
#include <cstring> 
#include <ctime>
#include <fstream>
#include <cstdio>


using namespace std;



int main()
{
	setlocale(LC_ALL, "");
	int size;
	int i, key = 0;
	cout << "n = ";
	cin >> size;
	int* arr1 = new int[size];
	int* arr2 = new int[size];
	string path = "D:\\who\\r.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) cout << "Ошибка открытия файла\n";
	else cout << "Файл открыт\n";
	cout << "Исходный массив:\n";
	for (i = 0; i < size; i++)
	{
		fin >> arr1[i];
		cout << arr1[i] << " ";
		fin >> arr2[i];
	}
	cout << endl;
	cout << "Нечётные элементы заданного массива:\n";
	for (i = 0; i < size; i++)
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
	int temp; // временная переменная для обмена элементов местами
	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++) {
			if (arr2[j] > arr2[j + 1]) {
				// меняем элементы местами
				temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
	cout << "Отсортированные нечётные элементы:\n";
	for (i = 0; i < key; i++) cout << arr2[i] << " ";
	fin.close();
	if (!fin.is_open()) cout << "\nФайл закрыт/Ошибка открытия файла\n";
	else cout << "Файл открыт\n";
	delete[] arr1;
	delete[] arr2;

	return 0;
}


}



