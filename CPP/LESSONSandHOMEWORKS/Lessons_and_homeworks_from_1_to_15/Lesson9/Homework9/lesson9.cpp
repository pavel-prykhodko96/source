/*
#include "pch.h"
#include "definitions.h"
#include "square.h"
#include "cube.h"


#define product(n,m) n*m
int main()
{
	cout << product(3, 2) << endl;
	cout << cube(9) << endl;
	cout << __FILE__ << endl;
	return 0;
}
*/
/*
#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;

enum Data_Type { T_INT = 10, T_DOUBLE, T_CARD };
struct Data
{
	union //Without name
	{
		char m_cWord[25];
		int m_nNum;
		double m_dNum;
	};
	Data_Type m_dtype;
};

int main()
{
	Data dt;
	int nWhat = 0;
	cout << "Write " << T_INT << " to work with integer\n"
		<< T_DOUBLE << " to work with double\n"
		<< T_CARD << " to work with word\n";
	cin >> nWhat;
	switch (nWhat)
	{
	case T_INT:
		cin >> dt.m_nNum;
		dt.m_dtype = T_INT;
		break;
	case T_DOUBLE:
		cin >> dt.m_dNum;
		dt.m_dtype = T_DOUBLE;
		break;
	case T_CARD:
		cin >> dt.m_cWord;
		dt.m_dtype = T_CARD;
		break;
	default: cout << "Wrong operation!" << endl;
	}

	switch (dt.m_dtype)
	{
	case T_INT: cout << dt.m_nNum << endl;
		break;
	case T_DOUBLE: cout << dt.m_dNum << endl;
		break;
	case T_CARD: cout << dt.m_cWord << endl;
		break;
	}
	return 0;
}
*/


#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;
enum Err_Code{CALC_OK,WRONG_SIGN,DIVIDE_ZERO};
Err_Code Calculation(double d1, double d2, char cSign, double * pRes);


int main()
{
	double d1(10),d2(0),dRes(0);
	char cSign='+';
	Err_Code err = Calculation (d1, d2, cSign, &dRes);
	switch (err)
	{
	case CALC_OK:
		cout << d1 << cSign << d2 << "=" << dRes << endl;
		break;
	case WRONG_SIGN:
		cout << "Wrong operator!: " << cSign << endl;
		break;
	case DIVIDE_ZERO:
		cout << "Dividing at zero!: " << d1 << cSign << d2 << "=?" << endl;
		break;
	}
}

Err_Code Calculation(double d1, double d2, char cSign, double * pRes)
{
	Err_Code err = CALC_OK;
	switch (cSign)
	{
	case '+':
		*pRes = d1 + d2;
		break;
	case '/':
		if (0 == d2)
			err = DIVIDE_ZERO;
		else *pRes = d1 / d2;
		break;
	default:
		err = WRONG_SIGN;
		break;
	}
	return err;
}