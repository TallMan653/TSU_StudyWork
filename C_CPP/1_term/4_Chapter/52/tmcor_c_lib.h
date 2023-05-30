#pragma once
// функция позволяет пользователю заполнить самому массив
void ReadMas(int* mas, int n);
// функция формирования массива случайных чисел в диапазоне от lf до rt
void RandMas(int* mas, int n, int lf, int rt);
// функция вывода массива на печать
void PrintMas(int* mas, int n, bool ignore = false);
// функция обнуляет участок с lf, rt либо весь массив при не указание последних двух аргументов
void NullMas(int* mas, int n, int lf = 0, int rt = 0);
// функция определяет монтоность массива 
bool MonoMas(int* mas, int n, int lf = 0, int rt = 0);
//функция сдвигает массива, saveset нужно ли сохранять первый элемент при сдвиге, lf и rt начало и количество элеметнов для сдвига
void ClearDup(int* mas, int n, int lf = 0, int rt = 0);
//функция исключает из массива дубликаты
void MoveMas(int* mas, int n, bool l = false, int lf = 0, int rt = 0);
