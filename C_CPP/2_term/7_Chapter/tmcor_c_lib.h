#pragma once
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#define UI unsigned int
//-�������������� ������-
struct Student {
    char fam[20], name[20];
    int group, mark[3];
};
struct Usel { int key; Usel* next; };
struct FUsel { float key; FUsel* next; };
struct Stack {
	Usel* head;
	Stack() { head = 0; };
	~Stack() { Clear(); };
	void Push(int k);
	int Pop();
	int Top();
	bool Empty();
	void Clear();
};
struct FStack {
	FUsel* head;
	FStack() { head = 0; };
	~FStack() { Clear(); };
	void Push(float k);
	float Pop();
	float Top();
	bool Empty();
	void Clear();
};

//���������� ������������� �������� ����� ���� ����������
int IntMax(int x, int y);

//���������� ������������ �������� ����� ���� ����������
int IntMin(int x, int y);

//��������������� ����� � ��������� �� x �� y
int IntRandom(int x, int y);


//���������� ������������� ��������(������) ����� ������� �����
int MaxPtr(int* mas, int n);

//���������� ������������ ��������(������) ����� ������� �����
int MinPtr(int* mas, int n);

//����������� ������������ �������
bool Mono(int* mas, int n, int min = 0, int max = 0);

//���������� �������� �� �������, n � m - �������, c - ����� �� ���������
bool IsScalarMatr(float matr[][50], int m, int n, int c = 1);

//��������� ���� ������ n � m - �������
void ComposMatr(float matr[][50], float matr_t[][50], float matr_end[][50], int n, int m);

//���������������� ������, � ������ �������� �������� ���� ������� �� ������ ������� � ������� ����� ���������� ����� ������, n � m - �������
void SetTransMatr(float matr[][50], float matr_t[][50], int n, int m);

//����������� ���� �������
int WeightVec(UI x, int n);


// ������ ������� ��� ������/��������/�����


//������ ������� �����
void ReadMas(int* mas, int n);

//����� ������� �����
void PrintMas(int* mas, int n);

//������ ������� �����
void InputMatr(float matr[][50], int m, int n);

//����� ������ ����
void OutputMatr(float matr[][50], int m, int n);

//����� ����� ��� ������� �����
void ShiftLeft_k(int a[], int n, int p = 0, int k = 1);

//������ ������������� �������
void InputMatrD(int** matr, int m, int n);

//����� ������������� �������
void OutputMatrD(int** matr, int m, int n);

//�������� ������
int DelStr(int** matr, int m, int n, int k);

//�������� ������
int DelStr_WR(int** matr, int m, int n, int k);

//����� ����� ��� ������� �����
void ShiftLeft_k_str(char a[], int n, int p = 0, int k = 1);

//���� �� ������ � ���� ������
bool char_onstr(char str[], char k);

//�������� ����� � ������
void str_delchars(char str[], char del_str[]);

//��������, �������� �� ������ ������
bool str_number(char s);

//��������, �������� �� ������ ��������� ������
bool str_large(char s);

//��������, �������� �� ������ �������� ������
bool str_small(char s);

//����� �� ����
int FindNoWords(char s[], int i = 0);

//������ �� �� �����?
bool isSameStr(char s[], char s1[]);

//�������� ������
int CreateStrings(char** words, char s[]);

//�������� ������ � ������� ����
int DelStr_WR_str(char** matr, int m, int k);

//�������� �������� ������
void CreateRandomString(char* word, int n);

//��������� ������ �������� �� �� �������
bool ThisIsVowel(char c);

//�������� �����
int BinFindK(int *bm, int low, int high, int k);

//����� �����-����
int BMSRTSearch(char *str, char *pat);

//���������� ���������
void SortByBooble(int *a, int n);

//�������� ��������
void Swap(int *a, int *b);

//���������� ������� ����
void timSort(int arr[], int n);

// ���������� ��������
void insertionSort(int arr[], int left, int right);

//���������� �������� � �������� �������
void BinaryInsertionSort(int *a, int n);




//������ ��� ������ � �������� ���������


//��������� � ������� ������� �������� �� 1
UI SetUPTrue(UI x, int k);

//���� �������� �������
UI InputBVec(char s[], int n);

//����� �������� �������
void OutputBVec(UI x, int n);

//������� ������������� ��������� � ���� ������� ��������
int difElBVec(UI x, UI y, int n);

//���� ������� �������
void InputBMVec(UI* bm, int m, int n);

//���� ��������� ������� �������
void InputRandomBMVec(UI* bm, int m, int n);

//����� ������� �������
void OutputBMVec(UI* bm, int m, int n);

//���������� ������� �� ���� (������ ����� �����������)
void SortBMVecByWeightDown(UI* bm, int m, int n);



//������ ��� ������ � �������


//�������� ����� �� ���������� �������
void CreateFilewithRandomNumber(const char* name, int n, int lf, int rt);

//������ ����� �� ����
void PrintFileNumb(const char* name);

//���������� ����� �� ����� ������� ������������ ��������
void SortFileNumbWNM(const char* name);

//�������� �� ������� �����
bool ClearFileCheck(const char* name);




//������ �� �����������


//���� ������ ��������
Student InputStudent();

//����� ������ ��������
void OutputStudent(Student st);

//��������� ���� � ������� ��������
void ReadFileStudent(const char* name, Student potok[], int n);

//�������� � ���� ������ ��������
void AddFileStudent(const char* name, int n);

//�������� � ���� ������ �������� (��� ����������)
void AddFileStudentWOSort(const char* name, int n);

//�������� ��������� �� �������
void ShowMarkStudent(Student kurs[], int n);

//�������� ��������� �� ������� (����������)
void ShowMarkLastNameStudent(Student kurs[], int n, bool first = true);



//������ �� ������

//��������� 
int Prioritet(char s);

//������� � �����
void toRPN(char p[], int Tab[]);

//����� �� �����
void fromRPN(char p[], int Tab[]);