#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <condition_variable>
#include <mutex>
using namespace std;

const int SIZE = 10000;
const int THREADAMOUNT = 3;
struct DataForThread
{
	DataForThread() :m_ofsFile ("abc.log"){}
	string m_sWord;
	int m_pArr[SIZE];
	int m_nHowManyFinished = 0;
	condition_variable m_cCondVar;
	mutex m_mMutex;
	ofstream m_ofsFile;
};

void fir_thread(DataForThread* pData)
{
	{
		unique_lock <mutex> ul(pData->m_mMutex);
		pData->m_sWord = "FIRST_WORD_FIRST_WORD_FIRST_WORD_FIRST_WORD_FIRST_WORD\n";
		pData->m_ofsFile << pData->m_sWord;
		for (int i = 0; i < SIZE; ++i)
			pData->m_pArr[i] = 1;
		for (int i = 0; i < SIZE; ++i)
			pData->m_ofsFile << pData->m_pArr[i];
		pData->m_ofsFile << endl;
		++pData->m_nHowManyFinished;
	}
	while (pData->m_nHowManyFinished < THREADAMOUNT)
		pData->m_cCondVar.notify_one();
}
void sec_thread(DataForThread* pData)
{
	{
		unique_lock <mutex> ul(pData->m_mMutex);
		pData->m_cCondVar.wait(ul);
		pData->m_sWord = "SECOND_WORD_SECOND_WORD_SECOND_WORD_SECOND_WORD_SECOND_WORD\n";
		pData->m_ofsFile << pData->m_sWord;
		for (int i = 0; i < SIZE; ++i)
			pData->m_pArr[i] = 2;
		for (int i = 0; i < SIZE; ++i)
			pData->m_ofsFile << pData->m_pArr[i];
		pData->m_ofsFile << endl;
		++pData->m_nHowManyFinished;
	}
	while (pData->m_nHowManyFinished < THREADAMOUNT)
		pData->m_cCondVar.notify_one();
}
void third_thread(DataForThread* pData)
{
	{
		unique_lock <mutex> ul(pData->m_mMutex);
		pData->m_cCondVar.wait(ul);
		pData->m_sWord = "THIRD_WORD_THIRD_WORD_THIRD_WORD_THIRD_WORD_THIRD_WORD\n";
		pData->m_ofsFile << pData->m_sWord;
		for (int i = 0; i < SIZE; ++i)
			pData->m_pArr[i] = 3;
		for (int i = 0; i < SIZE; ++i)
			pData->m_ofsFile << pData->m_pArr[i];
		pData->m_ofsFile << endl;
		++pData->m_nHowManyFinished;
	}
	while (pData->m_nHowManyFinished < THREADAMOUNT)
		pData->m_cCondVar.notify_one();
}

int main()
{
	DataForThread* pData = new DataForThread;

	thread fir(fir_thread, pData);
	thread sec(sec_thread, pData);
	thread third(third_thread, pData);

	fir.join();
	sec.join();
	third.join();

	delete pData;
}
