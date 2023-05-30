/*#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	int x, y;
	printf("¬ведите первое целое число: ");
	scanf_s("%d", &x);
	printf("¬ведите второе целое число: ");
	scanf_s("%d", &y);

	if ((float)x/2 > (float)y) printf("%d", x);
	else printf("%d,%d", x, y);
	return 0;
}*/

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	int x, y;
	printf("¬ведите первое целое число: ");
	scanf_s("%d", &x);
	printf("¬ведите второе целое число: ");
	scanf_s("%d", &y);

	if ((x-y)>y) printf("%d", x);
	else printf("%d,%d", x, y);
	return 0;
}
