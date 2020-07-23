
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class  moreThen
{
public:
	moreThen(int n) : m_CompValue(n) {}
	bool operator() (int el) { return el > m_CompValue; }
	void setCompVal(int n) { m_CompValue = n; }
private: 
	int m_CompValue = 0;
};

int main()
{
	vector <int> VC;
	for (int i = 0; i < 15; ++i)
		VC.push_back(rand() % 21);
	moreThen objcomp(15);
	int countElements = count_if(VC.begin(), VC.end(), objcomp);
}

