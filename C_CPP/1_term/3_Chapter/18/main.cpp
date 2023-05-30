#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "rus");
    int m;
    long double k, n, s=0,s1=1,sd=0;
    printf("¬ведите число m: ");
    scanf_s("%d", &m);
    for (k = 1; k <= m; k++) {
        s1 = 1;
        s = 0;
        for (n = 1; n <= k; n++) s += sin(k * n);
        for (int t = 1; t <= k; t++) s1 *= t;
        sd += s / s1;
    }
    printf("S = %.16Lf", sd);
    
    return 0;
}