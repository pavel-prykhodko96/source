
#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

struct DataForThread
{
	DataForThread(HANDLE g, HANDLE t) : prod(g),cons(t){}
	HANDLE prod;
	HANDLE cons;
	string s;
};

DWORD WINAPI pProd(void* pD)
{
	DataForThread* pd = static_cast<DataForThread*>(pD);
	for (int i = 0; i < 5; ++i)
	{
		std::stringstream ss;
		WaitForSingleObject(pd->cons, INFINITE);
		ss << " block data " << i;
		pd->s = ss.str();
		cout << "I sent " << i << endl;
		SetEvent(pd->prod);
	}
	return 0;
}

DWORD WINAPI pCons(void* pD)
{
	DataForThread* pd = static_cast<DataForThread*>(pD);
	for (int i = 0; i < 5; ++i)
	{
		WaitForSingleObject(pd->prod, INFINITE);
		cout << pd->s << endl;
		SetEvent(pd->cons);
	}
	return 0;
}
int main()
{
	HANDLE hProd = CreateEventA(0, FALSE, FALSE, 0);
	HANDLE hCons = CreateEventA(0, FALSE, FALSE, 0);

	DataForThread* pData = new DataForThread (hProd,hCons);

	HANDLE thrProd = CreateThread(0, 0, pProd, pData, 0, 0);
	HANDLE thrCons = CreateThread(0, 0, pCons, pData, 0, 0);
	
	SetEvent(hCons);

	WaitForSingleObject(thrProd, INFINITE);
	WaitForSingleObject(thrCons, INFINITE);

	CloseHandle(hProd);
	CloseHandle(hCons);
	CloseHandle(thrProd);
	CloseHandle(thrCons);
	delete pData;

	return 0;
}