
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
	vector <int> vValues;
	for (int i = 0; i < 15; ++i)
		vValues.push_back(rand() % 21);
	
	/*for (auto itb = vValues.begin(), it = vValues.end();itb != it; ++itb)
		cout << *itb << " "; // Разименование для вывода что в ячейке
	cout << endl;

	int nCountEvenElements = std::count_if(vValues.begin(), vValues.end(),
		[](int el) {return el % 2 == 0; }); // Predicate func
	cout << nCountEvenElements << endl;
	*/
	int a = 8;
	auto Lamb = [&a](int el)
	{
		cout << "a= " << a << endl;
		return el == a;
	};
	int nCountSMTH = count_if(vValues.begin(), vValues.end(), Lamb);
	{
		int a = 28;
		count_if(vValues.begin(), vValues.end(), Lamb);
	}

	/*vValues.erase(remove_if(vValues.begin(), vValues.end(),
		[](int el) {return el % 2 != 0; }), vValues.end());

	for (auto itb = vValues.begin(), it = vValues.end(); itb != it; ++itb)
		cout << *itb << " "; // Разименование для вывода что в ячейке
	cout << endl;*/

	return 0;
}

