// Lesson2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int nGlobal = 11;

int main()
{
	/*char Letter('a');
	cout << "Enter the letter, please: ";
	cin >> Letter;
	if (Letter >= 65 && Letter <= 90)
		cout << "This is the capital letter!" << endl;
	else if (Letter >= 97 && Letter <= 122)
		cout << "This is the small letter!" << endl;
	else cout << "This isn`t letter!" << endl;
	return 0;
	*/
	/*
	int nFirst(0);
	int nSecond(0);
	cout << "Enter first number, please: ";
	cin >> nFirst;
	cout << "Enter second number, please: ";
	cin >> nSecond;
	if (nFirst > nSecond)
		cout << nFirst << endl;
	else if (nFirst < nSecond)
		cout << nSecond << endl;
	else cout << "The numbers are equal!" << endl;
	return 0;
	int x(0);
	int y(0);
	int a = 5;
	int b = 5;
	cout << "enter the X and Y coordinates: ";
	cin >> x >> y;
	/*if (x > 0 && x < 10 && y > 0 && y < 10)
		cout << "Bingo!" << endl;
	else cout << "You missed!" << endl;
	
	if ((x-a)*(x-a)+(y-b)*(y-b)<25)
		cout << "Bingo!" << endl;
	else cout << "You missed!" << endl;
	*/
	int nNum1, nNum2;
	char cSym;
	cout << "Enter 2 numbers and operator, please: ";
	cin >> nNum1 >> nNum2 >> cSym;
	switch (cSym)
	{
	case '+':
		cout << "The result is: " << nNum1 + nNum2 << endl;
		break;
	case '/': if (nNum2!=0) cout << "The result is: " << nNum1 / nNum2 << endl;
			  else cout << "Divide to zero!" << endl;
		break;
	default:
		cout << "This operator is wrong!";
			break;
	}
	return 0;
}