//	В каждой строке массива А(N,М) найти и удалить минимальные элементы.
#include <iostream>
using namespace std;

void readMatrixSize(int&, int&);     
void readMatrix(int**, int, int);    
void printMatrix(int**, int, int);
void deleteMins(int**, int, int&);

int main()
{
	int n, m, **matrix = 0;
	readMatrixSize(n, m);       // Читаем размерность
	matrix = new int*[n];		// Создаём массив строк
	readMatrix(matrix, n, m);	// Читаем матрицу
	deleteMins(matrix, n, m);	// Удаляем минимальные из каждой строки
	printMatrix(matrix, n, m);  // Выводим матрицу 

	return 0;
}

void readMatrixSize(int& n, int& m){
	cout << "Enter size of your array(n, m): ";  // Задаем размер матрицы
	cin >> n;
	cin >> m;
}

void readMatrix(int** matrix, int n, int m){
	
	for (int i = 0; i < n; i++){     // Сначала создаём строки матрицы
		matrix[i] = new int[m];
	}

	cout << "Enter your matrix: " << endl;
	for (int i = 0; i < n; i++){	 // Потом считываем в них данные
		for (int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(int** matrix, int n, int m){
	cout << "Your matrix: " << endl;	// Тут всё понятно
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
}

int minPosition(int* a, int n){
	int nMin = 0;					// Банальный поиск номера минимального элемента в массиве
	for (int i = 1; i < n; i++){
		if (a[i] < a[nMin]){
			nMin = i;
		}
	}
	return nMin;
}

void deleteMin(int* a, int n, int pos){
	for (int i = pos; i < n; i++){	// Удаляем элемент последовательным сдвигом массива
		a[i] = a[i + 1];
	}
}

void deleteMins(int** matrix, int n, int &m){
	m--;
	for (int i = 0; i < n; i++){	// Идём по строкам и в каждой строке удаляем минимальный элемент
		deleteMin(matrix[i], m, minPosition(matrix[i], m));
	}
}