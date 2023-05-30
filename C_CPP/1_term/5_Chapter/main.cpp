#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tmcor_c_lib.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int *mas, n;
	printf("������� ���������� ��������� �������: ");
	scanf_s("%d", &n);
	mas = new int[n];

	printf("������� ��������:\n");
	ReadMas(mas, n);
	printf("������:\n");
	PrintMas(mas, n);
	int min = MinInt(MaxPtr(mas, n), MinPtr(mas, n)), max = MaxInt(MaxPtr(mas, n), MinPtr(mas, n));
	if (Mono(mas, n, min, max)) {
		printf("� ���� ������� ���� ���������� ������������������: ");
		PrintMas(mas + min, max - min+1);
	}else printf("� ���� ������� ���� ���������� ������������������");
	delete[] mas;
}