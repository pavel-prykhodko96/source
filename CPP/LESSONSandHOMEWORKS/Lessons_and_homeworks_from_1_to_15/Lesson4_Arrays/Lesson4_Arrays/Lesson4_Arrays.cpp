
#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int ARRSIZE = 8;
int main()
{
	int iArr[ARRSIZE][ARRSIZE] = { 0 };
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			iArr[i][j] = rand() % 20;
			cout << setw(4) << iArr[i][j];
		}
		cout << endl;
	}
}

/*const int ARRSIZE = 25;

void initArray (int iArr[], int nSize);
void showArray (int iArr[], int nSize);
int findHighest (int iArr[], int nSize);
int findLowest(int iArr[], int nSize);
void diapason(int iArr[], int lowestnum, int highestnum);
void sum20 (int iArr[], int nSize);

int main()
{
	int iArr[ARRSIZE];
	initArray(iArr, ARRSIZE);
	showArray(iArr, ARRSIZE);
	diapason(iArr, findLowest(iArr,ARRSIZE), findHighest(iArr,ARRSIZE));
	return 0;
}
void initArray(int iArr[], int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = rand() % 20;
	}
}
void showArray(int iArr[], int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}
int findHighest(int iArr[], int nSize)
{
	int nCurrent(0), nIndex(0);
	for (int i = iArr[0]; i < nSize; ++i)
	{
		if (iArr[i] > nCurrent)
		{
			nCurrent = iArr[i];
			nIndex = i;
		}
	}
	return nIndex;
}
int findLowest(int iArr[], int nSize)
{
	int nCurrent(iArr[0]), nIndex(0);
	for (int i = 0; i < nSize; ++i)
	{
		if (iArr[i] < nCurrent)
		{
			nCurrent = iArr[i];
			nIndex = i;
		}
	}
	return nIndex;
}
void diapason(int iArr[], int lowestnum, int highestnum)
{
	int changer(0);
	if (lowestnum > highestnum)
	{
		changer = lowestnum;
		lowestnum = highestnum;
		highestnum = changer;
	}
	for (int i = iArr[lowestnum]; i <= iArr[highestnum]; ++i)
	{
		cout << iArr[i] << " ";
	}
}
void sum20(int iArr[], int nSize)
{
	for (int i = 0; i < nSize - 1; ++i)
	{
		if (iArr[i] + iArr[i + 1] == 20)
		{
			cout << "(" << iArr[i] << "," << iArr[i + 1] << ")\n";
		}
	}
}*/
/*
int main()
{
	int iArr[ARRSIZE];
	srand(time(0));
	for (int i = 0; i < ARRSIZE; ++i)
	{
		iArr[i] = rand() % 26;
	}
	for (int i = 0; i < ARRSIZE; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < ARRSIZE; i+=2)
	{
		cout << iArr[i] << " ";
	}
}
	*/
