#include <stdio.h>
#include <locale.h>

bool check_box(int x) {
	int b_cout = 0;
	for (int i=1; b_cout < x; b_cout = i * i * i, i++);
	if (b_cout == x) return true;
	else return false;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int a;
	printf("������� ����� �����: ");
	scanf_s("%d", &a);
	if (check_box(a)) printf("����� %d �������� �����", a);
	else printf("����� %d �� �������� �����", a);

	return 0;
}
