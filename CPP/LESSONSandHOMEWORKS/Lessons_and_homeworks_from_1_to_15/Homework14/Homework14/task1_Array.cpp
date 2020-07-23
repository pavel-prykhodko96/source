
#include "pch.h"
#include "task1_Array.h"
#include "task1_BackUp.h"

Array::Array(int *pArr, int size) :m_nSize(size), m_nCurInd(size), m_pArr(nullptr)
{
	cout << "Object was created!\n";
	if (m_nSize <= 0)
		m_nSize = 1;
	m_pArr = new int[m_nSize];
	for (int i = 0; i < m_nSize; ++i)
	{
		m_pArr[i] = pArr[i];
	}
	cout << "Array constructor for: " << this << endl;
}
Array::Array(int size):m_nSize(size),m_pArr(nullptr), m_nCurInd(0)
{
	cout << "Object was created!\n";
	if (m_nSize <= 0)
		m_nSize = 1;
	m_pArr = new int[m_nSize];
	cout << "Array constructor for: " << this << endl;
}
Array::Array(const Array & R)
{
	m_nSize = R.m_nSize;
	m_nCurInd = R.m_nCurInd;
	m_pArr = new int[R.m_nCurInd];
	memcpy(m_pArr, R.m_pArr, sizeof(int)*R.m_nSize);
	cout << "Copy constructor for " << this << endl;
}
Array::Array(Array && R)
{
	m_pArr = R.m_pArr;
	m_nSize = R.m_nSize;
	m_nCurInd = R.m_nCurInd;
	R.m_pArr = nullptr;
	cout << "Move constructor for " << this << endl;
}
Array::~Array()
{
	cout << "Object was destroyed!\n";
	cout << "Array destructor for: " << this << endl;
	delete[] m_pArr;
}
ostream& operator<< (ostream& out, const Array& R)
{
	for (int i = 0; i < R.m_nCurInd; ++i)
	{
		out << R.m_pArr[i] << " ";
	}
	return out;
}
Array &Array::operator = (const Array & R)
{
	if (this != &R) 
	{
		this->~Array();
		m_nSize = R.m_nSize;
		m_nCurInd = R.m_nCurInd;
		m_pArr = new int[R.m_nCurInd];
		memcpy(m_pArr, R.m_pArr, sizeof(int)*R.m_nSize);
		cout << "Assignment for " << this << endl;
		return *this;
	}
}
Array operator+ (const int & a, Array & R)
{
	Array result(R.m_nSize + 1);
	memcpy_s(result.m_pArr + 1, sizeof(int)*R.m_nSize, R.m_pArr, sizeof(int)*R.m_nSize);
	result.m_pArr[0] = a;
	result.m_nCurInd = R.m_nSize + 1;
	return result;
}
Array Array::operator+ (const int & a)
{
	Array result(m_nSize + 1);
	memcpy_s(result.m_pArr, sizeof(int)*m_nSize, m_pArr, sizeof(int)*m_nSize);
	result.m_pArr[m_nSize] = a;
	result.m_nCurInd = m_nSize + 1;
	return result;
}

Array Array::operator + (const Array &b)
{
	Array result(m_nSize + b.m_nSize);
	memcpy_s(result.m_pArr, sizeof(int)*m_nSize, m_pArr, sizeof(int)*m_nSize);
	memcpy_s(result.m_pArr + m_nSize, sizeof(int)*b.m_nSize, b.m_pArr, sizeof(int)*b.m_nSize);
	result.m_nCurInd = m_nSize + b.m_nSize;
	return result;
}
int Array::operator [] (const int & b)
{
	if (b < m_nCurInd)
	return m_pArr[b];
	else cout << "Out of range" << endl;
	return 0;
}
void Array::push_back(int n)
{
	if (m_nCurInd == m_nSize)
		addMemory();
	m_pArr[m_nCurInd] = n;
	++m_nCurInd;
}
void Array::show()
{
	for (int i = 0; i < m_nCurInd; ++i)
	{
		cout << m_pArr[i] << " ";
	}
	cout << endl;
}
double Array::averageVal()
{
	double result = 0;
	for (int i = 0; i < m_nCurInd; ++i)
	{
		result += m_pArr[i];
	}
	return (result /= m_nCurInd);
}
int Array::size() { return m_nCurInd; }
void Array::setName(char *pFileName)
{
	m_pFileName = pFileName;
}
void Array::setBackUp(BackUp * pBU)//To initialize BackUp
	                               //And allocate memory
{
	m_pBackUp = pBU;
}
void Array::writeToFile()
{
	if (m_pFileName != nullptr)
		m_pBackUp->save(m_pFileName, m_pArr, m_nCurInd);
	cout << "There are " << m_nCurInd
		<< " values in the file " << m_pFileName << endl;
}
void Array::createArrFromFile()
{
	if (m_pFileName != nullptr)
	{
		delete[]m_pArr;
		m_nCurInd = m_pBackUp->get_size();
		m_nSize = m_nCurInd;
		m_pArr = new int[m_nSize];
		m_pBackUp->read(m_pFileName, m_pArr);
	}
}
void Array::addMemory()
{
	int *pTemp = new int[m_nSize * 2];
	for (int i = 0; i < m_nSize; ++i) //or memcpy 
	{
		pTemp[i] = m_pArr[i];
	}
	delete[] m_pArr;
	m_pArr = pTemp;
	m_nSize *= 2;
}