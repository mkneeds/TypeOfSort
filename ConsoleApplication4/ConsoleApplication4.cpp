
#include<iostream>
#include<iostream>
#include<math.h>
#include <ctime>
using namespace std;
int checkInt()
{
	int value, counter = 0;
	char* BufForWriting = new char[256];
	cin.clear();
	cin.getline(BufForWriting, 256, '\n');
	for (int i = 0; BufForWriting[i] != '\0'; i++)
		if (isdigit(BufForWriting[i]))
			counter++;
	if (strlen(BufForWriting) != counter ||
		(BufForWriting[0] == '0' && strlen(BufForWriting) > 1))
		value = -1;
	else value = atoi(BufForWriting);
	delete[] BufForWriting;
	return value;
}
int checkInterval(int min, int max)
{
	int value;
	value = checkInt();
	while (value < min || value > max)
	{
		cout << "Введите значение: ";
		value = checkInt();
	}
	return value;
}
void print(int n,int a[], int b[], int c[], int d[], int e[]) {
	cout << "\na[" << n << "]:";
	for (int i = 0; i < n; i++) {
		cout << " " << a[i];
	}
	cout << "\nb[" << n << "]:";
	for (int i = 0; i < n; i++) {
		cout << " " << b[i];
	}
	cout << "\nc[" << n << "]:";
	for (int i = 0; i < n; i++) {
		cout << " " << c[i];
	}
	cout << "\nd[" << n << "]:";
	for (int i = 0; i < n; i++) {
		cout << " " << d[i];
	}
	cout << "\ne[" << n << "]:";
	for (int i = 0; i < n; i++) {
		cout << " " << e[i];
	}
}
void buble(int* digitals,int n) {
	for (int i = 0; i <n ; i++) {
		bool flag = true;
		for (int j = 0; j < n - (i + 1); j++) {
			if (digitals[j] > digitals[j + 1]) {
				flag = false;
				swap(digitals[j], digitals[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
}
void SelectionSort(int* A, int n)
{
	int count, key;
	for (int i = 0; i < n - 1; i++)
	{
		count = A[i]; key = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[key]) key = j;
		if (key != i)
		{
			A[i] = A[key];
			A[key] = count;
		}
	}
}
void insertsort(int* c, int n) {
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && c[j - 1] > c[j]; j--) 
			swap(c[j - 1], c[j]);
}
void Shell(int A[], int n)
{
	int d,j,count;
	d = n;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && A[j] > A[j + d])
			{
				count = A[j];
				A[j] = A[j + d];
				A[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}
void hoare(int* s_arr, int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2];

	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;

		if (i <= j) {
			if (s_arr[i] > s_arr[j]) swap(s_arr[i], s_arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		hoare(s_arr, i, last);
	if (first < j)
		hoare(s_arr, first, j);
}
int linefind(int* arr, int size, int key) {
	for (int i = 0; i < size; ++i)
		if (arr[i] == key) {
			cout << "Такое число есть и находится на позиции ->" << i+1 << endl;
		}
	cout << "Такого числа нет" << endl;
	return -1;
}
int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;
		if (key < arr[midd])      
			right = midd - 1;     
		else if (key > arr[midd])  
			left = midd + 1;    
		else {
			cout << "Такое число есть и находится на позиции ->" << midd+1 << endl;
			return midd;
		}
		if (left > right)           
			return -1;
	}
}
int* a = new int[256];
int* b = new int[256];
int* c = new int[256];
int* d = new int[256];
int* e = new int[256];
int n;
int main() {
	setlocale(0, "rus");
start:
	cout << "\t\tМеню:" << endl;
	cout << "\t1)Инициализация массивов" << endl;
	cout << "\t2)Cортировка пузырьком" << endl;
	cout << "\t3)Cортировка выбором" << endl;
	cout << "\t4)Cортировка вставки" << endl;
	cout << "\t5)Cортировка Шелла" << endl;
	cout << "\t6)Cортировка Хоора" << endl;
	cout << "\t7)Последовательный поиск" << endl;
	cout << "\t8)Бинарный поиск" << endl;
	switch (checkInterval(1, 8)) {
	case 1: {
		cout << "Введите количество элементов в массиве" << endl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Введите " << i + 1 << "-элемент" << endl;
			cin >> a[i];
			b[i] = a[i];
			c[i] = a[i];
			d[i] = a[i];
			e[i] = a[i];

		}
		print(n, a, b, c, d, e);
		goto start;
		break;
	}
	case 2: {
		buble(a, n);
		print(n, a, b, c, d, e);
		goto start;
		break;
	}
	case 3: {
		SelectionSort(b, n);
		print(n, a, b, c, d, e);
		goto start;
		break;
	}
	case 4: {
		insertsort(c, n);
		print(n, a, b, c, d, e);
		goto start;
		break;
	}
	case 5: {
		Shell(d, n);
		print(n, a, b, c, d, e);
		goto start;
		break;
	}
	case 6: {
		hoare(e, 0, n - 1);
		print(n, a, b, c, d, e);
		goto start;
		break;
	}
	case 7: {
		int c;
		cout << "Введите число для поиска" << endl;
		cin >> c;
		linefind(a, n, c);
		goto start;
		break;
	}
	case 8: {
		int c;
		cout << "Введите число для поиска" << endl;
		cin >> c;
		Search_Binary(a, 0, n, c);
		goto start;
		break;
	}
	}
}