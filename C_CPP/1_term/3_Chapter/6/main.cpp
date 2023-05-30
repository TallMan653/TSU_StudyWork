#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "rus");
    int n,m;
    long double s = 0,p, i, j;
    printf("¬ведите число n: ");
    scanf_s("%d", &n);
    printf("¬ведите число m: ");
    scanf_s("%d", &m);
    for (i = 1; i <= n; i++) {
        p = 1;
        for (j = i; j <= m; j++) p *= (j * j) / (2 * j + i * i * i);
        s += p;
    }
    printf("S = %.16Lf", s);

    return 0;
}