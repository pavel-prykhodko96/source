// Lesson22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <string>
using namespace std;

struct DataForConVar
{
	mutex m_mMut;
	bool m_bIsReady = false;
	condition_variable m_CondVar;
	string m_sText;
};

void tProdFunc(DataForConVar* pData)
{
	for (int i = 0; i < 5; ++i)
	{
		{
			unique_lock<mutex> ul(pData->m_mMut);
			pData->m_sText += "Hi ";
			pData->m_bIsReady = true;
			cout << "producer: " << pData->m_sText << endl;
		}
		pData->m_CondVar.notify_one();
	}
}
void tConsFunc(DataForConVar* pData)
{
	for (int i = 0; i < 5; ++i)
	{
		unique_lock <mutex> ul(pData->m_mMut);
		pData->m_CondVar.wait(ul, [&pData]() {return pData->m_bIsReady; });
		pData->m_bIsReady = false;
		cout << "consumer: " << pData->m_sText << endl;
	}
}

int main()
{
	DataForConVar *pData = new DataForConVar;

	thread tProd(tProdFunc,pData);
	thread tCons(tConsFunc,pData);

	tProd.join();
	tCons.join();

	delete pData;
}
