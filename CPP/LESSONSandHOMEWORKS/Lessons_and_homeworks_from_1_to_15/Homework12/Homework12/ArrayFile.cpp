
#include "pch.h"
#include <stdlib.h> 
#include "Array.h"
#include "BackUp.h"

using namespace std;

int main()
{
	Array myArr(3);
	for (int i = 0; i < 20; ++i)
		myArr.push_back(i);
	myArr.show();
	char pFileName[] = "test.txt";
	//BackUp bu;
	//myArr.setBackUp(&bu);
	myArr.setName(pFileName);
	myArr.writeToFile();
	myArr.createArrFromFile();
	myArr.show();
	Array newArr(3);
	newArr.setName(pFileName);
	newArr.createArrFromFile();
	newArr.show();
}