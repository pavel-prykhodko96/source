
#include "pch.h"

void showArray(int *iArr, int nSize);
void initArray(int *iArr, int nSize);
bool ascending(int a, int b);
bool descending(int a, int b);
void bubblesort(int *iArr, int nSize, bool(*pSORT)(int, int));
int arQSORT(const void* pLeft, const void* pRight);

const int SIZE = 15;

int main()
{
	int iArr[SIZE];
	initArray(iArr, SIZE);
	std::qsort(iArr, SIZE, sizeof(int), arQSORT);
	showArray(iArr, SIZE);
	return 0;
/*	
    int iArr[SIZE];
	initArray(iArr, SIZE);
	cout << "Please enter how you want to sort (0 or 1): ";
	bool(*pF[2])(int, int) = { ascending,descending };
	int nWhat = 0;
	cin >> nWhat;
	if (nWhat != 0 && nWhat != 1)
	{
		cout << "Wrong VALUE!!!!!";
		return 1;
	}
	bubblesort(iArr, SIZE, pF[nWhat]);
	showArray(iArr, SIZE);
	return 0;
*/
/*
    int iWHAT = 0;
	bool(*pWhat) (int, int) = ascending;
	cout << "Please enter how you want to sort (0 or 1): ";
	cin >> iWHAT;
	if (iWHAT==1)
		pWhat = descending;
	else if (iWHAT == 0);
	else
	{
		cout << "Wrong value!!!!!!\n";
		return 1;
	}
	int iArr[SIZE];
	void(*pINIT) (int*, int) = initArray;
	pINIT(iArr, SIZE);
	bubblesort(iArr, SIZE, pWhat);
	showArray(iArr, SIZE);*/
}
int arQSORT(const void* pLeft, const void* pRight)
{
	int *pL = (int*)pLeft;
	int *pR = (int*)pRight;
	if (*pL < *pR)
		return -1;
	else if (*pL == *pR)
		return 0;
	else return 1;
}
bool ascending(int a, int b)
{
	if (a > b)
		return true;
	return false;
}
bool descending(int a, int b)
{
	if (a < b)
		return true;
	return false;
}
void bubblesort(int *iArr, int nSize, bool (*pSORT)(int,int))
{
	int ntemp(0);
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize - 1 - i; ++j)
		{
			if (pSORT(iArr[j],iArr[j+1]))
			{
				ntemp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = ntemp;				
			}
		}		
	}
}
void initArray(int *iArr, int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = rand() % 20;
	}
}

void showArray(int *iArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}
