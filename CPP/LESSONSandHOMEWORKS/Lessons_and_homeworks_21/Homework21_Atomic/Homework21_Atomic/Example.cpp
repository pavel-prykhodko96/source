#include "pch.h"
#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

//atomic
struct dataT
{
	int* m_pArr;
	int m_size;
	std::atomic_int* m_pInd;
	int m_Num;
};

void threadFF(dataT* pData)
{
	while (true)
	{
		int iCurInd = (pData->m_pInd)->fetch_add(1);
		//cout << std::this_thread::get_id() << "  iCurInd = " << iCurInd << endl;
		if (iCurInd >= pData->m_size)
			break;
		pData->m_pArr[iCurInd] = pData->m_Num;
		this_thread::sleep_for(chrono::nanoseconds(1));
	}
}

int main()
{
	cout << is_trivially_copyable <dataT>::value << endl;
	atomic<int>* pAtomInd = new atomic<int>(0);
	const int ARRSIZE = 200000;
	const int COUNTTHREADS = 4;
	int iArr[ARRSIZE] = { 0 };
	thread arrThr[COUNTTHREADS];
	dataT dataArr[COUNTTHREADS];
	for (int i = 0; i < COUNTTHREADS; ++i)
	{
		dataArr[i].m_pArr = iArr;
		dataArr[i].m_size = ARRSIZE;
		dataArr[i].m_pInd = pAtomInd;
		dataArr[i].m_Num = i + 2;
		arrThr[i] = thread(threadFF, dataArr + i);
	}

	for (auto& thr : arrThr)
		thr.join();
	//Diagnostic
	cout << "work was completed!" << endl;
	int iCountAr[COUNTTHREADS + 2] = { 0 };
	for (int i = 0; i < ARRSIZE; ++i)
	{
		//cout << iArr[i] << " ";
		iCountAr[iArr[i]]++;
	}
	for (int i = 2; i < COUNTTHREADS + 2; ++i)
	{
		cout << i << " = " << iCountAr[i] << " " << endl;
	}
	cout << endl;
	//End of diagnostic
	delete pAtomInd;
	return 0;
}
