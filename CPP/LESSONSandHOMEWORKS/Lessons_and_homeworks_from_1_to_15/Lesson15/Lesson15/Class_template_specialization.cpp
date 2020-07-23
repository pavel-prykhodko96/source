
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

template<>          //так прописывается специализированный класс,
class Array <char*> //будет работать только если уже есть "общий"
{
public:
	Array(int size) : m_pArr(nullptr), m_nSize(size), m_nCurInd(0)
	{
		if (m_nSize <= 0)
			m_nSize = 1;
		m_pArr = new char*[m_nSize];
	}
	~Array()
	{
		//было: delete[] m_pArr; 
		for (int i = 0; i < m_nCurInd; ++i)
			delete[]m_pArr[i]; //like deleteting 2-dimensional 
		delete[]m_pArr;        //array
	}
	void push_back(const char* el)
	{
		if (m_nCurInd == m_nSize)
			addMem();
		//было: m_pArr[m_nCurInd++] = el;
		//меняем на:
		char *temp = new char[strlen(el) + 1]; //new char делается чтобы 
	                               //данные записались в куче, иначе они 
		                           // удалятся после работы деструктора
		memcpy_s(temp, sizeof(char)*strlen(el) + sizeof(char), el,
			sizeof(char)*strlen(el) + sizeof(char));
		m_pArr[m_nCurInd++] = temp; //присваиваем указатель temp по
									//адресу которого записана строка
	}
	void show()
	{
		for (int i = 0; i < m_nCurInd; ++i)
			cout << m_pArr[i] << " ";
		cout << endl;
	}
private:
	char **m_pArr;
	int m_nSize;
	int m_nCurInd;
	void addMem()
	{
		char** temp = new char*[2 * m_nSize];
		memcpy_s(temp, 2 * m_nSize * sizeof(char*), m_pArr, sizeof(char*)*m_nSize);
		m_nSize *= 2;
		delete[]m_pArr;
		m_pArr = temp;
	}
};

int main()
{
	{
		Array <char*> cObj(3);
		{
			char str[] = "Hello";
			cObj.push_back(str);
			cObj.push_back("world");
		}
		cObj.show();
	}
	if (_CrtDumpMemoryLeaks())
		cout << "Memory leaks" << endl;
}