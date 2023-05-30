#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#define UI unsigned int
// Математический модуль

int IntMax(int x, int y) {
    if (x > y) return x;
    return y;
}

int IntMin(int x, int y) {
    if (x < y) return x;
    return y;
}

int IntRandom(int x, int y) {
    if (y > x) return rand() % (y - x + 1) + x;
    return -1;
}
int MaxPtr(int* mas, int n) {
    int* i_max, * p;
    for (i_max = mas, p = mas + 1; p < mas + n; p++) if (*p > *i_max) i_max = p;
    return i_max - mas;
}

int MinPtr(int* mas, int n) {
    int* i_min, * p;
    for (i_min = mas, p = mas + 1; p < mas + n; p++) if (*p < *i_min) i_min = p;
    return i_min - mas;
}

bool Mono(int* mas, int n, int min = 0, int max = 0) {
    if (max == 0) max = n;
    int* c_min = mas + min;
    int* c_max = mas + max;
    int ras = c_min - (c_min + 1);
    for (; c_min < c_max; c_min++) {
        if (c_min - (c_min + 1) == 0) continue;
        if (ras != c_min - (c_min + 1)) {
            return false;
            break;
        }
    }
    return true;
}

bool IsScalarMatr(float matr[][50], int m, int n, int c = 1) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matr[i][j] != c) || (i != j && matr[i][j] != 0)) {
                return false;
                break;
            }
        }
    }
    return true;
}

void ComposMatr(float matr[][50], float matr_t[][50], float matr_end[][50], int n, int m) {
    int sum;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        sum = 0;
        for (int k = 0; k < m; k++) {
            sum += matr[i][k] * matr_t[k][j];
        }
        matr_end[i][j] = sum;
    }
}

void SetTransMatr(float matr[][50], float matr_t[][50], int n, int m) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) matr_t[j][i] = matr[i][j];
}

int WeightVec(UI x, int n) {
    int count = 0;
    UI mask = 1;
    for (int i = 0; i < n; i++, mask <<= 1)
        if (x & mask) count++;
    return count;
}


// Модуль функций для таблиц/массивов/строк

void ReadMas(int* mas, int n) {
    for (int* p = mas; p < mas + n; p++) scanf_s("%d", p);
}

void PrintMas(int* mas, int n) {
    for (int* p = mas; p < mas + n; p++) printf("%4d", *p);
    printf("\n");
}

void InputMatr(float matr[][50], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf_s("%f", &matr[i][j]);
}

void OutputMatr(float matr[][50], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf(" %.3f ", matr[i][j]);
        printf("\n");
    }
}
void ShiftLeft_k(int a[], int n, int p = 0, int k = 1) {
    for (int i = p; i < n - k; i++) a[i] = a[i + k];
}

void InputMatrD(int** matr, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf_s("%d", &matr[i][j]);
}

void OutputMatrD(int** matr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf(" %d ", matr[i][j]);
        printf("\n");
    }
}

int DelStr(int** matr, int m, int n, int k) {
    for (int i = k; i < m - 1; i++) for (int j = 0; j < n; j++) matr[i][j] = matr[i + 1][j];
    return --m;
}

int DelStr_WR(int** matr, int m, int n, int k) {
    delete[] matr[k];
    for (int i = k; i < m - 1; i++) matr[i] = matr[i + 1];
    return --m;
}

void ShiftLeft_k_str(char a[], int n, int p = 0, int k = 1) {
    for (int i = p; i < n - k; i++) a[i] = a[i + k];
}

bool char_onstr(char str[], char k) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == k) {
            return true;
        }
    }
    return false;
}

void str_delchars(char str[], char del_str[]) {
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(del_str); j++) {
            if (str[i] == del_str[j]) {
                ShiftLeft_k_str(str, strlen(str), i);
                str[strlen(str) - 1] = '\0';
            }
        }
    }
}

int FindNoWords(char s[], int i = 0) {
    for (; s[i] && (s[i] == ' ' || s[i] == ','); i++);
    return i;
}

bool isSameStr(char s[], char s1[]) {
    if (strlen(s) == strlen(s1)) {
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] != s1[i]) return false;
        }
        return true;
    }
    return false;
}

int CreateStrings(char** words, char s[]) {
    int num_str = 0, j;
    for (int i = 0; s[i] != '.';) {
        i = FindNoWords(s, i);
        words[num_str] = new char[20];
        for (j = 0; s[i] != '.' && s[i] != ','; i++, j++) {
            words[num_str][j] = s[i];
        }
        words[num_str][j] = '\0';
        num_str++;
    }
    return num_str;
}

int DelStr_WR_str(char** matr, int m, int k) {
    delete[] matr[k];
    for (int i = k; i < m - 1; i++) matr[i] = matr[i + 1];
    return --m;
}

void CreateRandomString(char* word, int n) {
    int b = 0;
    for (int i = 0; i < n; i++) {
        do {
            b = IntRandom(65, 122);
        } while (b > 90 && b < 97);
        word[i] = b;
    }
    word[n] = '\0';
}

bool ThisIsVowel(char c) {
    char glas[] = { 'A','a','E','e','I','i','Y','y','U','u', 'O', 'o' };
    for (int i = 0; glas[i]; i++) {
        if (c == glas[i]) return true;
    }
    return false;
}
//Модуль для работы с булевыми векторами

UI SetUPTrue(UI x, int k) {
    UI mask = 1;
    mask <<= k;
    x |= mask;
    return x;
}

UI InputBVec(char s[], int n) {
    UI x = 0;
    for (int i = 0; i < n; i++) if (s[i] == '1') x = SetUPTrue(x, n - 1 - i);
    return x;
}
void OutputBVec(UI x, int n) {
    UI mask = 1;
    mask <<= n - 1;
    for (int i = 0; i < n; i++, mask >>= 1) {
        if (x & mask) printf("1");
        else printf("0");
    }
    printf("\n");
}

int difElBVec(UI x, UI y, int n) {
    int count = 0;
    UI mask = 1;
    for (int i = 0; i < n; i++, mask <<= 1)
        if ((x & mask) != (y & mask)) count++;
    return count;
}

void InputBMVec(UI* bm, int m, int n) {
    char s[33];
    for (int i = 0; i < m; i++) {
        gets_s(s);
        bm[i] = InputBVec(s, n);
    }
}
void InputRandomBMVec(UI* bm, int m, int n) {
    for (int i = 0; i < m; i++) {
        bm[i] = IntRandom(0, pow(2, n));
    }
}

void OutputBMVec(UI* bm, int m, int n) {
    for (int i = 0; i < m; i++) {
        OutputBVec(bm[i], n);
    }
    printf("\n");
}

void SortBMVecByWeightDown(UI* bm, int m, int n) {
    UI mask;
    int minpos;
    for (int curPos = 0; curPos < m - 1; curPos++) {
        mask = bm[curPos];
        minpos = curPos;

        for (int i = curPos + 1; i < m; i++) {
            if (WeightVec(mask, n) >= WeightVec(bm[i], n) && (WeightVec(bm[minpos], n) >= WeightVec(bm[i], n)))
                minpos = i;
        }

        bm[curPos] = bm[minpos];
        bm[minpos] = mask;
    }
}

//Модуль для работы с файлами

void CreateFilewithRandomNumber(const char* name, int n, int lf, int rt) {
    int x;
    FILE* f;
    errno_t f_err = fopen_s(&f, name, "w");
    if (f_err) {
        printf("Ошибка при создание файла");
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        x = IntRandom(lf, rt);
        fprintf(f, "%d ", x);
    }
    fclose(f);
}
void PrintFileNumb(const char *name) {
    FILE* f;
    int x;
    errno_t f_err = fopen_s(&f, name, "r");
    if (f_err) {
        printf("Ошибка при чтение файла");
        exit(-1);
    }

    while (fscanf_s(f, "%d", &x) != EOF) printf("%d ", x);
}