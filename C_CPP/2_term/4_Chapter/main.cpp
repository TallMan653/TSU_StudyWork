#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int n, lf, rt;
	printf("Введите количество чисел: ");
	scanf_s("%d", &n);
	printf("Введите начало диапозона: ");
	scanf_s("%d", &lf);
	printf("Введите конец диапозона: ");
	scanf_s("%d", &rt);
	CreateFilewithRandomNumber("main.txt", n, lf, rt);
	printf("Исходный файл:\n");
	PrintFileNumb("main.txt");

	SortFileNumbWNM("main.txt");
	printf("После сортировки:\n");
	PrintFileNumb("main.txt");
	return 1;
}
