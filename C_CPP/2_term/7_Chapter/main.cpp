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
	setlocale(LC_ALL, "rus");
	char p[80];
	int Tab[256];
	toRPN(p, Tab);
	fromRPN(p, Tab);
	return 0;
}