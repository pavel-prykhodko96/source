// Homework4.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
int const ARRSIZE = 10;
int const MAXVALUE = 50;
void initArray(int iArray[][ARRSIZE]);
void showArray(int iArray[][ARRSIZE]);

int main()
{
	int iArr[ARRSIZE][ARRSIZE] = { 0 };
	initArray(iArr);
	showArray(iArr);
	return 0;
}
void initArray(int iArray[][ARRSIZE])
{
	srand(time(0));
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			if (i == j||i==(ARRSIZE-1-j))
			{
			}
			else 
			{
				iArray[i][j] = rand() % MAXVALUE;
			}
		}
	}
}
void showArray(int iArray[][ARRSIZE])
{
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			if (j % ARRSIZE == 0)
			{
				cout << endl;
			}
			cout << setw(4) << iArray[i][j];
		}
	}
}