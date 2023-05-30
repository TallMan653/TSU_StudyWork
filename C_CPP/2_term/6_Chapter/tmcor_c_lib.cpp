#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>

#define UI unsigned int
using namespace std;


struct Student {
    char fam[20], name[20];
    int group, mark[3];
};
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
    for (int* p = mas; p < mas + n; p++) printf("%d ", *p);
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

int CreateStringsV1(char** words, char s[]) {
    int number = 0, j;
    for (int i = 0; s[i];) {
        int j;
        i = FindNoWords(s, i);
        words[number] = new char[20];
        for (j = 0; s[i] && s[i] != ' '; i++, j++) {
            words[number][j] = s[i];
        }
        words[number][j] = '\0';
        number++;
    }
    return number;
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
    char b = 0;
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

int BinFindK(int *bm, int low, int high, int k){
    int middle;
    while (low <= high){
		middle = (low + high) / 2;
		if(k < bm[middle]){
			high = middle-1;
		}
        else if(k > bm[middle]){
			low = middle+1;
		}
        else{
			return middle;
		}
	}
    return -1;
}
void CharHeuristic(char *str, int tab[]){
    int m = strlen(str);
    for (int i = 0; i < 256; i++)
        tab[i] = m;
    for (int i = 0; i < m; i++)
        tab[(int) str[i]] = i;
}
int BMSRTSearch(char *str, char *pat){
    int m = strlen(pat);
    int n = strlen(str);
    int tab[256];
    CharHeuristic(pat, tab);
    int s = 0;
    while (s <= (n - m)){
        int j = m - 1;
        while (j >= 0 && pat[j] == str[s + j])
            j--;
        if (j < 0){
            return s;
        }
        else s += j-tab[str[s + j]];
    }
    return -1;
}
void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SortByBooble(int *a, int n){
    for(int k = n-1;k>0;k--){
        for(int i = 0; i<k;i++) if(a[i] > a[i+1]) Swap(&a[i],&a[i+1]);
    }
}
void insertionSort(int *arr, int left, int right){
    for (int i = left + 1; i <= right; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] >= temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int BinFindPos(int *bm, int low, int high, int k){
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(k < bm[mid]) high = mid-1;
        else low = mid+1;
    }
    return low;
}
void BinaryInsertionSort(int *a, int n){
    for(int i = 1;i<n;++i){
        int key = a[i];
        int pos = BinFindPos(a,0,i-1,key);
        for(int j = i-1;j>=pos;--j){
            a[j+1] = a[j];
        }
        a[pos] = key;
    }
}
const int RUN = 32;
void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m,*left, *right;

    left = new int[len1];
    right = new int[len2];
    if(left == NULL || right == NULL) exit(-1);

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1){
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2){
        arr[k] = right[j];
        k++;
        j++;
    }
    delete[] left;
    delete[] right; 
}
 
void timSort(int arr[], int n)
{
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, IntMin((i+RUN-1), (n-1)));
    for (int size = RUN; size < n; size = 2*size){
        for (int left = 0; left < n; left += 2*size){
            int mid = left + size - 1;
            int right = IntMin((left + 2*size - 1), (n-1));
            if(mid < right) merge(arr, left, mid, right);
        }
    }
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
void PrintFileNumb(const char* name) {
    FILE* f;
    int x;
    errno_t f_err = fopen_s(&f, name, "r");
    if (f_err) {
        printf("Ошибка при чтение файла");
        exit(-1);
    }

    while (fscanf_s(f, "%d", &x) != EOF) printf("%d ", x);
    printf("\n");
    fclose(f);
}


void SortFileNumbWNMAtoB(const char* name) {
    FILE* f, * d1, * d2;
    int x, y;
    bool flag = true;
    errno_t f_err = fopen_s(&f, name, "r");
    errno_t d1_err = fopen_s(&d1, "d1.txt", "w");
    errno_t d2_err = fopen_s(&d2, "d2.txt", "w");
    if (f_err || d1_err || d2_err) {
        printf("Ошибка при чтение файла");
        exit(-1);
    }
    fscanf_s(f, "%d ", &y);
    fprintf(d1, "%d ", y);
    while (fscanf_s(f, "%d", &x) != EOF) {
        if (y > x) flag = !flag;
        if (flag) fprintf(d1, "%d ", x);
        else fprintf(d2, "%d ", x);
        y = x;
    }
    fclose(f);
    fclose(d1);
    fclose(d2);
}
void SortFileNumbWNMBtoA(const char* name) {
    FILE* f, * d[2];
    int n, x[2], y[2];
    errno_t f_err = fopen_s(&f, name, "w");
    errno_t d1_err = fopen_s(&d[0], "d1.txt", "r");
    errno_t d2_err = fopen_s(&d[1], "d2.txt", "r");

    if (f_err || d1_err || d2_err) {
        printf("Ошибка при чтение файла");
        exit(-1);
    }
    fscanf_s(d[0], "%d", &x[0]);
    fscanf_s(d[1], "%d", &x[1]);
    while (!feof(d[0]) && !feof(d[1])) {
        if (x[0] < x[1]) n = 0;
        else n = 1;
        fprintf(f, "%d ", x[n]);
        fscanf_s(d[n], "%d", &y[n]);
        if (!feof(d[n]) && x[n] <= y[n]) x[n] = y[n];
        else
        {
            fprintf(f, "%d ", x[1 - n]);
            fscanf_s(d[1 - n], "%d", &y[1 - n]);
            while (!feof(d[1 - n]) && x[1 - n] <= y[1 - n])
            {
                x[1 - n] = y[1 - n];
                fprintf(f, "%d ", x[1 - n]);
                fscanf_s(d[1 - n], "%d", &y[1 - n]);
            }
            x[0] = y[0];
            x[1] = y[1];
        }
    }
    while (!feof(d[0]))
    {
        fprintf(f, "%d ", x[0]);
        fscanf_s(d[0], "%d", &x[0]);
    }
    while (!feof(d[1]))
    {
        fprintf(f, "%d ", y[1]);
        fscanf_s(d[1], "%d", &y[1]);
    }
    fclose(f);
    fclose(d[0]);
    fclose(d[1]);
}
bool ClearFileCheck(const char* name) {
    FILE* fp;
    int x;
    errno_t fp_err = fopen_s(&fp, name, "r");
    if (fp_err) {
        printf("Ошибка при чтение файла");
        exit(-1);
    }
    if (fscanf_s(fp, "%d", &x) == EOF) {
        fclose(fp);
        return false;
    }
    fclose(fp);
    return true;
}
void SortFileNumbWNM(const char* name) {
    do {
        SortFileNumbWNMAtoB(name);
        SortFileNumbWNMBtoA(name);
    } while (ClearFileCheck("d2.txt"));
}


Student InputStudent() {
    Student st;
    int i;
    cout << "Введите:\nФамилию, имя: ";
    cin >> st.fam >> st.name;
    cout << "Группу: ";
    cin >> st.group;
    cout << "Оценки: ";
    for (i = 0; i < 3; i++) cin >> st.mark[i];
    return st;
}

void OutputStudent(Student st) {
    cout << "ФИ: " << st.fam << " " << st.name << endl << "Группа: " << st.group << endl << "Оценки: ";
    for (int i = 0; i < 3; i++) cout << st.mark[i] << " ";
    cout << endl;
}
void ReadFileStudent(const char* name, Student potok[], int n) {
    FILE* f;
    int i = 0;
    errno_t fp_err = fopen_s(&f, name, "r");
    if (fp_err) {
        cout << "Ошибка при чтение файла";
        exit(-1);
    }
    while (fscanf_s(f, "%s", potok[i].fam, 20) != EOF) {
        fscanf_s(f, "%s", potok[i].name, 20);
        fscanf_s(f, "%d", &(potok[i].group));
        for (int k = 0; k < 3; k++) {
            fscanf_s(f, "%d", &(potok[i].mark[k]));
        }
        i++;
    }
    fclose(f);
}
int cmpf(const void* _a, const void* _b) {
    Student* a = (Student*)_a;
    Student* b = (Student*)_b;
    return strcmp(a->fam, b->fam);
}
void AddFileStudent(const char* name, int n) {
    FILE* f;
    Student* t;
    errno_t fp_err = fopen_s(&f, name, "w");
    t = new Student[n];
    for (int i = 0; i < n; i++) {
        t[i] = InputStudent();
    }
    qsort(t, n, sizeof(Student), cmpf);
    if (fp_err) {
        cout << "Ошибка при чтение файла";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s %s %d ", t[i].fam, t[i].name, t[i].group);
        for (int j = 0; j < 3; j++) {
            fprintf(f, "%d ", t[i].mark[j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    delete[] t;
}


void ShowMarkStudent(Student kurs[], int n) {
    char str[20];
    cout << "Введите фамилию, для поиска оценок: ";
    cin >> str;
    int k = -1;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        k = -1;
        if (strcmp(kurs[i].fam, str) == 0) {
            for (int t = i + 1; t < n && (strcmp(kurs[i].fam, kurs[t].fam) == 0); t++) {
                if (!flag) cout << "Найдено несколько студентов, с такой фамилией" << endl << t - i << ". " << kurs[i].name << endl;
                flag = true;
                cout << t - i + 1 << ". " << kurs[t].name << endl;
            }
            if (flag) {
                cout << "выбирите нужную цифру, рядом с именим: ";
                cin >> k;
                k += i - 1;
                break;
            }
            else k = i;
        }
    }
    if (k == -1) {
        cout << "Не найдено" << endl;
    }
    else {
        cout << kurs[k].fam << " " << kurs[k].name << endl << "Оценки: ";
        for (int j = 0; j < 3; j++) {
            cout << kurs[k].mark[j] << " ";
        }
        cout << endl;
    }
}


void ShowMarkLastNameStudent(Student kurs[], int n, bool first = true) {
    char str[20];
    cout << "Введите фамилию, для поиска оценок: ";
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (strcmp(kurs[i].fam, str) == 0) {
            cout << kurs[i].name << endl;
            for (int j = 0; j < 3; j++) {
                cout << kurs[i].mark[j] << " ";
            }
            cout << endl;
            if (first) break;
        }
    }
}
void AddFileStudentWOSort(const char* name, int n) {
    FILE* f;
    Student t;
    errno_t fp_err = fopen_s(&f, name, "w");
    if (fp_err) {
        cout << "Ошибка при чтение файла";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        t = InputStudent();
        fprintf(f, "%s %s %d ", t.fam, t.name, t.group);
        for (int j = 0; j < 3; j++) {
            fprintf(f, "%d ", t.mark[j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}