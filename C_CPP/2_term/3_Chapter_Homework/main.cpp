#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
	int x,n,lf,rt;
	FILE* f1, * f2;
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	printf("¬ведите количество цифр: ");
	scanf_s("%d", &n);
	printf("¬ведите начальное значение диапозона: ");
	scanf_s("%d", &lf);
	printf("¬ведите конечное значение диапозона: ");
	scanf_s("%d", &rt);

	CreateFilewithRandomNumber("data.txt", n, lf, rt);
	PrintFileNumb("data.txt");

	errno_t f_err1 = fopen_s(&f1, "data.txt", "r");
	errno_t f_err2 = fopen_s(&f2, "rezult.txt", "w");
	if (f_err1 || f_err2) {
		printf("ќшибка при создание файла");
		exit(-1);
	}
	while (fscanf_s(f1, "%d", &x) != EOF)
		if (!(x & 0x01)) fprintf(f2, "%d ", x);

	fclose(f1);
	fclose(f2);

	return 1;
}
