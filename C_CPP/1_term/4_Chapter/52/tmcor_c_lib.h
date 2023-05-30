#pragma once
// ������� ��������� ������������ ��������� ������ ������
void ReadMas(int* mas, int n);
// ������� ������������ ������� ��������� ����� � ��������� �� lf �� rt
void RandMas(int* mas, int n, int lf, int rt);
// ������� ������ ������� �� ������
void PrintMas(int* mas, int n, bool ignore = false);
// ������� �������� ������� � lf, rt ���� ���� ������ ��� �� �������� ��������� ���� ����������
void NullMas(int* mas, int n, int lf = 0, int rt = 0);
// ������� ���������� ���������� ������� 
bool MonoMas(int* mas, int n, int lf = 0, int rt = 0);
//������� �������� �������, saveset ����� �� ��������� ������ ������� ��� ������, lf � rt ������ � ���������� ��������� ��� ������
void ClearDup(int* mas, int n, int lf = 0, int rt = 0);
//������� ��������� �� ������� ���������
void MoveMas(int* mas, int n, bool l = false, int lf = 0, int rt = 0);
