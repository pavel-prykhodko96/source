
#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

const int ARRSIZE = 20;

void showArray(int *iArr, int nSize);
void initArray(int *iArr, int nSize);
void bubblesort(int *iArr, int nSize);
int binary_search(int* arr, int wished_value, int ind_begin, int ind_end);

int main()
{
	int val(0);
	int arr [ARRSIZE];
	initArray(arr, ARRSIZE);
	bubblesort(arr, ARRSIZE);
	showArray(arr, ARRSIZE);
	cin >> val;
	cout << binary_search(arr, val, 0, ARRSIZE-1);
}
int binary_search(int* arr, int wished_value, int ind_begin, int ind_end)
{
	int current_ind = (ind_end + ind_begin) / 2;
	if (ind_begin == ind_end && arr[current_ind] != wished_value) return -1;
	if (arr[current_ind] == wished_value) return current_ind;
	if (arr[current_ind] < wished_value)
	{
		return binary_search(arr, wished_value, current_ind+1, ind_end);
	}
	else return binary_search(arr, wished_value, ind_begin, current_ind);
}

void initArray(int *iArr, int nSize)
{
	srand(time(0));
	for (int i = 0; i < nSize; ++i)
	{
		iArr[i] = rand() % 1000;
	}
}
void showArray(int *iArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		cout << iArr[i] << " ";
	}
	cout << endl;
}
void bubblesort(int *iArr, int nSize)
{
	int ntemp(0), nCounter(0); 
	for (int i = 0; i < nSize; ++i)
	{
		for (int j = 0; j < nSize - 1 - i; ++j)
		{
			if (iArr[j] > iArr[j + 1])
			{
				ntemp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = ntemp;
			}	
		}	
	}	
}