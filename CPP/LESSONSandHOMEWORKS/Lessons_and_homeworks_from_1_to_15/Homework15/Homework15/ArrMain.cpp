
#include "pch.h"
#include "Array.h"

using namespace std;

int main()
{
	const Array caArr(5);
	const int cnVal(5);
	Array aArr(10);
	int nVal(10);
	aArr = cnVal + caArr + nVal + cnVal;
}




