// Lesson6.1RECURSION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
	int nValue = 5;
	cout << factorial(nValue) << endl;
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}