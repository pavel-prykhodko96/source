
#include "pch.h"
#include <iostream>
using namespace std;

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
	  