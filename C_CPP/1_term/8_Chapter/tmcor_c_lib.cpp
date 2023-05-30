#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ReadMas(int* mas, int n) {
    for (int* p = mas; p < mas + n; p++) scanf_s("%d", p);
}

void PrintMas(int* mas, int n) {
    for (int* p = mas; p < mas + n; p++) printf("%4d", *p);
    printf("\n");
}

int MaxPtr(int* mas, int n) {
    int* i_max, * p;
    for (i_max = mas, p = mas + 1; p < mas + n; p++) if (*p > *i_max) i_max = p;
    return i_max - mas;
}

int MinPtr(int* mas, int n) {
    int* i_min, * p;
    for (i_min = mas, p = mas + 1; p < mas + n; p++) if (*p < *i_min) i_min = p;
    return i_min - mas;
}

int MaxInt(int x, int y) {
    if (x > y) return x;
    return y;
}

int MinInt(int x, int y) {
    if (x < y) return x;
    return y;
}

bool Mono(int* mas, int n, int min = 0, int max = 0) {
    if (max == 0) max = n;
    int* c_min = mas + min;
    int* c_max = mas + max;
    int ras = c_min - (c_min + 1);
    for (; c_min < c_max; c_min++) {
        if (c_min - (c_min + 1) == 0) continue;
        if (ras != c_min - (c_min + 1)) {
            return false;
            break;
        }
    }
    return true;
}

void InputMatr(float matr[][50], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf_s("%f", &matr[i][j]);
}

void OutputMatr(float matr[][50], int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) printf(" %.3f ", matr[i][j]);
        printf("\n");
    }
}

void SetTransMatr(float matr[][50], float matr_t[][50], int n, int m) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) matr_t[j][i] = matr[i][j];
}
bool IsScalarMatr(float matr[][50], int m, int n, int c = 1) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matr[i][j] != c) || (i != j && matr[i][j] != 0)) {
                return false;
                break;
            }
        }
    }
    return true;
}
void ComposMatr(float matr[][50], float matr_t[][50], float matr_end[][50], int n, int m) {
    int sum;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        sum = 0;
        for (int k = 0; k < m; k++) {
            sum += matr[i][k] * matr_t[k][j];
        }
        matr_end[i][j] = sum;
    }
}

void InputMatrD(int **matr, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf_s("%d", &matr[i][j]);
}

void OutputMatrD(int **matr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf(" %d ", matr[i][j]);
        printf("\n");
    }
}

int DelStr(int** matr, int m, int n, int k) {
    for (int i = k; i < m - 1; i++) for (int j = 0; j < n; j++) matr[i][j] = matr[i + 1][j];
    return --m;
}

int DelStr_WR(int** matr, int m, int n, int k) {
    delete[] matr[k];
    for (int i = k; i < m - 1; i++) matr[i] = matr[i + 1];
    return --m;
}