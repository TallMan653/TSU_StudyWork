#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"

const int n = 20;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	//Создание файла из n(20) символов
	char string1[n+1];
	FILE *f;
	errno_t f_err = fopen_s(&f, "main.txt", "w");
	if (f_err) { 
		printf("Ошибка при чтение файла");
		return 0;
	}
	CreateRandomString(string1, n);
	puts(string1);
	for (int i = 0; i < n; i++) {
		fprintf(f, "%c", string1[i]);
	}
	fclose(f);

	//Изменение файла
	char x;
	FILE *f1, *f2;
	errno_t f_err1 = fopen_s(&f1, "main.txt", "r");
	errno_t f_err2 = fopen_s(&f2, "rezult.txt", "w");
	if (f_err1 || f_err2) {
		printf("Ошибка при чтение файла");
		return 0;
	}


	while ((x= fgetc(f1)) != EOF) {
		if(ThisIsVowel(x)) fprintf_s(f2, "%c", '0');
		else fprintf_s(f2, "%c", x);
	}

	fclose(f1);
	fclose(f2);
	return 1;
}
