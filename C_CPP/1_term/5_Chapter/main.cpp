#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tmcor_c_lib.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int *mas, n;
	printf("Введите количество элементов массива: ");
	scanf_s("%d", &n);
	mas = new int[n];

	printf("Введите элементы:\n");
	ReadMas(mas, n);
	printf("Массив:\n");
	PrintMas(mas, n);
	int min = MinInt(MaxPtr(mas, n), MinPtr(mas, n)), max = MaxInt(MaxPtr(mas, n), MinPtr(mas, n));
	if (Mono(mas, n, min, max)) {
		printf("В этом массиве есть монотонная последовательность: ");
		PrintMas(mas + min, max - min+1);
	}else printf("В этом массиве нету монотонной последовательности");
	delete[] mas;
}