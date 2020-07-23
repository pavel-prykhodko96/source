
#pragma once
#include <iostream>
using namespace std;
class BackUp;

class Array
{
public:
	explicit Array(int size);
	explicit Array(int *pArr, int size);
	Array(const Array & R);
	Array(Array && R);
	~Array();

	friend ostream & operator<< (ostream& out, const Array& R);
	Array & operator = (const Array & R);
	friend Array operator + (const int & a, const Array & R);
	Array operator + (const int & a) const;
	Array operator + (const Array & b) const;

	void push_back(int n);
	void show();
	double averageVal();
	int size();
private:
	int m_nSize;
	int *m_pArr;
	int m_nCurInd;
	void addMemory();
	BackUp *m_pBackUp;
	char *m_pFileName = nullptr;
};

