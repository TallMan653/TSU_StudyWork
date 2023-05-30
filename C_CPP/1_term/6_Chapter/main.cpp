#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tmcor_c_lib.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int *mas1, *mas2, *mas3, n1, n2,cur_mas3 = 0;
	printf("¬ведите количество элементов первого массива: ");
    scanf_s("%d", &n1);
    printf("¬ведите количество элементов второго массива: ");
    scanf_s("%d",&n2);
    mas1 = new int[n1];
    mas2 = new int[n2];
    if (mas1==NULL || mas2== NULL) return -1;
    printf("¬ведите элементы первого массива:\n");
	ReadMas(mas1, n1);
    printf("¬ведите элементы второго массива:\n");
	ReadMas(mas2, n2);
    printf("ѕервый массив:\n");
    PrintMas(mas1, n1);
    printf("¬торой массив:\n");
    PrintMas(mas2, n2);
    

    mas3 = new int[MinInt(n1,n2)];
    if (mas3 == NULL) return -1;

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(mas1[i]==mas2[j]) mas3[cur_mas3++]=mas1[i];
        }
    }
    printf("“ретий массив (пересечени€):\n");
    PrintMas(mas3, cur_mas3);
    delete[] mas1; 
    delete[] mas2; 
    delete[] mas3; 
}