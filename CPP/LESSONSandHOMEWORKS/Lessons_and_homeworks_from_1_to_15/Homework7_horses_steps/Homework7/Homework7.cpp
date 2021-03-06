
#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int ARRSIZE = 10;
void showArray(int iArray[ARRSIZE][ARRSIZE], int arr_size)
{
	for (int i = 0; i < arr_size; ++i)
	{
		for (int j = 0; j < arr_size; ++j)
		{
			if (j % (arr_size +1) == 0)
			{
				//cout << endl;
			}
			//cout << setw(4) << iArray[i][j];
		}
	}
	//cout << endl;
}
void horse_step(int arr[ARRSIZE][ARRSIZE], int arr_size, int how_much, int& result, int nCounter = 1, int x = 0, int y = 0)
{                      //nCounter == 1 because of existance of Start point arr[0][0] == 1
	++nCounter;        //So first step starts with nCounter == 2
	for (int i = 2, k = 0; k<2; i*=-1,++k)          //Variables i and j are needed to move
	{                                               //by cells of the array
		for (int j = 1, l = 0; l < 4; j *= -1, ++l) //
		{
			if (l > 1) //This is for 2 steps up/down and 1 step left/right by half of times
			{          //And for 2 steps left/right and 1 step up/down by another half of times
				int nTemp = i;
				i = j;
				j = nTemp;
			}
			if (x + i >= 0 && x + i < arr_size && y + j >= 0 && y + j < arr_size && arr[x + i][y + j] == 0)
			{                                      //Checking limits of array and no repeating of the steps
				x += i;
				y += j;                                                                               
				arr[x][y] = nCounter;                                                                 //If the step is correct put to [x][y] 
				if (nCounter < how_much) horse_step(arr, arr_size, how_much, result, nCounter, x, y); //number of step and call next step
				if (nCounter == how_much && x == y && x == arr_size - 1)  //
				{                                                         //if last step situated in current place
					++result;                                             //add score of variants
					showArray(arr, arr_size);                             //
					
				}
				arr[x][y] = 0; //this instructions deletes marker of step
				x -= i;        //and turn to previous positions
				y -= j;        //
			}
			if (l > 1) //return origin values
			{          //to do correct working
				int nTemp = i;
				i = j;
				j = nTemp;
			}
		}
	}
}

int main()
{
	int result(0), how_much(0), arr_size(0);
	cin >> arr_size >> how_much;
	int iArr[ARRSIZE][ARRSIZE] = { 0 };
	iArr[0][0] = 1; //Start point
	horse_step(iArr, arr_size, how_much+1, result); //how_much + 1 because of existence of Start point arr[0][0] == 1
	cout << result;                                 
	return 0;
}