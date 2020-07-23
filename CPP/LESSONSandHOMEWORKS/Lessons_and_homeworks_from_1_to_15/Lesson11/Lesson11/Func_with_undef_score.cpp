
#include "pch.h"

void FuncSum(int nCount, ...)
{
	cout << &nCount << endl;
	int *pA = &nCount;
	int sum = 0;
	for (int i = 1; i <= nCount; ++i)
	{
		sum += *(pA + i);
		cout << *(pA + i) << " ";
	}
	sum /= nCount;
	cout << "Average value is: " << sum << endl;
}


int main()
{
	FuncSum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	return 0;
}