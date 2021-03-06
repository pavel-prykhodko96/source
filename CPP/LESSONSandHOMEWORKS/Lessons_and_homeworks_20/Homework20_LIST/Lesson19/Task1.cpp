
#include "pch.h"
#include <iostream>
#include <chrono>
#include <vector>
#include "List.h"

using namespace std;

int main()
{
	List newList;
	int nVal = 0;
	while (cin >> nVal)
	{
		if (nVal < 10)
			newList.push_back(nVal);
		else break;
	}
	List::iterator it, itEnd;
	int nRemainder = 0;
	for (it = newList.begin(), itEnd = newList.end();it != itEnd;++it)
	{
		cin >> nVal;
		nVal += nRemainder;
		nRemainder = 0;
		it.set_val(nVal+*it);
		if (*it > 9)
		{
			it.set_val(*it % 10);
			nRemainder = 1;
		}
	}
	if (nRemainder == 1)
		newList.push_back(nRemainder);
	newList.show();
	return 0;
}
