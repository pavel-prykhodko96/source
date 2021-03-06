// Stroustrup_section5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "../../std_lib_facilities.h"

void error(string s1, string s2)
{
	throw runtime_error(s1 + s2);
}
int main()
{
	try
	{
		for (int i = 0; i < 15; ++i)
		{
			cout << i << endl;
			if (i == 5) error("Hi, Jack");
		}
		return 0;
	}
	catch (runtime_error& e)
	{
		cerr << e.what() << endl;
		keep_window_open();
		return 1;
	}
}
