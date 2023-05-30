#include <stdio.h>
#include <stdlib.h>
#include "tmcor_c_lib.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int a[50], n;
    printf("Введите n (n<50): ");
    scanf_s("%d", &n);
    printf("Введите значение элеметнов, через enter\n");
    ReadMas(a, n);
    printf("\nМассив: ");
    PrintMas(a, n);
    if (MonoMas(a, n)) printf("Является монотонной последовательностью");
    else printf("Не является монотонной последовательностью");
}