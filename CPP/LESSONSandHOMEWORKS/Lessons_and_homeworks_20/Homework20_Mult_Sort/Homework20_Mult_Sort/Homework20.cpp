#include "pch.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <Windows.h>
using namespace std;

DWORD WINAPI threadFunction(void* pData);
void showArr(int iArr[], int size);
void bubbleSort(int iArr[], int size);

struct pieceOfArr
{
	pieceOfArr(int*pArr, int nSize): m_pArr(pArr), m_nSize(nSize) {}
	int *m_pArr;
	int m_nSize;
};

int main()
{
	const int ARRSIZE = 100000;
	const int COUNTTHREADS = 2;
	const int MAXVAL = 20000;
	const int COMPAREVAL = MAXVAL / 2;
	int iArrFir[ARRSIZE] = { 0 };
	int iArrSec[ARRSIZE] = { 0 };
	for (int i = 0; i < ARRSIZE; ++i)
		iArrSec[i] = iArrFir[i] = rand() % MAXVAL;
	int nIdFromFinish = ARRSIZE - 1;

	for (int i = 0; i < ARRSIZE; ++i) // [0,9]
	{
		if (iArrFir[i] >= COMPAREVAL) // >= 500 
		{
			for (int j = nIdFromFinish; j > i; --j) // [10,19] 
			{
				if (iArrFir[j] < COMPAREVAL) // <500
				{
					int nTemp = iArrFir[i];
					iArrFir[i] = iArrFir[j];
					iArrFir[j] = nTemp;
					nIdFromFinish = j;
					break;
				}
			}
		}
	}

	int nIdRightValFromStart = 0;
	for (int i = 0; i < ARRSIZE - 1; ++i)
	{
		if (iArrFir[i + 1] > COMPAREVAL)
		{
			nIdRightValFromStart = i + 1;
			break;
		}
	}

	HANDLE ThreadArr[COUNTTHREADS];
	pieceOfArr *FirPiece = new pieceOfArr(iArrFir, nIdRightValFromStart);
	pieceOfArr *SecPiece =
		new pieceOfArr((iArrFir + nIdRightValFromStart), ARRSIZE - nIdRightValFromStart);
	
	auto startTime = std::chrono::steady_clock::now();

	ThreadArr[0] = CreateThread(0, 0, threadFunction, FirPiece, 0, 0);
	ThreadArr[1] = CreateThread(0, 0, threadFunction, SecPiece, 0, 0);

	WaitForMultipleObjects(COUNTTHREADS, ThreadArr, TRUE, INFINITE);
	
	auto endTime = chrono::steady_clock::now();
	chrono::duration <double> diff = endTime - startTime;
	cout << diff.count() << " seconds passed with using threads\n";

	startTime = std::chrono::steady_clock::now();

	bubbleSort(iArrSec, ARRSIZE);

	endTime = chrono::steady_clock::now();
	diff = endTime - startTime;
	cout << diff.count() << " seconds passed without using threads\n";
}
DWORD WINAPI threadFunction(void* pData)
{
	pieceOfArr *pdata = static_cast<pieceOfArr*>(pData);
	bubbleSort(pdata->m_pArr, pdata->m_nSize);
	delete pdata;
	return 0;
}

void bubbleSort(int iArr[], int size)
{
	int temp;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (iArr[j] > iArr[j + 1])
			{
				temp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = temp;
			}
}
void showArr(int iArr[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << iArr[i] << " ";
	cout << endl;
}