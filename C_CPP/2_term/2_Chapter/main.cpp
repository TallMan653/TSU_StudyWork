#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
	srand(time(NULL));
	UI* bm, mask;
	int m, n;
	char s[33];
	setlocale(LC_ALL, "rus");
	printf("Введите размер матрицы m*n\n");
	scanf_s("%d%d", &m, &n);
	getchar();

	bm = new UI[m];
	if (bm == NULL) return 0;

	printf("Введите матрицу\n");
	InputRandomBMVec(bm, m, n);
	printf("Ваша матрица:\n");
	OutputBMVec(bm, m, n);
	SortBMVecByWeightDown(bm, m, n);
	printf("После сортировки:\n");
	OutputBMVec(bm, m, n);

	delete[]bm;
	return 1;
}
