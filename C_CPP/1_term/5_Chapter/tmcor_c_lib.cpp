#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ReadMas(int* mas, int n) {
    for (int* p = mas; p < mas + n; p++) scanf_s("%d", p);
}

void PrintMas(int* mas, int n){
    for (int* p = mas; p < mas + n; p++) printf("%4d", *p);
    printf("\n");
}

int MaxPtr(int* mas, int n){
    int *i_max, *p;
    for (i_max = mas, p = mas + 1; p < mas + n; p++) if (*p > *i_max) i_max = p;
    return i_max - mas;
}

int MinPtr(int* mas, int n){
    int *i_min, *p;
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

bool Mono(int* mas, int n, int min=0, int max=0) {
    int ras = *(mas+min)-*(mas+min+1);
    if (max == 0) max = n;
    for (; min < max ; min++) {
        if (*(mas+min)-*(mas+min+1) == 0) continue;
        if (ras != (*(mas + min) - *(mas + min + 1))) {
            return false;
            break;
        }
    }
    return true;
}