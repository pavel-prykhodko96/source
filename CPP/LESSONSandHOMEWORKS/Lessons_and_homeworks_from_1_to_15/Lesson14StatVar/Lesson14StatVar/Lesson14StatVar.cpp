
#include "pch.h"
#include <iostream>
#include "A.h"
using namespace std;

int main()
{
	cout << A::m_nCountObj << endl; 
	{
		cout << A::getStatVar() << endl;
		A objA(7);
		cout << A::m_nCountObj << endl;
		A objArr[10];
		cout << A::m_nCountObj << endl;
	}
	cout << A::m_nCountObj << endl;
}


/*
void func()
{
	static int nStatic = 0; 
	int regularVar = 0;    
	cout << "StaticVar: " << ++nStatic << ", regularVar: " << ++regularVar << endl;
}

int main()
{
	for (int i = 0; i < 10; ++i)
		func();
	return 0;
}
*/