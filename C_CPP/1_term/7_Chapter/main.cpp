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
    printf("Введите размер матрицы, вначале количество строк, затем количество столбцов (<50)\n");
    scanf_s("%d%d", &m, &n);
    printf("Введите элементы матрицы (по змейки)\n");
    InputMatr(a, m, n);
    printf("Матрица\n");
    OutputMatr(a, m, n);
    SetTransMatr(a, a_t, n, m);
    printf("Транспонированная матрица:\n");
    OutputMatr(a_t, n, m);
    ComposMatr(a, a_t, a_e, n, m);
    printf("Произвдение первой и второй матрицы:\n");
    OutputMatr(a_e, m, n);
    if (IsScalarMatr(a_e, m, n)) printf("Ортогональная");
    else printf("Не ортогональная");
    return 0;
}