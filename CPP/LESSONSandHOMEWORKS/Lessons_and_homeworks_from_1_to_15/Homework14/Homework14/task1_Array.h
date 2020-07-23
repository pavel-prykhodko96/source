
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

	friend ostream & operator << (ostream& out, const Array& R);
	Array & operator = (const Array & R);
	friend Array operator + (const int & a, Array & R);
	Array operator + (const int & a);
	Array operator + (const Array & b);
	int operator [] (const int & b);

	void push_back(int n);
	void show();
	double averageVal();
	int size();
	void setName(char *pFileName);
	void setBackUp(BackUp * pBU);//To initialize BackUp
								 //And allocate memory
	void writeToFile();
	void createArrFromFile();
private:
	int m_nSize;
	int *m_pArr;
	int m_nCurInd;
	void addMemory();
	BackUp *m_pBackUp;
	char *m_pFileName = nullptr;
};

