

#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

//ARRAY SORTING

const int ARRSIZE = 5555;

void showArray(int *iArr, int nSize);
void showArray(char *iArr, int nSize);
void showArray(double *iArr, int nSize);
void initArray(double *iArr, int nSize);
void initArray(int *iArr, int nSize);
void initArray(char *iArr, int nSize);
void bubblesort(int *iArr, int nSize, bool bAsc = true);
void insertionsort(int *iArr, int nSize);
void selectionsort(int *iArr, int nSize);

int main()
{
	int iArray[ARRSIZE];
	initArray(iArray, ARRSIZE);
	int *pArrayFirCopy = new int[ARRSIZE];
	int *pArraySecCopy = new int[ARRSIZE];
	memcpy(pArrayFirCopy, iArray, sizeof(iArray)); //memcpy copyies iArray to pArrayFirCopy
	memcpy(pArraySecCopy, iArray, sizeof(iArray));
	SYSTEMTIME stBeg, stEnd;
	//showArray(iArray, ARRSIZE);//FIRST SORT: SELECTION
	GetLocalTime(&stBeg);
	selectionsort(iArray, ARRSIZE);
	GetLocalTime(&stEnd);
	cout << (stEnd.wSecond*1000 + stEnd.wMilliseconds) - (stEnd.wSecond*1000 + stBeg.wMilliseconds) << endl;
	//showArray(iArray, ARRSIZE);
	//showArray(pArrayFirCopy, ARRSIZE); //SECOND SORT: BUBBLE
	GetLocalTime(&stBeg);
	bubblesort(pArrayFirCopy, ARRSIZE);
	GetLocalTime(&stEnd);
	cout << (stEnd.wSecond*1000 + stEnd.wMilliseconds) - (stEnd.wSecond*1000 + stBeg.wMilliseconds) << endl;
	//showArray(pArrayFirCopy, ARRSIZE);
	//showArray(pArraySecCopy, ARRSIZE); //THIRD SORT: INSERTION
	GetLocalTime(&stBeg);
	insertionsort(pArraySecCopy, ARRSIZE); 
	GetLocalTime(&stEnd);
	cout << (stEnd.wSecond*1000 + stEnd.wMilliseconds) - (stEnd.wSecond*1000 + stBeg.wMilliseconds) << endl;
	//showArray(pArraySecCopy, ARRSIZE);
	//SYSTEMTIME stBeg, stEnd;
	//GetLocalTime(&stBeg);
	//GetLocalTime(&stEnd);
	//cout << (stEnd.wSecond*1000 + stEnd.wMilliseconds) - (stEnd.wSecond*1000 + stBeg.wMilliseconds) << endl;
	return 0;
}

void insertionsort(int *iArr, int nSize)
{
	int temp(0), ind(0);
	for (int i = 1; i < nSize; ++i)
	{
		temp = iArr[i];
		ind = i - 1;
		while (ind >= 0 && iArr[ind] > temp)
		{
			iArr[ind + 1] = iArr[ind];
			ind--;
		}
		iArr[ind + 1] = temp;
	}
	
}
void bubblesort(int *iArr, int nSize, bool bAsc) //bAsc for choose direction of sorting
{
	int nChanger(0); //Changer
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize - 1 - i; ++j)
		{
			if (bAsc == true && iArr[j] > iArr[j + 1] || bAsc == false && iArr[j] < iArr[j + 1]) //sort from low to high or vice versa
			{
				nChanger = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = nChanger;
			}
		}
	}
}
void selectionsort(int *iArr, int nSize)
{
	int nChanger(0);
	for (int i = nSize - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (iArr[j] > iArr[i])
			{
				nChanger = iArr[j];
				iArr[j] = iArr[i];
				iArr[i] = nChanger;
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
void initArray(double *iArr, int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = rand() % 20;
	}
}
void initArray(char *iArr, int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = 65 + rand() % 26;
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
void showArray(double *iArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}
void showArray(char *iArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}

