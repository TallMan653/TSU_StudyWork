#include <stdio.h>
#include <locale.h>

bool type_check(int x) {
	if (x % 2 == 0) return true;
	else return false;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b;
	bool f_check = true;
	printf("--------6.3--------\n");
	do {
		if (!f_check) printf("����� A ������ ���� ������ ��� ����� ����� B\n");
		printf("������� ����� ����� A: ");
		scanf_s("%d", &a);
		printf("������� ����� ����� B: ");
		scanf_s("%d", &b);
		f_check = false;
	} while (a > b);
	if (b > 0) b = -2;
	if (!type_check(b)) b -= 1;

	for (; b >= a; b -= 2) {
		printf("%d\n", b);
	}

	return 0;
}