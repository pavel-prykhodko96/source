#include "pch.h"
#include <iostream>
#include <chrono>
#include <vector>
#include "List.hpp"

using namespace std;

ostream & operator << (ostream &os, string str)
{
	for (int i = 0; i < str.size(); ++i)
		os << str[i];
	return os;
}
int main()
{
	List <string> L;
	for (int i = 0; i < 5; ++i)
		L.push_back("ROSE");

	for (int i = 0; i < 5; ++i)
		L.push_back("QUANTUM");

	for (int i = 0; i < 5; ++i)
		L.push_back("MIRACLE");

	L.delete_val("a");
	List<string>::iterator it, itEnd;
	for (it = L.find("ROSE"), itEnd = L.end(); it != itEnd; ++it)
		cout << *it << "  ";
	cout << endl;
	return 0;
}
