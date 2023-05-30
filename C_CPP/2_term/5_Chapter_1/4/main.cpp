#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include "tmcor_c_lib.cpp"
#include <Windows.h>

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	srand(time(NULL));
	char p[40];
    char s[120];
    gets_s(s);
    gets_s(p);
    printf("%d", BMSRTSearch(s,p));
	return 1;
}