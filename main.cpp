//Лабараторная работа 1 по дисциплине МРЗвИС
//Выполнена студентом группы 721701
//БГУИР Коваленко Алексей Васильевич
//Реализация алгоритма вычисления произведения пары 8-разрядных чисел умножением
//со старших разрядов со сдвигом частичной суммы влево
//V.1.0
//алгоритм вычисления произведения 8-разрядных чисел умножением со старших разрядов со
//сдвигом частичной суммы влево

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int SIZE = 8;
int MAX_SIZE = 16;

int* translation(int a1);
vector<int> mult(vector<int> vector1, vector<int> vector2);
int* summa(int *aSIZE, int *aMAXSIZE);
void sdvig(int *a);
void inver_sdvig(int *a);
void view(int *a, int size);
int arrToNumber(int* a, int size);
void conveer(int **a, int **b, int **c, int kol, vector<int> &result);
int *ravno(const int *a, int size, bool flag);
int *null_el(int size);

int main()
{
	vector<int> vector1;
	vector<int> vector2;
	vector<int> vector3;
	int kol;
	int vec;
	cout << "How much numbers in vectors you want to multiply?" << endl;
	cin >> kol;
	cout << "Write first vector" << endl;
	for(int i=0;i<kol;i++)
	{
	    cin >> vec;
		vector1.push_back(vec);
	}
	cout << "Write second vector" << endl;
	for(int i=0;i<kol;i++)
	{
		cin >> vec;
		vector2.push_back(vec);
	}
	vector3 = mult(vector1, vector2);
	for (int i : vector3) {
	    cout << i << " ";
    }
	cout << endl;
	return 0;
}

vector<int> mult(vector<int> vector1, vector<int> vector2)
{
    vector<int> result;
	int kol = (int)vector1.size();
	int **a = new int*[kol];
	for(int i=0;i<kol;i++)
	{
		a[i] = new int[SIZE];
	}
	int **b = new int*[kol];
	for(int i=0;i<kol;i++)
	{
		b[i] = new int[SIZE];
	}
	int **c = new int*[kol];
    for(int i=0;i<kol;i++)
    {
        c[i] = new int[MAX_SIZE];
    }
	for(int i = 0;i<kol;i++)
	{
		a[i] = translation(vector1[i]);
		b[i] = translation(vector2[i]);
	}
	for(int i=0;i<vector1.size();i++)
	{
	    view(a[i], SIZE);
	    cout << "  ";
	}
	cout << endl;
	for(int i=0;i<vector1.size();i++)
	{
		view(b[i], SIZE);
		cout << "  ";
	}
	cout << endl;
	cout << endl;
    conveer(a, b, c, kol, result);

    for(int i=0;i<kol;i++)
    {
        delete[] a[i];
    }
    for(int i=0;i<kol;i++)
    {
        delete[] b[i];
    }
    for(int i=0;i<kol;i++)
    {
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;
	return result;
}

int* translation(int a1) {
	int *a;
	a = new int[SIZE];
	int i = SIZE - 1;
	while (a1 > 1)
	{
		a[i] = a1 % 2;
		a1 = a1 / 2;
		i--;
	}
	a[i] = 1;
	i--;
	while (i >= 0)
	{
		a[i] = 0;
		i--;
	}
	return a;
}

int* summa(int *aSIZE, int *aMAXSIZE) {
    int *c = new int[MAX_SIZE];
    int *bMAXSIZE = new int[MAX_SIZE];
    for(int i=0;i<MAX_SIZE;i++)
    {
        if(i<SIZE)
            bMAXSIZE[i] = 0;
        else
            bMAXSIZE[i] = aSIZE[i-8];
    }
    int k = 0, i = MAX_SIZE - 1;
    while (i >= 0) {
        if (aMAXSIZE[i] == 0 && bMAXSIZE[i] == 0) {
            if (k == 1) c[i] = 1;
            else c[i] = 0;
            k = 0;
        }
        if (aMAXSIZE[i] == 1 && bMAXSIZE[i] == 1) {
            if (k == 1) c[i] = 1;
            else { c[i] = 0; k = 1; }
        }
        if (aMAXSIZE[i] != bMAXSIZE[i]) {
            if (k == 1)  c[i] = 0;
            else { c[i] = 1; k = 0; }
        }
        i--;
    }
    return c;
}

void sdvig(int *a)
{
    for(int i = 0; i < MAX_SIZE - 1; i++)
    {
        a[i] = a[i+1];
    }
    a[MAX_SIZE - 1] = 0;
}

void inver_sdvig(int **a, int n, int size)
{
    for(int j=0;j<n;j++)
    {
        for(int i = size - 1; i >= 0 - 1; i--)
        {
            a[i] = a[i-1];
        }
        a[0]= nullptr;
    }
}

void view(int *a, int size)
{
    if(a!= nullptr)
    {
        for(int i = 0; i < size; i++)
        {
            cout << a[i];
            if(i % 4 == 3 && i!=size-1)
                cout << ".";
        }
    }
    else cout << "                   ";
}

int arrToNumber(int* a, int size)
{
    int number = 0;
    for(int i = 0; i < size; i++)
    {
        number += (int)(a[i]*pow(2,size - i - 1));
    }
    return number;
}

void conveer(int **a, int **b, int **c, int kol, vector<int> &result)
{
    int ***mas = new int **[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++)
    {
        mas[i] = new int *[2 * (MAX_SIZE + kol - 1)];
    }
    for(int i = 0; i < kol; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (a[i][j] == 1) {
                c[i] = summa(b[i], c[i]);
                mas[j*2][i*2] = ravno(b[i], MAX_SIZE, false);
            }
            else {
                mas[j*2][i*2] = null_el(MAX_SIZE);
            }
            mas[j*2][i*2 + 1] = ravno(c[i], MAX_SIZE, true);
            mas[j*2 + 1][i*2] = ravno(c[i], MAX_SIZE, true);
            if (j != SIZE - 1)
                sdvig(c[i]);
            mas[j*2 + 1][i*2 + 1] = ravno(c[i], MAX_SIZE, true);
        }
        result.push_back(arrToNumber(c[i], MAX_SIZE));
    }
    for(int j=0;j<MAX_SIZE;j++)
    {
        inver_sdvig(mas[j], j*2 , 2 * (MAX_SIZE + kol - 1));
    }
    cout << "               ";
    for(int i=0;i<MAX_SIZE;i++)
    {
        cout << "Step " << i + 1 << "               ";
    }
    cout << endl;
    cout << endl;
    for(int i=0;i<2 * (MAX_SIZE + kol - 1);i++)
    {
        //getchar();
        if(i % 2 == 0) {
            cout << "Tact " << i / 2 + 1 << " ";
            if(i / 2 + 1 < 10)
                cout << " ";
        }
        else cout << "        ";
        for(int j=0;j<MAX_SIZE;j++)
        {
            view(mas[j][i], MAX_SIZE);
            cout << "  ";
        }
        cout << endl;
        if(i % 2)
            cout << endl;
    }
//    for(int i = 0; i < MAX_SIZE; i++)
//    {
//        for(int j=0;j<MAX_SIZE + kol - 1;j++)
//        {
//            delete[] mas[i][j];
//        }
//        delete[] mas[i];
//    }
//    delete[] mas;
}

int *ravno(const int *a, int size, bool flag)
{
    int *mas = new int[size];
    if(flag) {
        for (int i = 0; i < size; i++) {
            mas[i] = a[i];
        }
    }
    else {
        for(int i = 0; i < size; i++){
            if(i<size/2)
                mas[i] = 0;
            else mas[i] = a[i - size/2];
        }
    }
    return mas;
}


int *null_el(int size){
    int *a = new int[size];
    for(int i = 0; i < size; i++)
    {
        a[i] = 0;
    }
    return a;
}