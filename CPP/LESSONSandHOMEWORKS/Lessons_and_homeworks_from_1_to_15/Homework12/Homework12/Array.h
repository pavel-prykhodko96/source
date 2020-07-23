
#pragma once
#include "BackUp.h"

class Array
{
	int m_size;
	int *m_pArr;
	int m_curInd;
	void addMemory();
	BackUp *m_pBackUp;
	char *m_pFileName = nullptr;
public:
	void setName(char *pFileName);
	void setBackUp(BackUp * pBU);
	void writeToFile();
	void createArrFromFile();
	explicit Array(int size);
	explicit Array(int *pArr, int size);
	~Array();
	void show();
	void push_back(int n);
	double averageVal();
	int size();
};

