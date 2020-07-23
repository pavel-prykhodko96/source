
#include "pch.h"
#include <iostream>
#include "Array.h"
#include <stdlib.h> 

//class Array;

using namespace std;

int main()
{
	int nVal;
	{
		Array myArr(3);
		while (cin >> nVal)
			myArr.push_back(nVal);
		myArr.show();
		cout << myArr.averageVal() << endl
			<< myArr.size() << endl;
	}
	if (_CrtDumpMemoryLeaks())
		cout << "Memory LEAKS!\n";
	else cout << "Memory is OK!\n";
	return 0;
}