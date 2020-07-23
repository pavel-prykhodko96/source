
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char cStr[256];
	int ind_low[256];
	int ind_high[256];
	for (int i = 0; i < 256; ++i)
	{
		ind_low[i] = -1;
		ind_high[i] = -1;
	}
	cout << "Enter the sentence: \n";
	cin.getline(cStr, 256); //where to write and how many symbols 
	int nCharName = strlen(cStr); //marking a lenghts of symbols in the string
	int nCountOfSym(0), index_scorel(0), index_scoreh(0), lowest(100000000000), highest(-1);
	for (int i = 0; i < nCharName; ++i)
	{
		if (cStr[i] != ' ')  ++nCountOfSym;
		if (cStr[i] == ' ' || (i == nCharName - 1 && cStr[i] != ' '))
		{
			if (lowest > nCountOfSym && nCountOfSym > 0)
			{
				lowest = nCountOfSym;
			}
			if (highest < nCountOfSym)
			{
				highest = nCountOfSym;
			}
			nCountOfSym = 0;
		}
	}
	for (int i = 0; i < nCharName; ++i)
	{
		if (cStr[i] != ' ')  ++nCountOfSym;
		if (cStr[i] == ' ' || (i == nCharName - 1 && cStr[i] != ' '))
		{
			if (lowest == nCountOfSym)
			{
				ind_low[index_scorel++] = i - lowest;
				if (i == nCharName - 1 && cStr[i] != ' ') ++ind_low[index_scorel - 1];
			}
			if (highest == nCountOfSym)
			{
				ind_high[index_scoreh++] = i - highest;
				if (i == nCharName - 1 && cStr[i] != ' ') ++ind_high[index_scoreh - 1];
			}
			nCountOfSym = 0;
		}
	}
	for (int i = 0; ind_low[i] >= 0; ++i)
	{
		for (int j = ind_low[i]; j < ind_low[i] + lowest; ++j)
			cout << cStr[j];
		cout << " ";
	}
	cout << endl;
	for (int i = 0; ind_high[i] >= 0; ++i)
	{
		for (int j = ind_high[i]; j < ind_high[i] + highest; ++j)
			cout << cStr[j];
		cout << " ";
	}
	cout << endl;
	return 0;
}

	/*for (int i = index_low; i < index_low + lowest; ++i)
		cout << cStr[i];
	cout << endl;
	for (int i = index_high; i < index_high + highest; ++i)
		cout << cStr[i];
	cout << endl;
	return 0;
	*/

/*if (cStr[i] != ' '&& i<nCharName-1)
			++nCounter;
		else
		{
			if (cStr[i] != ' ') ++nCounter;
			if (lowest > nCounter)
			{
				lowest = nCounter;
				index = i - lowest;
			}
			nCounter = 0;
		}
*/

	/*
	for (int i = strlen(cStr); i >= 0; --i) //deleting symbols from ending to beginning of cStr and output that each time
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
	