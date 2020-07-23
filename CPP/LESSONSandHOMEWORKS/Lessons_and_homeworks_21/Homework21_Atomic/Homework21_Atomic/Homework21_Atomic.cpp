
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <atomic>
using namespace std;

struct DataForThread
{
	int m_ID;
	int m_nSize;
	int *m_pArr;
	atomic_int *m_pInd;
};

DWORD WINAPI pF(void* pData)
{
	DataForThread* pD = static_cast<DataForThread*>(pData);
	while (true)
	{
		/*OLD:*/ //WaitForSingleObject(pD->m_hMut, INFINITE);
		int ind = (*pD->m_pInd).fetch_add(1);
		/*OLD:*/ //ReleaseMutex(pD->m_hMut);
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
	atomic_int *pInd = new atomic_int{ 0 };

	/*OLD:*/ //HANDLE hMut = CreateMutexA(0, FALSE, "process name");
	for (int i = 0; i < THREADCOUNT; ++i)
	{
		DaFoThArr[i].m_ID = i * 1;
		DaFoThArr[i].m_nSize = ARRSIZE;
		DaFoThArr[i].m_pArr = iArr;
		DaFoThArr[i].m_pInd = pInd;
		/*OLD:*/ //DaFoThArr[i].m_hMut = hMut;

		ThrArray[i] = CreateThread(0, 0, pF, DaFoThArr + i, 0, 0);
	}
	WaitForMultipleObjects(THREADCOUNT, ThrArray, TRUE, INFINITE);

	//Diagnostic
	cout << "work was completed!" << endl;
	int iCountAr[THREADCOUNT] = { 0 };
	for (int i = 0; i < ARRSIZE; ++i)
	{
		//cout << iArr[i] << " ";
		iCountAr[iArr[i]]++;
	}
	for (int i = 0; i < THREADCOUNT; ++i)
	{
		cout << i << " = " << iCountAr[i] << " " << endl;
	}
	cout << endl;
	//End of diagnostic
	/*
	for (int i = 0; i < ARRSIZE; ++i)
		std::cout << iArr[i] << " ";
	std::cout << std::endl;
	*/
	for (int i = 0; i < THREADCOUNT; ++i)
		CloseHandle(ThrArray[i]);
	delete pInd;
	return 0;
}