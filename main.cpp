//Лабараторная работа 1 по дисциплине МРЗвИС
//Выполнена студентом группы 721701
//БГУИР Коваленко Алексей Васильевич
//Реализация алгоритма вычисления произведения пары 8-разрядных чисел умножением
// со старших разрядов со сдвигом частичной суммы влево
//V.1.0
//алгоритм вычисления произведения 8-разрядных чисел умножением со старших разрядов со
// сдвигом частичной суммы влево

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
int *ravno(const int *a, int size);

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
        }
    }
    else cout << "                ";
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
    int ***mas = new int **[kol];
    for(int i = 0; i < kol; i++)
    {
        mas[i] = new int *[MAX_SIZE + kol - 1];
    }
    for(int i = 0; i < kol; i++)
    {
            for (int j = 0; j < SIZE; j++)
            {
                if (a[i][j] == 1)
                    c[i] = summa(b[i], c[i]);
                mas[i][j*2] = ravno(c[i], MAX_SIZE);
                if (j != SIZE - 1)
                {
                    sdvig(c[i]);
                    mas[i][j*2 + 1] = ravno(c[i], MAX_SIZE);
                }
            }
        result.push_back(arrToNumber(c[i], MAX_SIZE));
    }
    for(int j=0;j<kol;j++)
    {
        inver_sdvig(mas[j], j, MAX_SIZE + kol - 1);
    }
    for(int i=0;i<MAX_SIZE + kol - 1;i++)
    {
        for(int j=0;j<kol;j++)
        {
            view(mas[j][i],MAX_SIZE);
            cout << "  ";
        }
        cout << endl;
    }
}

int *ravno(const int *a, int size)
{
    int *mas = new int[size];
    for(int i=0;i<size;i++)
    {
        mas[i] = a[i];
    }
    return mas;
}