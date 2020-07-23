#include "pch.h"
#include "Singleton.h"

int Singleton::m_nCountObj = 0;
int Singleton::m_nSize = 0;
int* Singleton::m_pArr = nullptr;
Singleton::Singleton(int size)
{
	if (1 == ++m_nCountObj)
	{
		m_pArr = new int[size];
		for (int i = 0; i < size; ++i)
			m_pArr[i] = i;
		m_nSize = size;
	}
	cout << "Singletones score for " << this << " " << m_nCountObj << endl;
}

Singleton::~Singleton()
{
	if (0 == --m_nCountObj)
	{
		delete[]m_pArr;
	}
	cout << "Destruction for " << this << endl;
}
void Singleton::show()
{
	for (int i = 0; i < m_nSize; ++i)
		cout << m_pArr[i] << " ";
	cout << endl;
}
