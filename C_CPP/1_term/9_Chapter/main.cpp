#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "tmcor_c_lib.h"
#include <locale.h>
#include <Windows.h>

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char str[80], del_str[80];
    printf("Введите исходную строку:\n");
    gets_s(str);
    printf("Введите символы которые нужно исключить:\n");
    gets_s(del_str);
    printf("Строка после иключение символов:\n");
    str_delchars(str, del_str);
    puts(str);

	return 0;
}