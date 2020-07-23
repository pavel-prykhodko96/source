
#pragma once
class Array
{
	int m_size;
	int *m_pArr;
	int m_curInd;
	void addMemory();
public:
	explicit Array(int size);
	~Array();
	void show();
	void push_back(int n);
	double averageVal();
	int size();
};

