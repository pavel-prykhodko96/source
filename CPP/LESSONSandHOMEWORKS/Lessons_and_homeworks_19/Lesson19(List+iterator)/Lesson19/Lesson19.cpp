#include "pch.h"
#include <iostream>
#include <chrono>
#include <vector>
#include "List.h"
using namespace std;

int main()
{
	{List L;
	for (int i = 0; i < 10; ++i)
		L.push_back(rand()%50);
	cout << L.size() << endl; 
	L.show();
	}if (_CrtDumpMemoryLeaks()) cout << "MEMORY LEAKS!\n";
	return 0;
}
