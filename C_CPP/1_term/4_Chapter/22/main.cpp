#include <stdio.h>
#include <stdlib.h>
#include "tmcor_c_lib.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int a[50], n;
    printf("������� n (n<50): ");
    scanf_s("%d", &n);
    printf("������� �������� ���������, ����� enter\n");
    ReadMas(a, n);
    printf("\n������: ");
    PrintMas(a, n);
    if (MonoMas(a, n)) printf("�������� ���������� �������������������");
    else printf("�� �������� ���������� �������������������");
}