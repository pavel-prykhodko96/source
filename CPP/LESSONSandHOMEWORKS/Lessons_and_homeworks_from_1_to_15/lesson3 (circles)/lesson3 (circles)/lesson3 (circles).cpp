// lesson3 (circles).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int nHeight(0), nWidth(0);
	cin >> nHeight >> nWidth;
	for (int i = 0; i < nHeight; ++i)
	{
		if (i == 0 || i == nHeight - 1)
		{
			for (int j = 0; j < nWidth; ++j)
			{
				cout << "*";
			}
		}
		else
		{
			cout << "*";
			for (int j = 0; j < nWidth - 2; ++j)
			{
				cout << " ";
			}
			if (nWidth > 1)
			{
				cout << "*";
			}
		}
		cout << endl;
	}
	/*int nLenght(0), nWidth(0), nCountStars(1);
	cout << "Please enter the lenght and width of rectangle: ";
	cin >> nLenght >> nWidth;
	int nCountSpaces = nLenght - 1;
	for (int i = 0; i < nWidth; ++i)
	{
		for (int j = 0; j < nCountSpaces; ++j)
			cout << " ";
		for (int j = 0; j < nCountStars; ++j)
			cout << "*";
		++nCountStars;
		--nCountSpaces;
		cout << endl;
	}
	*/
	/*
	cout << "Please enter the lenght and width of rectangle: ";
	cin >> nLenght >> nWidth;
	for (int i = 0; i < nWidth; ++i)
	{
		for (int j = 0; j < nLenght; ++j)
			cout << "*";
		cout << endl;
	}
	*/
	/*
	cout << "Please enter the lenght and width of rectangle: ";
	cin >> nLenght >> nWidth;
	for (int i = 0; i < nWidth; ++i)
	{
		for (int j = 0; j < nCountStars; ++j)
			cout << "*";
		cout << endl;
		++nCountStars;
	}
	*/
	/*
	int nSize(0), nWidth(0), nCounter(0), nString(0);
	cout << "Please enter number of * and width of string: ";
	cin >> nSize >> nWidth;
	for (int i = 0; i < nSize; ++i)
	{
		if (nString % 2 == 0)
		{
			cout << "*";
		}
		else
		{
			cout << "$";
		}
		++nCounter;
		if (nCounter == nWidth)
		{
			cout << endl;
			nCounter = 0;
			++nString;
		}
	}
	*/
	return 0;
}
