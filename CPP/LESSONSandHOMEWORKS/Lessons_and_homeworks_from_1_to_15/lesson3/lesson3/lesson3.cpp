// lesson3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int nLenght(0);
	double nWidth(0);
	int nMenu(0);
	cout << "1. Square: a\n2. Rectangle: a*b\n3. Treangle: 1/2h*a\n";
	cin >> nMenu;
	switch (nMenu)
	{
	case 1: 
	{
		cout << "Please enter the lenght of square`s side: ";
		cin >> nLenght;
		cout << "The area is: " << nLenght * nLenght << endl;
		break;
	}
	case 2:
	{
		cout << "Please enter the lenght and width of rectangle: ";
		cin >> nLenght >> nWidth;
		cout << "The area is: " << nLenght * nWidth << endl;
		break;
	}
	case 3:
	{
		cout << "Please enter the lenght and height of triangle: ";
		cin >> nLenght >> nWidth;
		cout << "The area is: " << nLenght * nWidth/2.0 << endl;
		break;
	}
	default: cout << "Please choose the correct option!" << endl;
	}
	int nMonth(0);
	int nDay(0);
	int nYear(0);
	int February(0);
	cout << "Please enter the date and month (dd mm yyyy): ";
	cin >> nDay >> nMonth >> nYear;
	if (nYear % 4 == 0) February = 29;
	else February = 28;
		switch (nMonth)
		{
		case 1: cout << nDay << " from the start of the year!" << endl;
			break;
		case 2: cout << nDay + 31 << " from the start of the year!" << endl;
			break;
		case 3: cout << nDay + 31 + February << " from the start of the year!" << endl;
			break;
		case 4: cout << nDay + 62 + February << " from the start of the year!" << endl;
			break;
		case 5: cout << nDay + 92 + February << " from the start of the year!" << endl;
			break;
		case 6: cout << nDay + 123 + February << " from the start of the year!" << endl;
			break;
		case 7: cout << nDay + 153 + February << " from the start of the year!" << endl;
			break;
		case 8: cout << nDay + 184 + February << " from the start of the year!" << endl;
			break;
		case 9: cout << nDay + 215 + February << " from the start of the year!" << endl;
			break;
		case 10: cout << nDay + 245 + February << " from the start of the year!" << endl;
			break;
		case 11: cout << nDay + 276 + February << " from the start of the year!" << endl;
			break;
		case 12: cout << nDay + 306 + February << " from the start of the year!" << endl;
			break;
		default: cout << "It isn`t the month`s number!" << endl;
		}
		return 0;	
}
