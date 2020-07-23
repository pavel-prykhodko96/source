// Homework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int nSideSize(0);
	cout << "Please enter rhombus` side size: ";
	cin >> nSideSize;
	for (int i = 1; i < (nSideSize * 2); ++i) //Number of string == i
	{
		for (int j = nSideSize; j > i; --j) //Output spaces before half
		{
			cout << " ";
		}
		for (int j = nSideSize; j < i; ++j) //Output spaces after half
		{
			cout << " ";
		}
			cout << "*";
		if (i <= nSideSize)
		{
			for (double j = 1.5; j < i; j += 0.5) //Output stars before half
			{
				cout << " ";
			}
		}
		else
		{
			for (double j = i + 1.5; j < (nSideSize * 2); j += 0.5) //Output stars after half
			{
				cout << " ";
			}
		}
		if (i > 1 && i < (nSideSize * 2 - 1))
		{
			cout << "*";
		}
		cout << endl;	
	}
	return 0;
}
	/*
	for (int i = 1; i < (nSideSize * 2); ++i) //Number of string ==i
	{
		for (int j = nSideSize; j > i; --j) //Output spaces before half
		{
			cout << " ";
		}
		for (int j = nSideSize; j < i; ++j) //Output spaces after half
		{
			cout << " ";
		}
		if (i <= nSideSize)
		{
			for (double j = 0.5; j < i; j += 0.5) //Output stars before half
			{
				cout << "*";
			}
		}
		else
		{
			for (double j = i+0.5 ; j < (nSideSize * 2); j += 0.5) //Output stars after half
			{
				cout << "*";
			}
		}
			cout << endl;
	}
	return 0;
}
*/
   