
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//THE TASK "WHAT NUMBER IS BIGGER?"

	/*
	int nFirst(0);
	int nSecond(0);
	cout << "Enter first number, please: ";
	cin >> nFirst;
	cout << "Enter second number, please: ";
	cin >> nSecond;
	if (nFirst > nSecond)
		cout << nFirst << " is bigger" << endl;
	else if (nFirst < nSecond)
		cout << nSecond << " is bigger" << endl;
	else cout << "The numbers are equal!" << endl;
	*/

	//THE TASK "THE INTERSECTION OF THE CIRCLES"
	
	
	int xFirstC(0), yFirstC(0), xSecondC(0), ySecondC(0), rFirstC(0), rSecondC(0);
	cout << "enter the X-, Y- coordinates of centre and R(radius) for first circle: ";
	cin >> xFirstC >> yFirstC >> rFirstC;
	cout << "enter the X-, Y- coordinates of centre and R(radius) for second circle: ";
	cin >> xSecondC >> ySecondC >> rSecondC;
	//The equation for distance between two points is: |AB|² = (y2 - y1)² + (x2 - x1)²
	if (((rFirstC + rSecondC)*(rFirstC + rSecondC)) > ((xSecondC - xFirstC)*(xSecondC - xFirstC) + (ySecondC - yFirstC)*(ySecondC - yFirstC)))
		cout << "The circles intersect!" << endl;
	else if (((rFirstC + rSecondC)*(rFirstC + rSecondC)) == ((xSecondC - xFirstC)*(xSecondC - xFirstC) + (ySecondC - yFirstC)*(ySecondC - yFirstC)))
		cout << "The circles intersect in one point!" << endl;
	else cout << "The circles don`t intersect!" << endl;
	
	
	//THE TASK "CALCULATOR"
	
	/*
	int nNum1, nNum2;
	char cSym;
	cout << "Enter 2 numbers and operator (+,-,*,/), please: ";
	cin >> nNum1 >> nNum2 >> cSym;
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
		cout << "This operator is wrong!";
		break;
	}
	*/

	//THE TASK "WHAT DAY IS TODAY?"

	/*
	int nDay;
	cout << "Enter the day of the week number: ";
	cin >> nDay;
	switch (nDay)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		cout << "It`s a work day!" << endl;
		break;
	case 6:
	case 7:
		cout << "It`s an off day!" << endl;
		break;
	default:
		cout << "It`s not the day of the week!" << endl;
	}
	*/

	return 0;
}