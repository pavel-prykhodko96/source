#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;

DWORD WINAPI threadFunction(void* pData);
struct dataForThread
{
	dataForThread(int nMult, int*pArr, int nSize, HANDLE mut) : m_nMult(nMult), 
		m_pArr(pArr), m_nSize(nSize), m_Mut(mut){}
	int m_nMult;
	int *m_pArr;
	int m_nSize;
	HANDLE m_Mut;
};

int main()
{
	
	const int ARRSIZE = 20;
	const int COUNTTHREADS = 3;
	int iArr[ARRSIZE] = { 0 };
	HANDLE ThreadArr[COUNTTHREADS];

	for (int i = 0; i < ARRSIZE; ++i)
		iArr[i] = 1;

	HANDLE hMut = CreateMutexA(0,TRUE,"process name");

	dataForThread *pData;
	for (int i = 0; i < COUNTTHREADS; ++i)
	{
		pData = new dataForThread(2+i*1,iArr,ARRSIZE,hMut);
		ThreadArr[i] = CreateThread(0, 0, threadFunction, pData, 0, 0);
	}
	//HANDLE threadHandle = CreateThread(0, 0, threadFunction, 0, 0, 0);

	/*
	int n;    PAUSE
	cin >> n;
	*/
	//or:

	//WaitForSingleObject(threadHandle, INFINITE);*/
	
	char cAnsw;
	cout << "release mutex? (y/n)\n";
	cin >> cAnsw;
	if (cAnsw == 'y')
		ReleaseMutex(hMut);

	WaitForMultipleObjects(COUNTTHREADS, ThreadArr, TRUE, INFINITE);

	//for (int i = 0; i < ARRSIZE; ++i)
		//cout << iArr[i] << " ";
	for (int i = 0; i < COUNTTHREADS; ++i)
	{
		CloseHandle(ThreadArr[i]);
	}
	CloseHandle(hMut);
	//CloseHandle(threadHandle);
	return 0;
}

DWORD WINAPI threadFunction(void* pData)
{
	dataForThread *pdata = static_cast<dataForThread*>(pData);
	cout << "Thread # " << GetCurrentThreadId() << " is waiting...\n";
	WaitForSingleObject(pdata->m_Mut, INFINITE);
	cout << "Thread # " << GetCurrentThreadId() << " processes data\n";
	for (int i = 0; i < pdata->m_nSize; ++i)
		cout << pdata->m_pArr[i] * pdata->m_nMult << " ";
	cout << endl;

	ReleaseMutex(pdata->m_Mut);
	delete pData;
	return 0;
}