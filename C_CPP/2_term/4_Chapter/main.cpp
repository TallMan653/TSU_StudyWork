#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int n, lf, rt;
	printf("������� ���������� �����: ");
	scanf_s("%d", &n);
	printf("������� ������ ���������: ");
	scanf_s("%d", &lf);
	printf("������� ����� ���������: ");
	scanf_s("%d", &rt);
	CreateFilewithRandomNumber("main.txt", n, lf, rt);
	printf("�������� ����:\n");
	PrintFileNumb("main.txt");

	SortFileNumbWNM("main.txt");
	printf("����� ����������:\n");
	PrintFileNumb("main.txt");
	return 1;
}
