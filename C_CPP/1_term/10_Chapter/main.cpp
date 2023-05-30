#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "tmcor_c_lib.cpp"
#include <locale.h>
#include <Windows.h>

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char s[1000];
    printf("Напишите предложение:\n");
    gets_s(s);
    char** words;
    words = new char* [100];
    if (words == NULL) return 0;

    int num_str = CreateStrings(words, s);

    for (int i = 0; i < num_str; i++) {
        bool find_str = false;
        for (int j = i+1; j < num_str; j++) {
            if (isSameStr(words[i], words[j])) {
                num_str = DelStr_WR_str(words, num_str, j);
                find_str = true;
                j--;
            }
        }
        if(find_str){
            num_str = DelStr_WR_str(words, num_str, i);
            i--;
        }
    }

    for (int i = 0; i < num_str; i++) {
        puts(words[i]);
    }
    for (int i = 0; i < num_str; i++) {
        delete[] words[i];
    }
    delete[] words;
	return 0;
}
