#include <stdio.h>
#include <locale.h>

bool type_check(int x) {
	if (x % 2 == 0) return true;
	else return false;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int x, y;
	printf("������� ������ ����� �����: ");
	scanf_s("%d", &x);
	printf("������� ������ ����� �����: ");
	scanf_s("%d", &y);
	if (type_check(x) == type_check(y)) printf("�����");
	else printf("�� �����");
	return 0;
}
/*
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int x, y;
	printf("������� ������ ����� �����: ");
	scanf_s("%d", &x);
	printf("������� ������ ����� �����: ");
	scanf_s("%d", &y);
	if (x % 2 == y % 2) printf("�����");
	else printf("�� �����");
	return 0;
}
*/