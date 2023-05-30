#pragma once
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#define UI unsigned int
//-Математический модуль-



//Нахождение максимального элемента среди двух аргументов
int IntMax(int x, int y);

//Нахождение минимального элемента среди двух аргументов
int IntMin(int x, int y);

//Псевдослучайное число в диапозоне от x до y
int IntRandom(int x, int y);


//Нахождение максимального элемента(индекс) среду массива чисел
int MaxPtr(int* mas, int n);

//Нахождение минимального элемента(индекс) среду массива чисел
int MinPtr(int* mas, int n);

//Определение монотонности массива
bool Mono(int* mas, int n, int min = 0, int max = 0);

//Определяет скалярна ли матрица, n и m - размеры, c - число по диоганали
bool IsScalarMatr(float matr[][50], int m, int n, int c = 1);

//Умножение двух матриц n и m - размеры
void ComposMatr(float matr[][50], float matr_t[][50], float matr_end[][50], int n, int m);

//Транспонирование матриц, в первый аргумент вводится сама матрица во второй матрица в которую будет записанные новые данные, n и m - размеры
void SetTransMatr(float matr[][50], float matr_t[][50], int n, int m);

//Определения веса вектора
int WeightVec(UI x, int n);


// Модуль функций для таблиц/массивов/строк


//Запись массива чисел
void ReadMas(int* mas, int n);

//Вывод массива чисел
void PrintMas(int* mas, int n);

//Запись матрицы чисел
void InputMatr(float matr[][50], int m, int n);

//Вывод матрцы исел
void OutputMatr(float matr[][50], int m, int n);

//Сдвиг влево для массива чисел
void ShiftLeft_k(int a[], int n, int p = 0, int k = 1);

//Запись динамического массива
void InputMatrD(int** matr, int m, int n);

//Вывод динамического массива
void OutputMatrD(int** matr, int m, int n);

//Удаление строки
int DelStr(int** matr, int m, int n, int k);

//Удаление строки
int DelStr_WR(int** matr, int m, int n, int k);

//Сдвиг влево для массива строк
void ShiftLeft_k_str(char a[], int n, int p = 0, int k = 1);

//Есть ли символ в этой строке
bool char_onstr(char str[], char k);

//Удаление слова в строке
void str_delchars(char str[], char del_str[]);

//Поиск не слов
int FindNoWords(char s[], int i = 0);

//Строка та же самая?
bool isSameStr(char s[], char s1[]);

//Создание строки
int CreateStrings(char** words, char s[]);

//Удаление строки в массиве слов
int DelStr_WR_str(char** matr, int m, int k);

//Создание случайно строки
void CreateRandomString(char* word, int n);

//Проверяет символ является ли он гласным
bool ThisIsVowel(char c);

//Бинарный поиск
int BinFindK(int *bm, int low, int high, int k);

//Поиск Бойра-Мура
int BMSRTSearch(char *str, char *pat);

//Сортировка пузырьком
void SortByBooble(int *a, int n);

//Поменять элементы
void Swap(int *a, int *b);

//Сортировка методом Тима
void timSort(int arr[], int n);


//Модуль для работы с булевыми векторами


//Установка в булевом векторе элемента на 1
UI SetUPTrue(UI x, int k);

//Ввод булевого вектора
UI InputBVec(char s[], int n);

//Вывод булевого вектора
void OutputBVec(UI x, int n);

//Подсчет разнозначемых элементов в двух булевых векторах
int difElBVec(UI x, UI y, int n);

//Ввод булевой матрицы
void InputBMVec(UI* bm, int m, int n);

//Ввод случайной булевой матрицы
void InputRandomBMVec(UI* bm, int m, int n);

//Вывод булевой матрицы
void OutputBMVec(UI* bm, int m, int n);

//Сортировка массива по весу (первый самый минимальный)
void SortBMVecByWeightDown(UI* bm, int m, int n);

//Модуль для работы с файлами


//Создание файла со случайными числами
void CreateFilewithRandomNumber(const char* name, int n, int lf, int rt);

//Чтение файла из цифр
void PrintFileNumb(const char* name);

//Сортировка файла из чисел методом естественным слиянием
void SortFileNumbWNM(const char* name);

//Проверка на пустату файла
bool ClearFileCheck(const char* name);