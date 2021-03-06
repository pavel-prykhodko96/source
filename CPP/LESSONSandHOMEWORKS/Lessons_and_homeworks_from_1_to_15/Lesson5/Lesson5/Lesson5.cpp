
#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>

class New
{
public:
	char type;
	double value; 
};
using namespace std;

const int ARRSIZE = 20;
const int nMaxNumber = 20;

void showArray(int iArr[], int nSize);
int findHighest(int iArr[], int nSize, int&rMax, int*pMax);
int count_negative(int iArr[]);
void createArrayWithNeg (int*pSource, int *pDestination);


int main()
{
	{
		int iArrayFirst[ARRSIZE]={ 0 };
		int rMax = 0; // For reference 
		int pMax = 0; // For pointer
		srand(time(0));
		for (int i = 0; i < ARRSIZE; ++i)
		{
			iArrayFirst[i] = rand() % nMaxNumber - 10;
		}
		int nCountNegative = count_negative(iArrayFirst);
		int *pDinArray = new int[nCountNegative];
		showArray(iArrayFirst, ARRSIZE);
		cout << endl << nCountNegative << endl;
		createArrayWithNeg(iArrayFirst, pDinArray);
		showArray(pDinArray, nCountNegative);
		delete [] pDinArray;
	}if (_CrtDumpMemoryLeaks())
		cout << "MEMORY LEAKS!!!!!" << endl;
	else
		cout << "MEMORY OK!!!!!" << endl;
	return 0;
}
//Output all values of the array:
void showArray(int *iArr, int nSize) //*iArr==iArr[]
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}

int findHighest(int *iArr, int nSize,int&rMax, int*pMax) 
{
	int nCurrent(0), nIndexhigh(0);
	for (int i = 0; i < nSize; ++i)
	{
		if (iArr[i] > nCurrent)
		{
			nCurrent = iArr[i];
			nIndexhigh = i;
		}
	}
	rMax = iArr[nIndexhigh];
	*pMax = iArr[nIndexhigh];
	return nIndexhigh;
}

int count_negative(int iArr[])
{
	int nCounter = 0;
	for (int i = 0; i < ARRSIZE; ++i)
	{
		if (*(iArr + i) < 0)
		{
			++nCounter;
		}
	}
	return nCounter;
}

void createArrayWithNeg(int*pSource, int *pDestination) 
{
	int nCounter = 0;
	for (int i = 0; i < ARRSIZE; ++i)
	{
		if (*(pSource + i) < 0)
		{
			*(pDestination + nCounter) = *(pSource + i);
			++nCounter;
		}
	}
}

/*
int sum(int*ref1, int*ref2);

int main()
{
	int n1(6), n2(8);
	cout << sum(&n1, &n2) << endl;
	return 0;
}

int sum(int*ref1, int*ref2)
{
	return *ref1 + *ref2;
}
*/