// conditionVariable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <sstream>
#include <condition_variable>

using namespace std;

struct dataForThread
{
	string m_str;
	mutex m_Mut;
	bool bProdIsReady = false;
	condition_variable m_conVar;
	atomic<bool> m_NotificationWasReceved = false;
};

void producer(dataForThread* pData)
{
	for (int i = 0; i < 5; ++i)
	{
		{
			stringstream sss;
			sss << " data block " << i;
			lock_guard<mutex> lg(pData->m_Mut);
			pData->m_str = sss.str();
			pData->bProdIsReady = true;
			cout << "produser: " << pData->m_str.data() << endl;
			pData->m_NotificationWasReceved.store(false);
		}
		while (true)
		{
			pData->m_conVar.notify_one();
			if (pData->m_NotificationWasReceved.load())
				break;

		}
	}
}

void consumer(dataForThread* pData)
{
	for (int i = 0; i < 5; ++i)
	{
		unique_lock<mutex> ul(pData->m_Mut);
		pData->m_conVar.wait(ul, [&pData]() {return pData->bProdIsReady; });
		pData->bProdIsReady = false;
		cout << "consumer: " << pData->m_str.data() << endl;
		pData->m_NotificationWasReceved.store(true);
	}
}


int main()
{
	dataForThread* pData = new dataForThread;
	thread trProd(producer, pData);
	thread trConsum(consumer, pData);

	trProd.join();
	trConsum.join();

    return 0;
}

