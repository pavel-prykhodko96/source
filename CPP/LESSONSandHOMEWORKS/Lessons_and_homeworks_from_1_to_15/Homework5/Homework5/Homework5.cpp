
#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;
//TASK 3: THE SNAKE
const int ARRSIZE = 18;

void showArray(int iArray[][ARRSIZE]);

int main()
{
	int iArray[ARRSIZE][ARRSIZE] = { 0 };
	int nValue(0), sign(1), x(ARRSIZE/2), y(ARRSIZE/2);
	if (ARRSIZE % 2 != 1) //This is necessary because we can't corectly divide odd numbers
	{
		--x;
		--y;
	}
	for (int i = 1; i <= ARRSIZE; ++i) //The cycle must run (ARRSIZE - 0.5) times to look watchable so we use '<=' instead of '<'
	{
		for (int j = 0; j < i; y += sign, ++j)
		{
			iArray[x][y] = nValue;
			++nValue;
		}
		if (i == ARRSIZE) //The cycle must run (ARRSIZE - 0.5) times to be watchable so we break cycle at half during the last iteration
		{
			break;
		}
		for (int j = 0; j < i; x += sign, ++j)
		{
			iArray[x][y] = nValue;
			++nValue;
		}
		sign *= -1;
	}
	showArray(iArray);
	return 0;
}
void showArray(int iArray[][ARRSIZE])
{
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			if (j % ARRSIZE == 0)
			{
				cout << endl;
			}
			cout << setw(4) << iArray[i][j];
		}
	}
}

/*//TASK 2: potholes on the road
const int ARRSIZE = 100;
const int MAXVAL = 11; //Really 10

void showArray(int *iArr, int nSize);
void createsymbols(int*iArr, int nSize, char*cArr);

int main()
{
	int iArray[ARRSIZE] = { 0 };
	char cSymbolsArr[ARRSIZE] = { '0' };
	srand(time(0));
	for (int i = 0; i < ARRSIZE; ++i)
	{
		iArray[i] = rand() % MAXVAL;
	}
	createsymbols(iArray, ARRSIZE, cSymbolsArr);
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < iArray[i]; ++j)
		{
			cout << cSymbolsArr[i];
		}
		cout << endl;
	}
	return 0;
}

void createsymbols(int*iArr, int nSize, char*cArr)
{
	int nCounter(0);
	for (int i = 0; i < ARRSIZE; ++i)
	{
		if (iArr[i]<=3)
		{
			if (nCounter >= 3)
			{
				for (int j = 1; j <= nCounter; ++j)
				{
					cArr[i - j] = '$';
				}
			}
			nCounter = 0;
			cArr[i] = '*';		
		}
		else 
		{
			cArr[i] = '#';
			++nCounter;
		}
	}
}
*/
/*//TASK 1: from -25 to +25, input diapason of values
const int ARRSIZE = 30;
const int nMaxNumber = 50;

void showArray(int *iArr, int nSize);
int countValues(int*iArr,int High, int Low);
void writeValues(int*iArr, int High, int Low, int*iArr2);

int main()
{
	{
		int iArrayFirst[ARRSIZE] = { 0 };
		int nLowVal(0);
		int nHighVal(0);
		int nCountValues(0);
		srand(time(0));
		for (int i = 0; i < ARRSIZE; ++i)
		{
			iArrayFirst[i] = rand() % nMaxNumber - 25;
		}
		cout << "Please enter the lowest and the highest values of the desired to find diapason of values: ";
		cin >> nLowVal >> nHighVal;
		if (nLowVal > nHighVal)
		{
			int Changer = nLowVal;
			nLowVal = nHighVal;
			nHighVal = Changer;
		}
		nCountValues = countValues(iArrayFirst, nHighVal, nLowVal);
		int*iArraySecond = new int[nCountValues];
		writeValues(iArrayFirst, nHighVal, nLowVal, iArraySecond);
		showArray(iArrayFirst, ARRSIZE);
		showArray(iArraySecond, nCountValues);
		delete[]iArraySecond;
	}if (_CrtDumpMemoryLeaks())
		cout << "Memory leaks!";
	else cout << "Memory OK!";
	return 0;
}

int countValues(int*iArr, int High, int Low)
{
	int nCounter(0);
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = Low; j <= High; ++j)
		{
			if (*(iArr + i) == j)
			{
				++nCounter;
			}
		}
	}
	return nCounter;
}

void writeValues(int*iArr, int High, int Low, int*iArr2)
{
	int nCounter(0);
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = Low; j <= High; ++j)
		{
			if (*(iArr + i) == j)
			{
				*(iArr2 + nCounter) = j;
				++nCounter;
			}
		}
	}
}
void showArray(int *iArr, int nSize) //Output all values of the array:
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}
*/