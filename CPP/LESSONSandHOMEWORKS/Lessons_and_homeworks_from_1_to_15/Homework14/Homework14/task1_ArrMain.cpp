
#include "pch.h"
#include <stdlib.h>
#include "task1_Array.h"
#include "task1_BackUp.h"

using namespace std;

int main()
{
	Array ar1(10);
	for (int i = 0; i < 20; ++i)
		ar1.push_back(10000+i);
	cout << ar1[25] << endl;
	return 0;
}




