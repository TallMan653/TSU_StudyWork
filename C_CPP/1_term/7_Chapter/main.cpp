#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
    setlocale(LC_ALL, "rus");
    float a[50][50];
    float a_t[50][50];
    float a_e[50][50];

    int n, m;
    printf("������� ������ �������, ������� ���������� �����, ����� ���������� �������� (<50)\n");
    scanf_s("%d%d", &m, &n);
    printf("������� �������� ������� (�� ������)\n");
    InputMatr(a, m, n);
    printf("�������\n");
    OutputMatr(a, m, n);
    SetTransMatr(a, a_t, n, m);
    printf("����������������� �������:\n");
    OutputMatr(a_t, n, m);
    ComposMatr(a, a_t, a_e, n, m);
    printf("����������� ������ � ������ �������:\n");
    OutputMatr(a_e, m, n);
    if (IsScalarMatr(a_e, m, n)) printf("�������������");
    else printf("�� �������������");
    return 0;
}