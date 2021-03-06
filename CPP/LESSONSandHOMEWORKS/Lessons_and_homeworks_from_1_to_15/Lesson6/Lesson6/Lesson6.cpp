// Lesson6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

//ARRAY SORTING

const int ARRSIZE = 20;

void showArray(int *iArr, int nSize);
void showArray(char *iArr, int nSize);
void initArray(int *iArr, int nSize);
void initArray(char *iArr, int nSize);
void bubblesort(int *iArr, int nSize, int& nCount, bool bAsc = true);
void insertionsort(int *iArr, int nSize, int& nCount);

int main()
{
	/*char iArray[ARRSIZE];
	initArray(iArray, ARRSIZE);
	showArray(iArray, ARRSIZE);
	*/
	char cStr[256];
	sprintf_s(cStr, "Today %d %d %d", 20, 10, 2018);
	cout << cStr << endl;
	int nCounter(0);
	int iArray[ARRSIZE] = { 0 };
	initArray(iArray, ARRSIZE);
	//int *pArrayCopy = new int[ARRSIZE];
	//memcpy(pArrayCopy, iArray, sizeof(iArray)); 
	//SYSTEMTIME stBeg, stEnd;
	//showArray(iArray, ARRSIZE);
	//GetLocalTime(&stBeg);
	bubblesort(iArray, ARRSIZE, nCounter);
	showArray(iArray, ARRSIZE);
	//GetLocalTime(&stEnd);
	//showArray(iArray, ARRSIZE);
	//cout << (stEnd.wSecond*1000 + stEnd.wMilliseconds) - (stEnd.wSecond*1000 + stBeg.wMilliseconds) << endl;
	//GetLocalTime(&stBeg);
	//insertionsort(pArrayCopy, ARRSIZE, nCounter);
	//GetLocalTime(&stEnd);
	//showArray(iArray, ARRSIZE);
	//cout << (stEnd.wSecond * 1000 + stEnd.wMilliseconds) - (stEnd.wSecond * 1000 + stBeg.wMilliseconds) << endl;
	//cout << nCounter << endl;
	return 0;
}

void insertionsort(int *iArr, int nSize, int& nCount)
{
	int temp(0), ind(0), nCounter(0);
	for (int i = 1; i < nSize; ++i)
	{
		temp = iArr[i];
		ind = i - 1;
		while (ind >= 0 && iArr[ind] > temp)
		{
			iArr[ind + 1] = iArr[ind];
			ind--;
			nCounter += 2;
		}
		iArr[ind + 1] = temp;
		++nCounter;
	}
	nCount = nCounter;
}
void bubblesort(int *iArr, int nSize, int& nCount, bool bAsc)
{
	int ntemp(0), nCounter(0); //Changer
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize - 1 - i; ++j)
		{
			if (bAsc==true&&iArr[j] > iArr[j + 1]|| bAsc == false && iArr[j] < iArr[j + 1])
			{
				ntemp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = ntemp;
				++nCounter;
			}
			++nCounter;
		}
		++nCounter;
	}
	nCount = nCounter;
}
/*
void bubblesort(int *iArr, int nSize, int& nCount)
{
	int ntemp(0), nCounter(0); //Changer
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize - 1-i; ++j)
		{
			if (iArr[j] > iArr[j + 1])
			{
				ntemp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = ntemp;
				++nCounter;
			}
			++nCounter;
		}
		++nCounter;
	}
	nCount = nCounter;
}
*/

void initArray(int *iArr, int nSize)
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
void showArray(char *iArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}

