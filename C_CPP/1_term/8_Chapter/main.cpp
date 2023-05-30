#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
	setlocale(LC_ALL, "rus");
	int** mas, n, m, km = -1, max_m = 0, c_m;
	printf("Введите количество строк: ");
	scanf_s("%d", &m);
	printf("Введите количество столбцов: ");
	scanf_s("%d", &n);
	mas = new int* [n];
	for (int i = 0; i < n; i++) mas[i] = new int[m];
	InputMatrD(mas,m,n);
	printf("Матрица:\n");
	OutputMatrD(mas, m, n);
	for (int i = 0; i < n; i++) {
		c_m = 0;
		for (int j = 0; j < n; j++)if (mas[i][j] < 0) c_m++;

		if (c_m > max_m) {
			km = i;
			max_m = c_m;
		}
	}
	if (km != -1) m = DelStr(mas,m,n,km);
	printf("После удаления:\n");
	OutputMatrD(mas, m, n);
	for (int i = 0; i < n-1; i++) delete[] mas[i];
	delete[] mas;
	return 0;
}