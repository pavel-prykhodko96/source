
#include "pch.h"
#include <stdlib.h>
#include "Array.h"

using namespace std;

int main()
{
	Array ar1(10);
	for (int i = 0; i < 10; ++i)
		ar1.push_back(i);
	Array ar2(0);
	ar2 = ar1;
	ar2.show();
	
	Array ar3 = ar1 + ar2;
	ar3.show();
	ar1 = ar3;
	ar3 = ar1 + ar1 + ar1;
	ar3.show();

	cout << ar3 << endl;

	return 0;
}

/*
int main() //old
{
	Array myArr(3);
	for (int i = 0; i < 20; ++i)
		myArr.push_back(i);
	myArr.show();
	char pFileName[] = "test.txt";
	myArr.setName(pFileName);
	myArr.writeToFile();
	myArr.createArrFromFile();
	myArr.show();
	Array newArr(3);
	newArr.setName(pFileName);
	newArr.createArrFromFile();
	newArr.show();
}
*/



