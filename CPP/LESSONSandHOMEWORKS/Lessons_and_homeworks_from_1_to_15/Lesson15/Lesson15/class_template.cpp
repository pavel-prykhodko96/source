
#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
class Array
{
public:
	Array(int size) : m_pArr(nullptr), m_nSize(size), m_nCurInd(0)
	{
		if (m_nSize <= 0)
			m_nSize = 1;
		m_pArr = new T[m_nSize];
	}
	~Array() { delete[] m_pArr; }
	void push_back(T el)
	{
		if (m_nCurInd == m_nSize)
			addMem();
		m_pArr[m_nCurInd++] = el;
	}
	void show()
	{
		for (int i = 0; i < m_nCurInd; ++i)
			cout << m_pArr[i] << " ";
		cout << endl;
	}
private:
	T *m_pArr;
	int m_nSize;
	int m_nCurInd;
	void addMem()
	{
		T * temp = new T[2 * m_nSize];
		memcpy_s(temp, 2 * m_nSize * sizeof(T), m_pArr, sizeof(T)*m_nSize);
		m_nSize *= 2;
		delete[]m_pArr;
		m_pArr = temp;
	}
};

int main()
{
	Array <int> aObj(7);
	for (int i = 0; i < 10; ++i)
	{
		aObj.push_back(1.2 + i * 3);
	}
	aObj.show();
	Array <double> dObj(3);
	for (int i = 0; i < 10; ++i)
	{
		dObj.push_back(1.35465977*i);
	}
	dObj.show();
}