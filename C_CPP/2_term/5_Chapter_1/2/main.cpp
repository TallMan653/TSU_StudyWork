#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.h"

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int *bm, n,k,fk;
	printf("������� ���������� �����:");
	scanf_s("%d",&n);
	getchar();
	bm = new int[n];
	if (bm == NULL) return 0;
	for (int i = 0; i < n; i++){
		bm[i] = IntRandom(-100,100);
	}
	timSort(bm,n);
	PrintMas(bm,n);
	printf("������� k:");
	scanf_s("%d",&k);
	getchar();
	fk = BinFindK(bm,0,n-1,k);
	if(fk != -1) printf("������� �� %d",fk);
	else printf("�� �������");
	

	delete[]bm;

	return 1;
}
