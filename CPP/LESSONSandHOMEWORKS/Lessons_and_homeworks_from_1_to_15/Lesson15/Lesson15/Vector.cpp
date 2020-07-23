
#include "pch.h"
#include <vector>
#include <iostream>

using namespace std;
int main()
{
	vector <int> VC; //template class
	for (int i = 0; i < 10; ++i)
	{
		VC.push_back(rand() % 20);
		cout
			<< "SIZE: " << VC.size() << endl
			<< "CAPACITY: " << VC.capacity() << endl;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << VC[i] << " ";
	}
	cout << endl << VC.size() << endl << VC.capacity() << endl; 
	// Iterators
	vector<int>::iterator itb = VC.begin(), // адрес первого элемента контейнера
		                  iten = VC.end();  // адрес первого элемента за 
	                                        // пределом контейнера
	for (itb = VC.begin(); itb != iten; ++itb)
	{
		cout << *itb << " ";
	}
	return 0;
}



