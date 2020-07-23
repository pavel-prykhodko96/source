#include "pch.h"
#include <iostream>
#include <chrono>
#include <Windows.h>
using namespace std;


void showArr(int iArr[], int size);
void bubbleSort(int iArr[], int size);
DWORD WINAPI threadFunction(void* pData);

struct dataForThread
{
	dataForThread(int nMult, int*pArr, int nSize, HANDLE mut=0) : m_nMult(nMult),
		m_pArr(pArr), m_nSize(nSize), m_Mut(mut) {}
	int m_nMult;
	int *m_pArr;
	int m_nSize;
	HANDLE m_Mut;
};

int main()
{

	const int ARRSIZE = 10000;
	const int COUNTTHREADS = 2;
	int iArrFIR[ARRSIZE] = { 0 };
	int iArrSEC[ARRSIZE] = { 0 };
	int iArrFWITHOUTTHREAD[ARRSIZE] = { 0 };
	int iArrSWITHOUTTHREAD[ARRSIZE] = { 0 };
	HANDLE ThreadArr[COUNTTHREADS];

	for (int i = 0; i < ARRSIZE; ++i)
	{
		iArrFIR[i] = rand() % 100;
		iArrSEC[i] = rand() % 100;
		iArrFWITHOUTTHREAD[i] = rand() % 100;
		iArrSWITHOUTTHREAD[i] = rand() % 100;
	}
	dataForThread *pData;

	//FIRST SORTING WITH THREADS:

	auto startTime = std::chrono::steady_clock::now();

	pData = new dataForThread(1, iArrFIR, ARRSIZE);
	ThreadArr[0] = CreateThread(0, 0, threadFunction, pData, 0, 0);
	pData = new dataForThread(2, iArrSEC, ARRSIZE);
	ThreadArr[1] = CreateThread(0, 0, threadFunction, pData, 0, 0);

	WaitForMultipleObjects(COUNTTHREADS, ThreadArr, TRUE, INFINITE);
	
	auto endTime = chrono::steady_clock::now();
	chrono::duration <double> diff = endTime - startTime;
	cout << diff.count() << " seconds passed with using threads\n";

	//SECOND SORTING WITHOUT THREADS:

	dataForThread data(0,0,0);

	startTime = std::chrono::steady_clock::now();

	data = dataForThread(3, iArrFWITHOUTTHREAD, ARRSIZE);
	bubbleSort(data.m_pArr, data.m_nSize);	
	data = dataForThread(4, iArrSWITHOUTTHREAD, ARRSIZE);
	bubbleSort(data.m_pArr, data.m_nSize);
	
	bubbleSort(iArrSWITHOUTTHREAD, ARRSIZE);

	endTime = chrono::steady_clock::now();
	diff = endTime - startTime;
	cout << diff.count() << " seconds passed without using threads\n";

	//showArr(iArrFIR, ARRSIZE);
	//showArr(iArrSEC, ARRSIZE);
	//showArr(iArrFWITHOUTTHREAD, ARRSIZE);
	//showArr(iArrSWITHOUTTHREAD, ARRSIZE);

	for (int i = 0; i < COUNTTHREADS; ++i)
	{
		CloseHandle(ThreadArr[i]);
	}

	return 0;
}

DWORD WINAPI threadFunction(void* pData)
{
	dataForThread *pdata = static_cast<dataForThread*>(pData);
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