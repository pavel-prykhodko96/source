
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int nNumber;
	cout << "There is multiplication table by 3:" << endl;
	cout << "1*3=3" << endl;
	cout << "2*3=6" << endl;
	cout << "3*3=9" << endl;
	cout << "4*3=12" << endl;
	cout << "5*3=15" << endl;
	cout << "6*3=18" << endl;
	cout << "7*3=21" << endl;
	cout << "8*3=24" << endl;
	cout << "9*3=27" << endl << endl;
	cout << "Enter the 3-digital number, please: ";
	cin >> nNumber;
	cout << nNumber / 100 << endl << nNumber / 10 % 10 << endl << nNumber % 10 << endl;
	return 0;
}
