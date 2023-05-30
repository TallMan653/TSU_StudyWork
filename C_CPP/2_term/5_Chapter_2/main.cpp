#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.cpp"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	clock_t start1,start2,start3, stop1,stop2,stop3;
	double T1, T2,T3;
	int *a_arr,*b_arr, *c_arr, n;
	printf("Введите количество чисел:");
	scanf_s("%d",&n);
	getchar();

	a_arr = new int[n];
	b_arr = new int[n];
	c_arr = new int[n];
	if (a_arr == NULL || b_arr == NULL || c_arr == NULL) return 0;
	for (int i = 0; i < n; i++){
		int k = IntRandom(-100,100);
		a_arr[i] = b_arr[i] = c_arr[i] = k;
	}
	if(n <=30){
		PrintMas(a_arr,n);
	}

	start1 = clock();
	insertionSort(a_arr,0,n-1);
	stop1 = clock();

	start2 = clock();
	BinaryInsertionSort(b_arr,n);
	stop2 = clock();

	start3 = clock();
	timSort(c_arr,n);
	stop3 = clock();

	T1 = (double) (stop1-start1)/CLOCKS_PER_SEC;
	T2 = (double) (stop2-start2)/CLOCKS_PER_SEC;
	T3 = (double) (stop3-start3)/CLOCKS_PER_SEC;
	
	printf("Время выполнения кода t1=%lf\n",T1);
	printf("Время выполнения кода t2=%lf\n",T2);
	printf("Время выполнения кода t3=%lf\n",T3);
	if(n <=30){
		PrintMas(a_arr,n);
		PrintMas(b_arr,n);
		PrintMas(c_arr,n);
	}
	delete[]a_arr;
	delete[]b_arr;
	delete[]c_arr;
	return 1;
}
