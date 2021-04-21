#include <iostream>
#include <iomanip>

using namespace std;

//Переменная для подсчета количества сравнений
int comparison;
//Переменная для подсчета количества перемещений
int movement;

//Функция удаления элементов массива
//Предусловие: на вход поступает указатель на ненулевой массив, количество элементов массива, значение, коротое нужно удалить
//Постусловие: функция удаляет из массива все элементы со значение key и изменяет размер массива
void delFirstMethod(int*& x, int& n, int key) {
	//Переменная для подсчета количества сравнений
	comparison = 0;
	//Переменная для подсчета количества перемещений
	movement = 0;
	int i = 0;
	while (i < n)
	{
		comparison++;
		if (x[i] == key)
		{
			for (int j = i; j < n - 1; j++)
			{
				x[j] = x[j + 1];
				movement++;
			}
			n--;
		}
		else
		{
			i++;
		}
	}
}

//Функция удаления элементов массива
//Предусловие: на вход поступает указатель на ненулевой массив, количество элементов массива, значение, коротое нужно удалить
//Постусловие: функция удаляет из массива все элементы со значение key и изменяет размер массива
void delOtherMethod(int*& x, int& n, int key)
{
	//Переменная для подсчета количества сравнений
	comparison = 0;
	//Переменная для подсчета количества перемещений
	movement = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		movement++;
		x[j] = x[i];
		comparison++;
		if (x[i] != key)
		{
			j++;
		}
	}
	n = j;
}


//Функция заполнения массива случайными числами
//Предусловие: на вход поступает ссылка на массив и его длина
//Постусловие: функция заполняет массив случаными числами
void randomFill(int*& x, int n)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = rand() % 10; //ограничение для отладки
	}
}

//Функция вывода массива на экран
//Предусловие: на вход поступает ссылка на массив и его длина
//Постусловие: функция выводит массив в консоли
void printArray(int* x, int n)
{
	if (x == nullptr || n == 0)
	{
		cout << "Массив пуст";
	}
	else
	{
		for (int i = 0; i < n; i++) {
			cout << setw(4) << x[i];
		}
	}
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int n;
	int* array;
	int key;

	n = 10;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delFirstMethod на массиве из 10 элементов (удаляемое значение: " << key << "):" << endl;
	randomFill(array, n);
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delFirstMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 100;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delFirstMethod на массиве из 100 элементов (удаляемое значение: " << key << "):" << endl;
	randomFill(array, n);
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delFirstMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 10;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delFirstMethod на массиве из 10 элементов, при условии, что не будет удален ни один элемент (удаляемое значение: " << key << "):" << endl;
	for (int i = 0;i < n;i++)
	{
		array[i] = key + 1;
	}
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delFirstMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 10;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delFirstMethod на массиве из 10 элементов, при условии, что будут удалены все элементы (удаляемое значение: " << key << "):" << endl;
	for (int i = 0;i < n;i++)
	{
		array[i] = key;
	}
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delFirstMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 10;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delOtherMethod на массиве из 10 элементов (удаляемое значение: " << key << "):" << endl;
	randomFill(array, n);
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delOtherMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 100;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delOtherMethod на массиве из 100 элементов (удаляемое значение: " << key << "):" << endl;
	randomFill(array, n);
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delOtherMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 10;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delOtherMethod на массиве из 10 элементов, при условии, что не будет удален ни один элемент (удаляемое значение: " << key << "):" << endl;
	for (int i = 0;i < n;i++)
	{
		array[i] = key + 1;
	}
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delOtherMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;

	n = 10;
	array = new int[n];
	key = 7;
	cout << "Тестирование алгоритма delOtherMethod на массиве из 10 элементов, при условии, что будут удалены все элементы (удаляемое значение: " << key << "):" << endl;
	for (int i = 0;i < n;i++)
	{
		array[i] = key;
	}
	cout << "Массив до обработки: " << endl;
	printArray(array, n);
	delOtherMethod(array, n, key);
	cout << "Массив после обработки: " << endl;
	printArray(array, n);
	cout << "Количество сравнений: " << comparison << endl;
	cout << "Количество перемещений: " << movement << endl;
}

