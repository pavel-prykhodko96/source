

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char cStr[256];
	cout << "Enter the sentence: \n";
	cin.getline(cStr, 256);
	int nCharName = strlen(cStr);
	int nCounter(0), lowest(256);
	int index = 0;
	for (int i = 0; i < nCharName; ++i)
	{
		if (cStr[i] == ' ') 
		{
			lowest = nCounter;
			index = i - lowest;
			nCounter = 0;
		}
		++nCounter;
	}
	for (int i = index; i < index+lowest; ++i)
		cout << cStr[i];
	cout << endl;
	


    /*	
    for (int i = strlen(cStr); i >= 0; --i) //deleteng symbols from ending to beginning of cStr and out that each time
	{
		cStr[i] = 0;
		cout << cStr << endl;
	}
	*/
	/*for (int i = 0; i < nCharName; ++i)
	{
		if (cStr[i] != 1)
		{
			cCurrentLetter = cStr[i];
		}
		else continue;
		cCurrentLetter = cStr[i];
		for (int i = 0;i<nCharName;++i)
		{
			if (cStr[i] == cCurrentLetter)
			{
				cStr[i] = 1;
				++nCounter;
			}
		}
		cout << cCurrentLetter << ": " << nCounter << endl;
		nCounter = 0;
	}*/
	/*for (int i = 0; i < nCharName; ++i)
	{
		if (cStr[i] != 1)
		{
			++nArr[cStr[i]];
		}
	}
	for (int i = 0; i < 256; ++i)
	{
		if (nArr[i] > 0) cout << char(i) << " " << nArr[i] << endl;
	}*/
	return 0;
}