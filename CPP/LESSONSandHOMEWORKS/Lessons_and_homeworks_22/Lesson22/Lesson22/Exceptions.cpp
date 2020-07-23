#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//try
	//{
	//	int nNum;
	//	cout << "Enter the num: ";
	//	cin >> nNum;
	//	if (nNum <= 0)
	//		throw (1);
	//}
	//catch (int n)
	//{
	//	cout << "catch block for int\n";
	//}
	//catch (...)
	//{
	//	cout << "catch for something else\n";
	//}
	//int nN;
	//cin >> nN;
	//return 0;
	int nCount = 0;
	try
	{		
		while (true)
		{
			new int[100000000ul];
			++nCount;
		}
	}
	catch (const std::bad_alloc& e)
	{
		cout << "Allocation failed!: " << e.what() << " " << nCount << endl;
	}
}
