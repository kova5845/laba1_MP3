#include <iostream>
#include <vector>

using namespace std;

int SIZE = 8;
int MAX_SIZE = 16;

int* translation(int a1);
vector<int> mult(vector<int> vector1, vector<int> vector2);
int* summa(int *aSIZE, int *aMAXSIZE);
void sdvig(int *a);
void view(int *a, int size);

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
	return 0;
}

vector<int> mult(vector<int> vector1, vector<int> vector2)
{
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

	}
	for(int i=0;i<vector1.size();i++)
	{
		view(b[i], SIZE);
	}
    for(int j = 0; j < kol; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (a[j][i] == 1)
                c[j] = summa(b[j], c[j]);
            if (i != SIZE - 1)
                sdvig(c[j]);
        }
    }
    for(int i=0;i<vector1.size();i++)
    {
        view(c[i], MAX_SIZE);
    }

	return vector1;
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

void view(int *a, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;
}







/*void sum(vector<int> a, vector<int> b, int l)
{
	int k = 0, i = 7;
	while (i >= 0)
	{
		if (a[i] == 0 && b[i] == 0)
		{
			if (k == 1) c[i] = 1;
			else c[i] = 0;
			k = 0;
		}
		if (a[i] == 1 && b[i] == 1)
		{
			if (k == 1) c[i] = 1;
			else
			{
				c[i] = 0;
				k = 1;
			}
		}
		if (a[i] != b[i])
		{
			if (k == 1)  c[i] = 0;
			else
			{
				c[i] = 1;
				k = 0;
			}
		}
		i--;
	}
}*/





/*#include "pch.h"
#include <iostream>
using namespace std;

void Perevod(int a1, int *a) {
	int i = 15;
	while (a1 > 1) {
		a[i] = a1 % 2;
		a1 = a1 / 2;
		i--;
	}
	a[i] = 1;
	i--;
	while (i >= 0) {
		a[i] = 0;
		i--;
	}
}

void View(int* a) {
	int k;
	if (a[0] == 1) a[8] = 1;
	for (k = 8; k < 16; k++) {
		cout << a[k];
	}
	cout << endl;
}


void View1(int* a) {
	int k;
	for (k = 0; k < 8; k++) {
		cout << a[k];
	}
	for (k = 8; k < 16; k++)
		cout << a[k];
	cout << endl;
}


void View2(int* a) {
	int k;
	for (k = 0; k < 16; k++) {
		cout << a[k];
		if (k != 0 && a[k] == 1)
			break;
	}
	cout << ".";
	for (k++; k < 16; k++)
		cout << a[k];
	cout << endl;
}

void Sum(int *a, int *b, int *c) {
	int k = 0, i = 15;
	while (i >= 0) {
		if (a[i] == 0 && b[i] == 0) {
			if (k == 1) c[i] = 1;
			else c[i] = 0;
			k = 0;
		}
		if (a[i] == 1 && b[i] == 1) {
			if (k == 1) c[i] = 1;
			else { c[i] = 0; k = 1; }
		}
		if (a[i] != b[i]) {
			if (k == 1)  c[i] = 0;
			else { c[i] = 1; k = 0; }
		}
		i--;
	}
}

void Razn(int *a, int *b, int *c) {
	int k, i;
	k = 0; i = 15;
	while (i >= 0) {
		if (a[i] == 1 && b[i] == 1) {
			if (k == 1) c[i] = 1;
			else c[i] = 0;
		}
		if (a[i] == 0 && b[i] == 0) {
			if (k == 1) c[i] = 1;
			else c[i] = 0;
			k = 0;
		}
		if (a[i] == 0 && b[i] == 1) {
			if (k == 1)  c[i] = 0;
			else { c[i] = 1; k = 1; }
		}
		if (a[i] == 1 && b[i] == 0) {
			if (k == 1) { c[i] = 0; k = 0; }
			else c[i] = 1;
		}
		i--;
	}
}



void Perevod_Obr(int *a) {
	int i;
	for (i = 0; i < 16; i++)
		if (a[i] == 0) a[i] = 1;
		else a[i] = 0;
	a[0] = 1;
}

void Perevod_Dop(int *a) {
	int q[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
	Sum(a, q, a);
}

void Sum_Obr(int *a, int *b, int *c) {
	int k = 0, i = 15;
	while (i >= 0) {
		if (a[i] == 0 && b[i] == 0) {
			if (k == 1) c[i] = 1;
			else c[i] = 0;
			k = 0;
		}
		if (a[i] == 1 && b[i] == 1) {
			if (k == 1) c[i] = 1;
			else { c[i] = 0; k = 1; }
		}
		if (a[i] != b[i]) {
			if (k == 1)  c[i] = 0;
			else { c[i] = 1; k = 0; }
		}
		i--;
	}
	if (k==1)
		Perevod_Dop(c);
}

void Proizvedenie(int *a, int *b, int *d) {
	int i,j=0;
	for (i = 0; i < 16; i++)
		d[i] = 0;
	for (i = 0; i < 16; i++)
		j += b[i] * pow(2, 15 - i);
			for (i = 0; i < j; i++)
			Sum(d, a, d);
	}

void Delenie(int *a, int *b, int *d) {
	int i, j, k, n;
	for (i = 0; i < 16; i++)
		if (a[i] == 1) break;
	for (j = 0; j < 16; j++)
		if (b[j] == 1) break;
	k = j - i;
	//Perevod_Dop(b);
	for (i = 0; i < 16; i++)
		d[i] = 0;
	while (k > 0) {
		//Sum(a, b, d);
		Razn(a, b, d);
		j = 0; n = 0;
		for (i = 0; i < 16; i++) {
			j += b[i] * pow(2, 15 - i);
			n += d[i] * pow(2, 15 - i);
		}
		d[11] = 1;
		if (j < n) return;
		else k--;
	}
}

void Perevod_s_Pl(int a1, int *a) {
	int i = 13;
	while (a1 > 1) {
		a[i] = a1 % 2;
		a1 = a1 / 2;
		i--;
	}
	a[i] = 1;
	i--;
	while (i >= 0) {
		a[i] = 0;
		i--;
	}
	a[7] = 0;
	a[6] = 1;
	a[5] = 1;
	for (i = 14; i < 16; i++)
		a[i] = 0;
}

void Sum_Pl(int *a, int *b, int *c) {
	int k = 0, i = 15;
	while (i >= 8) {
		if (a[i] == 0 && b[i] == 0) {
			if (k == 1) c[i] = 1;
			else c[i] = 0;
			k = 0;
		}
		if (a[i] == 1 && b[i] == 1) {
			if (k == 1) c[i] = 1;
			else { c[i] = 0; k = 1; }
		}
		if (a[i] != b[i]) {
			if (k == 1)  c[i] = 0;
			else { c[i] = 1; k = 0; }
		}
		i--;
	}
	for (i = 0; i < 8; i++)
		c[i] = a[i];
}


int main() {
	int a, b, a1[16], b1[16], c1[16], d1[16], a2[16], b2[16], c2[16], a3[16], b3[16], c3[16];
	cout << "Input numbers" << endl;
	cin >> a;
	cin >> b;
	cout << endl;
	Perevod(a,a1);
	cout << a << " = ";
	View(a1);
	Perevod(b, b1);
	cout << b << " = ";
	View(b1);
	Sum(a1, b1, c1);
	cout << a <<" + "<< b << " = ";
	View(c1);
	if (a > b) {
		cout << a << " - " << b << " = ";
		Razn(a1, b1, c1);
	}
	else {
		cout << b << " - " << a << " = ";
		Razn(b1, a1, c1);
	}
	View(c1);
	c1[0] = 1;
	if(a>b) cout << b << " - " << a << " = ";
	else cout << a << " - " << b << " = ";
	View(c1);
	Sum(a1, b1, c1);
	c1[0] = 1;
	cout << "-"<< a << " - " << b << " = ";
	View(c1);
	cout << endl;


	Perevod(a, a2);
	Perevod_Obr(a2);
	cout <<"-"<< a << " = ";
	View(a2);
	Perevod(b, b2);
	Perevod_Obr(b2);
	cout <<"-"<< b << " = ";
	View(b2);
	Sum(a1, b1, c1);
	cout << a << " + " << b << " = ";
	View(c1);
	Sum_Obr(a2, b2, c2);
	cout <<"-"<< a << " - " << b << " = ";
	View(c2);
	Sum_Obr(a1, b2, c2);
	cout << a << " - " << b << " = ";
	View(c2);
	Sum_Obr(a2, b1, c2);
	cout << b << " - " << a << " = ";
	View(c2);
	cout << endl;

	Perevod(a, a3);
	Perevod_Obr(a3);
	Perevod_Dop(a3);
	cout <<"-"<< a << " = ";
	View(a3);
	Perevod(b, b3);
	Perevod_Obr(b3);
	Perevod_Dop(b3);
	cout <<"-"<< b << " = ";
	View(b3);
	cout << a << " + " << b << " = ";
	View(c1);
	Sum(a3, b3, c3);
	cout <<"-"<< a << " - " << b << " = ";
	View(c3);
	Sum(a1, b3, c3);
	cout << a << " - " << b << " = ";
	View(c3);
	Sum(b1, a3, c3);
	cout << b << " - " << a << " = ";
	View(c3);
	cout << endl;


	Proizvedenie(a1, b1, d1);
	cout << a << " * " << b << " = " << " -" << a << " * -" << b << " = ";
	View1(d1);
	d1[0] = 1;
	cout << a << " * " <<"-"<< b << " = " << " -" << a << " * " << b << " = ";
	View1(d1);
	if (a > b) {
		Delenie(a1, b1, d1);
		cout << a << " / " << b << " = " << " -" << a << " / -" << b << " = ";
		View2(d1);
		d1[0] = 1;
		cout << a << " / " << "-" << b << " = " << " -" << a << " / " << b << " = ";
		View2(d1);
		cout << endl;
	}
	else {
	Delenie(b1, a1, d1);
	cout << b << " / " << a << " = " << " -" << b << " / -" << a << " = ";
	View2(d1);
	d1[0] = 1;
	cout << b << " / " << "-" << a << " = " << " -" << b << " / " << a << " = ";
	View2(d1);
	cout << endl;
	}

	Perevod_s_Pl(a, a1);
	cout << a << " = ";
	View1(a1);
	Perevod_s_Pl(b, b1);
	cout << b << " = ";
	View1(b1);
	cout << a << " + " << b << " = ";
	Sum_Pl(a1, b1,c1);
	View1(c1);
	return 0;
}*/