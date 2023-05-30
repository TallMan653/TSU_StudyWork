#include <stdio.h>
#include <locale.h>

int check_sov(int x) {
	int sum = 0;
	for (int i = 1; i < int(x / 2) + 1; i++) {
		if (x % i == 0) sum += i;
	}
	return sum;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int a;
	printf("Введите натуральное число: ");
	scanf_s("%d", &a);
	if (check_sov(a) == a) printf("Число %d является совершенным", a);
	else printf("Число %d не является совершенным", a);

	return 0;
}