#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "rus");
	
	setlocale(LC_ALL, "rus");
	int x;
	printf("¬ведите целое число: ");
	scanf_s("%d", &x);
	if (x < 1) printf("%d", abs(x));
	else if (x >= 1 && x <= 3) printf("1");
	else printf("%d", -abs(x) + 4);
}