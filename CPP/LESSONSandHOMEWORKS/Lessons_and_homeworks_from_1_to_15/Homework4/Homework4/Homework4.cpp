
#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;


//Functions for arrays
const int ARRSIZE = 50;
void showArray (int iArr[], int nSize);
int findHighest (int iArr[], int nSize);
int findLowest(int iArr[], int nSize);
void diapason(int iArr[], int lowestnum, int highestnum);
void sum20 (int iArr[], int nSize);
void find_number(int iArr[], int nSize);
void statistics(int iArr[], int nSize);
void comparison(int iArr1[], int iArr2[],int nMaxNumber);
//General function main() for one-dimensional array with initializer inside:
int main()
{
	int iArrayFirst[ARRSIZE]{ 0 };
	int iArraySecond[ARRSIZE]{ 0 };
	int nMaxNumber = 20;
	srand(time(0));
	for (int i = 0; i < ARRSIZE; ++i)
	{
		iArrayFirst[i] = rand() % nMaxNumber;
	}
	for (int i = 0; i < ARRSIZE; ++i)
	{
		iArraySecond[i] = rand() % nMaxNumber;
	}
	cout << "Values of the first array: ";
	showArray(iArrayFirst, ARRSIZE);
	cout << "Values of the second array: ";
	showArray(iArraySecond, ARRSIZE);
	cout << "The same values are: ";
	comparison(iArrayFirst, iArraySecond, nMaxNumber);
	return 0;
}
//Output all values of the array:
void showArray(int iArr[], int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}
void comparison(int iArr1[], int iArr2[], int nMaxNumber)
{
	int iArrCompare[ARRSIZE]{ 0 }, nIndexArrCompare(0);
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			for (int k = 0; k < nIndexArrCompare; ++k)
			{
				if (iArr1[i] == iArrCompare[k])
				{
					++i;
					k = 0;
				}
			}
			if (iArr1[i] == iArr2[j])
			{
				iArrCompare[nIndexArrCompare++] = iArr1[i];
				break;
			}
		}
	}
	showArray(iArrCompare, nIndexArrCompare);
}

//Outputing numbers and how much they were meeted:
/*void statistics(int iArr[], int nMaxValue)
{
	int nCounter(0);
	for (int i = 0; i<nMaxValue;++i)
	{
		cout << "Number: " << i << " "; 
		for (int j = 0; j < ARRSIZE; ++j)
		{
			if (iArr[j] == i)
			{
				++nCounter;
			}
		}
		cout << "was meeted " << nCounter << " times!" << endl;
		nCounter = 0;
	}
}*/
//Finding places where number is situated and count how much that will be meeted:
/*void find_number(int iArr[], int nSize)
{
	int nNumber(0), nCounter(0);
	cout << "Please enter the number you want to find: ";
	cin >> nNumber;
	cout << "Your number is located at these places: ";
	for (int i = 0; i < nSize; ++i)
	{
		if (iArr[i] == nNumber)
		{
			cout << "[" << i << "] ";
			++nCounter;
		}
	}
	cout << endl << "Your number was meeted " << nCounter << " times!" << endl;
}*/
//Functions for finding diapason:
/*int findHighest(int iArr[], int nSize)
{
	int nCurrent(0), nIndexhigh(0);
	for (int i = 0; i < nSize; ++i)
	{
		if (iArr[i] > nCurrent)
		{
			nCurrent = iArr[i];
			nIndexhigh = i;
		}
	}
	return nIndexhigh;
}
int findLowest(int iArr[], int nSize)
{
	int nCurrent(iArr[0]), nIndexlow(0);
	for (int i = 0; i < nSize; ++i)
	{
		if (iArr[i] < nCurrent)
		{
			nCurrent = iArr[i];
			nIndexlow = i;
		}
	}
	return nIndexlow;
}
void diapason(int iArr[], int lowestnum, int highestnum)
{
	int changer(0);
	if (lowestnum > highestnum)
	{
		changer = lowestnum;
		lowestnum = highestnum;
		highestnum = changer;
	}
	for (int i = lowestnum; i <= highestnum; ++i)
	{
		cout << iArr[i] << " ";
	}
}*/
//find two numbers which stand nearby and their sum = 20:
/*void sum20(int iArr[], int nSize)
{
	for (int i = 0; i < nSize - 1; ++i)
	{
		if (iArr[i] + iArr[i + 1] == 20)
		{
			cout << "(" << iArr[i] << "," << iArr[i + 1] << ")\n";
		}
	}
}*/
//Presentation of cout array without functions (first version - not necessary):
/*
int main()
{
	int iArr[ARRSIZE];
	srand(time(0));
	for (int i = 0; i < ARRSIZE; ++i)
	{
		iArr[i] = rand() % 26;
	}
	for (int i = 0; i < ARRSIZE; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < ARRSIZE; i+=2)
	{
		cout << iArr[i] << " ";
	}
}
*/
//Cycle for figure with menu:
/*int main()
{
	int nLenght(0);
	double nWidth(0);
	int nMenu(0);
	char cAnswer('y');
	do
	{
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
			cout << "The area is: " << nLenght * nWidth / 2.0 << endl;
			break;
		}
		default: cout << "Please choose the correct option!" << endl;
		}
		cout << "Do you wish to continue?(y/n): ";
		cin >> answer;
		system("Cls");
	}
	while (cAnswer=='y');
}*/
//Calculator with cycle:
/*
int main()
{
	int nNum1, nNum2;
	char cSym, cAnswer = 'y';
	do
	{
		cout << "Enter 2 numbers and operator (+,-,*,/), please(x+y): ";
		cin >> nNum1 >> cSym >> nNum2;
		switch (cSym)
		{
		case '+':
			cout << "The result is: " << nNum1 + nNum2 << endl;
			break;
		case '-':
			cout << "The result is: " << nNum1 - nNum2 << endl;
			break;
		case '*':
			cout << "The result is: " << nNum1 * nNum2 << endl;
			break;
		case '/': if (nNum2 != 0) cout << "The result is: " << nNum1 / nNum2 << endl;
				  else cout << "Can`t divide to zero!" << endl;
			break;
		default:
			cout << "This operator is wrong!" << endl;
			break;
		}
		cout << "Do you wish continue (y/n)?: ";
		cin >> cAnswer;
		system("Cls");
	}
	while (cAnswer == 'y');
	return 0;
}
*/
//Two - dimensional arrays:
/*const int ARRSIZE = 8;
int main()
{
	int iArr[ARRSIZE][ARRSIZE] = { 0 };
	for (int i = 0; i < ARRSIZE; ++i)
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			iArr[i][j] = rand() % 20;
			cout << setw(4) << iArr[i][j];
		}
		cout << endl;
	}
}
*/