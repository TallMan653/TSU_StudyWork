#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"
int main() {
    char s1[32] = "";
    char s2[32] = "";
    setlocale(LC_ALL, "Rus");
    printf("¬ведите первый булевый вектор: ");
    gets_s(s1);
    UI x = InputBVec(s1, strlen(s1));

    printf("¬ведите второй булевый вектор: ");
    gets_s(s2);
    UI y = InputBVec(s2, strlen(s2));

    OutputBVec(x, strlen(s1));
    OutputBVec(y, strlen(s2));

    printf("%d", difElBVec( x, y, IntMax(strlen(s1),strlen(s2))));

    return 1;
}