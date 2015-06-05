//	� ������ ������ ������� �(N,�) ����� � ������� ����������� ��������.
#include <iostream>
using namespace std;

void readMatrixSize(int&, int&);     
void readMatrix(int**, int, int);    
void printMatrix(int**, int, int);
void deleteMins(int**, int, int&);

int main()
{
	int n, m, **matrix = 0;
	readMatrixSize(n, m);       // ������ �����������
	matrix = new int*[n];		// ������ ������ �����
	readMatrix(matrix, n, m);	// ������ �������
	deleteMins(matrix, n, m);	// ������� ����������� �� ������ ������
	printMatrix(matrix, n, m);  // ������� ������� 

	return 0;
}

void readMatrixSize(int& n, int& m){
	cout << "Enter size of your array(n, m): ";  // ������ ������ �������
	cin >> n;
	cin >> m;
}

void readMatrix(int** matrix, int n, int m){
	
	for (int i = 0; i < n; i++){     // ������� ������ ������ �������
		matrix[i] = new int[m];
	}

	cout << "Enter your matrix: " << endl;
	for (int i = 0; i < n; i++){	 // ����� ��������� � ��� ������
		for (int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(int** matrix, int n, int m){
	cout << "Your matrix: " << endl;	// ��� �� �������
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
}

int minPosition(int* a, int n){
	int nMin = 0;					// ��������� ����� ������ ������������ �������� � �������
	for (int i = 1; i < n; i++){
		if (a[i] < a[nMin]){
			nMin = i;
		}
	}
	return nMin;
}

void deleteMin(int* a, int n, int pos){
	for (int i = pos; i < n; i++){	// ������� ������� ���������������� ������� �������
		a[i] = a[i + 1];
	}
}

void deleteMins(int** matrix, int n, int &m){
	m--;
	for (int i = 0; i < n; i++){	// ��� �� ������� � � ������ ������ ������� ����������� �������
		deleteMin(matrix[i], m, minPosition(matrix[i], m));
	}
}