
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int nNumber1(0), nNumber2(0);
	cout << "Please enter two numbers: ";
	cin >> nNumber1 >> nNumber2;
	if (nNumber1 > nNumber2)
	{
		int Changer = nNumber1;
		nNumber1 = nNumber2;
		nNumber2 = Changer;
	}
	for (int i = nNumber1; i <= nNumber2; ++i) //Checking diapason of numbers
	{
		for (int j=i; j >= 3; j /= 10) //Sequential checking: Does number contain 3?
		{
			if (j % 10 == 3)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}