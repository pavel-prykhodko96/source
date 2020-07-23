
#include "pch.h"
#include <iostream>
#include <chrono>
#include <vector>
#include "List.h"

using namespace std;

void connect(List& dest, const List& source)
{
	List::iterator it = source.begin(), itEnd = source.end();
	for (; it != itEnd; ++it)
		dest.push_back(*it);
	return;
}

int main()
{
	List Lis;
	Lis.push_back(115);
	Lis.push_back(15);
	Lis.push_back(9);
	Lis.push_back(6);
	Lis.push_back(3);
	Lis.push_back(42);
	Lis.push_back(11);
	Lis.push_back(6);
	Lis.push_back(8);
	Lis.push_back(17);
	Lis.push_back(1);
	Lis.show();
	Lis.bubblesort();
	Lis.show();

	List abc;
	connect(abc, Lis);
	connect(abc, Lis);
	connect(abc, Lis);
	connect(abc, abc);

	abc.bubblesort();
	abc.show();
	
	return 0;
}
