
#include "pch.h"
#include "Array.h"
#include <iostream>
using std::cout;
using std::endl;


Array::Array(int size):m_size(size),m_pArr(nullptr), m_curInd(0)
{
	cout << "Object was created!\n";
	if (m_size <= 0)
		m_size = 1;
	m_pArr = new int[m_size];
	cout << "Array constructor for: " << this << endl;
}

Array::~Array()
{
	cout << "Object was destroyed!\n";
	cout << "Array destructor for: " << this << endl;
	delete[] m_pArr;
}

void Array::addMemory()
{
	int *pTemp = new int[m_size * 2];
	for (int i = 0; i < m_size; ++i) //or memcpy 
	{
		pTemp[i] = m_pArr[i];
	}
	delete[] m_pArr;
	m_pArr = pTemp;
	m_size *= 2;
}

void Array::show()
{
	for (int i = 0; i < m_curInd; ++i)
	{
		cout << m_pArr[i] << " ";
	}
	cout << endl;
}

void Array::push_back(int n)
{
	if (m_curInd == m_size)
		addMemory();
	m_pArr[m_curInd] = n;
	++m_curInd;
}
double Array::averageVal()
{
	double result = 0;
	for (int i = 0; i < m_curInd; ++i)
	{
		result += m_pArr[i];
	}
	return (result /= m_curInd);
}
int Array::size() { return m_curInd; }