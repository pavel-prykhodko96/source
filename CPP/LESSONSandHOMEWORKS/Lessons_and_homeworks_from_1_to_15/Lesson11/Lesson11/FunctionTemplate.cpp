
#include "pch.h"

template <typename T>
void initArray (T *iArr, int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = rand() % 20;
	}
}
void initArray(double *iArr, int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = rand() % 2000000 * 0.001;
	}
}
template <typename T2>
void showArray(T2 *iArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}

const int SIZE = 20;

int main()
{
	double iArr[20];
	initArray(iArr, SIZE);
	showArray(iArr, SIZE);
}