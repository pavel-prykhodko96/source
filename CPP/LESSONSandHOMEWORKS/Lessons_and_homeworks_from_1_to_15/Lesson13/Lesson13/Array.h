
#pragma once
#include <iostream>
using namespace std;
class BackUp;

class Array
{
private:
	int m_nSize;
	int *m_pArr;
	int m_nCurInd;
	void addMemory();
	BackUp *m_pBackUp;
	char *m_pFileName = nullptr;
public:
	friend ostream& operator<< (ostream& out, const Array& R);
	void setName(char *pFileName);
	void setBackUp(BackUp * pBU);
	void writeToFile();
	void createArrFromFile();
	explicit Array(int size);
	//Array();
	explicit Array(int *pArr, int size);
	~Array();
	Array(const Array & R);
	Array & operator = (const Array & R);
	Array operator + (const Array & b);
	void show();
	void push_back(int n);
	double averageVal();
	int size();
};

