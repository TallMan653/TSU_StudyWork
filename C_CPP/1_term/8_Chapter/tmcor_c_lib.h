#pragma once
void ReadMas(int* mas, int n);
void PrintMas(int* mas, int n);
int MaxPtr(int* a, int n);
int MinPtr(int* a, int n);
int MaxInt(int x, int y);
int MinInt(int x, int y);
bool Mono(int* mas, int n, int min, int max);
void InputMatr(float matr[][50], int m, int n);
void OutputMatr(float matr[][50], int m, int n);
void SetTransMatr(float matr[][50], float matr_t[][50], int n, int m);
bool IsScalarMatr(float matr[][50], int m, int n, int c = 1);
void ComposMatr(float matr[][50], float matr_t[][50], float matr_end[][50], int n, int m);
void InputMatrD(int** matr, int m, int n);
void OutputMatrD(int** matr, int m, int n);
int DelStr(int** matr, int m, int n, int k);
int DelStr_WR(int** matr, int m, int n, int k);