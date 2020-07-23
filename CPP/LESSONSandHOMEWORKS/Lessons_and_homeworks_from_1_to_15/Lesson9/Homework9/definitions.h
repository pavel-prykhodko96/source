//#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;

enum Data_Type { T_INT = 10, T_DOUBLE, T_CARD };
struct Data
{
	union
	{
		char m_cWord[25];
		int m_nNum;
		double m_dNum;
	};
	Data_Type m_dtype;
};
