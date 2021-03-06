// Lesson21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

struct DataForThread
{
	int m_ID;
	int m_nSize;
	int *m_pArr;
	int *m_pInd;
	HANDLE m_hMut;
};

DWORD WINAPI pF(void* pData)
{
	DataForThread* pD = static_cast<DataForThread*>(pData);
	while (true)
	{
		WaitForSingleObject(pD->m_hMut, INFINITE);
		int ind = (*pD->m_pInd)++;
		ReleaseMutex(pD->m_hMut);
		if (ind < pD->m_nSize)
			pD->m_pArr[ind] = pD->m_ID;
		else break;
	}
	return 0;
}

int main()
{
	const int ARRSIZE = 25000;
	const int THREADCOUNT = 4;
	HANDLE ThrArray[THREADCOUNT];
	DataForThread DaFoThArr[THREADCOUNT];
	int iArr[ARRSIZE] = { 0 };
	int *pInd = new int{ 0 };

	HANDLE hMut = CreateMutexA(0, FALSE, "process name");
	for (int i = 0; i < THREADCOUNT; ++i)
	{
		DaFoThArr[i].m_ID = i * 10;
		DaFoThArr[i].m_nSize = ARRSIZE;
		DaFoThArr[i].m_pArr = iArr;
		DaFoThArr[i].m_pInd = pInd;
		DaFoThArr[i].m_hMut = hMut;

		ThrArray[i] = CreateThread(0, 0, pF, DaFoThArr+i, 0, 0);
	}
	WaitForMultipleObjects(THREADCOUNT, ThrArray, TRUE, INFINITE);

	for (int i = 0; i < ARRSIZE; ++i)
		std::cout << iArr[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < THREADCOUNT; ++i)
		CloseHandle(ThrArray[i]);
	delete pInd;
	return 0;
}