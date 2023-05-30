#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "tmcor_c_lib.h"
using namespace std;

int main()
{
	int n;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student* kurs;
	cout << "Введите количество студентов: ";
	cin >> n;
	AddFileStudent("data.txt", n);

	kurs = new Student[n];
	if (kurs == NULL) return -1;
	ReadFileStudent("data.txt", kurs, n);
	ShowMarkStudent(kurs, n);
	delete[]kurs;
}