// Lesson10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void one_or_zero(int nNum)
{
	unsigned int nKey = 1 << 31;
	for (int i = 1; i <= 32; ++i)
	{
		if (nNum &nKey)
			cout << 1;
		else cout << 0;
		if (i % 8 == 0) cout << " ";
		nKey = nKey >> 1;
	}
	cout << endl;
}
void print_drives(int nNum)
{
	unsigned int nKey = 1;
	char letter = 'A';
	for (int i = 0; i < 32; ++i)
	{
		if (nNum & nKey)
			cout << letter << ':' << endl;		
		++letter;
		nKey = nKey << 1;
	}
	cout << endl;
}
int main()
{
	//print_drives(GetLogicalDrives());
	//one_or_zero(12513542135);
	unsigned int nNum = 7;
	cout << ~nNum;
	return 0;
}
