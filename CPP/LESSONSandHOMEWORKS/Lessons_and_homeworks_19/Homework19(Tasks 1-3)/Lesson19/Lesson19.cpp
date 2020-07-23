
#include "pch.h"
#include <iostream>
#include <chrono>
#include <vector>
#include "List.h"

using namespace std;

int main()
{
	List L;
	L.push_back(1);
	L.push_back(6);
	L.push_back(5);
	L.push_back(5);
	L.push_back(1);
	L.push_back(5);

	L.delete_val(5);
	List::iterator it, itEnd;
	for (it = L.begin(), itEnd = L.end(); it != itEnd; ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
