
#include "pch.h"
#include "Array.h"

Array::Array(int *pArr, int size) :m_size(size), m_curInd(size), m_pArr(nullptr)
{
	cout << "Object was created!\n";
	if (m_size <= 0)
		m_size = 1;
	m_pArr = new int[m_size];
	for (int i = 0; i < m_size; ++i)
	{
		m_pArr[i] = pArr[i];
	}
	cout << "Array constructor for: " << this << endl;
}
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
void Array::setName(char *pFileName)
{
	m_pFileName = pFileName;
}
void Array::setBackUp(BackUp * pBU)
{
	m_pBackUp = pBU;
}
void Array::writeToFile()
{
	if (/*m_pBackUp != nullptr &&*/m_pFileName != nullptr)
		m_pBackUp->save(m_pFileName, m_pArr, m_curInd);
	cout << "There are " << m_curInd
		<< " values in the file " << m_pFileName << endl
		<< "Be careful with the size of the array during its creation!\n";
}
void Array::createArrFromFile()
{
	if (/*m_pBackUp != nullptr &&*/m_pFileName != nullptr)
	{
		cout << "Please tell the size of the array you want to create: \n";
		int nSize(0);
		cin >> nSize;
		delete[]m_pArr;
		m_curInd = nSize;
		m_size = nSize;
		m_pArr = new int[nSize];
		m_pArr = m_pBackUp->read(m_pFileName, nSize);
	}
}