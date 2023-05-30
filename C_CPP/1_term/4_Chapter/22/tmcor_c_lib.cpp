#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������� ��������� ������������ ��������� ������ ������
void ReadMas(int* mas, int n) {
    for (int i = 0; i < n; i++) scanf_s("%d", &mas[i]);
}
// ������� ������������ ������� ��������� ����� � ��������� �� lf �� rt
void RandMas(int* mas, int n, int lf, int rt) {
    srand(time(0));
    for (int i = 0; i < n; i++) mas[i] = rand() % (rt - lf + 1) + lf;
}
// ������� ������ ������� �� ������, ������ �������� ��������� ������������ ����
void PrintMas(int* mas, int n, bool ignore = false) {
    for (int i = 0; i <= n; i++) {
        if (i == n)  printf("\n");
        else if (!ignore || mas[i] != 0) printf("%4d", mas[i]);
    }

}
// ������� �������� ������� � lf, rt ���� ���� ������ ��� �� �������� ��������� ���� ����������
void NullMas(int* mas, int n, int lf = 0, int rt = 0) {
    if (rt == 0) rt = n;
    for (; lf <= rt; lf++) mas[lf] = 0;
}
// ������� ���������� ���������� ������� 
bool MonoMas(int* mas, int n, int lf = 0, int rt = 0) {
    int ras = mas[lf] - mas[lf + 1];
    if (rt == 0) rt = n;
    for (; lf < rt - 1; lf++) {
        if (ras != (mas[lf] - mas[lf + 1])) {
            return false;
            break;
        }
    }
    return true;
}
//������� �������� �������, saveset ����� �� ��������� ������ ������� ��� ������, lf � rt ������ ����� ������
void MoveMas(int* mas, int n, bool savest = false, int lf = 0, int rt = 0) {
    if (rt == 0) rt = n;
    int first = 0;
    if (savest) first = mas[lf];
    for (; lf < rt; lf++) {
        mas[lf] = mas[lf + 1];
    }
    mas[rt - 1] = first;
}
//������� ��������� �� ������� ���������
void ClearDup(int* mas, int n, int lf = 0, int rt = 0) {
    int count_dup = 0;
    if (rt == 0) rt = n;
    for (; lf < rt - 1; lf++) {
        if (mas[lf] == mas[lf + 1]) {
            mas[lf + 1] = 0;
            MoveMas(mas, n, false, lf + 1);
        }
    }
}