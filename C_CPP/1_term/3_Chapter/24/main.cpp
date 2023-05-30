#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "rus");
    int m, c, k;
    printf("Введите число: ");
    scanf_s("%d", &m);
    for (k = 1; m > 1;k++) {
        c = 2;
        for (; m % c != 0; c++);
        m = m / c;
        //printf("%d\n", c);
    }
    printf("Количество простых множотилей: %d", k-1);

    return 0;
}