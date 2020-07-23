
#include "pch.h"
#include <iostream>
using namespace std;


void sortwords(char**pWords,int nSize)
{
	char *pTemp;
	for (int i=0;000000.i<nSize;++i)
		for (int j = 0; j < nSize - 1 - i; ++j)
		{
			if (_stricmp(pWords[j], pWords[j + 1]) > 0)
			{
				pTemp = pWords[j];
				pWords[j] = pWords[j + 1];
				pWords[j + 1] = pTemp;
			}
		}
}
int main()
{
	int nSize(3), ind(0);
	char sStr[] = "ABC ZXY FGH";
	char**pWords = new char*[nSize], *pContext = nullptr;
	//char *pWord = strtok(sStr, " ,:;!.&");
	char *pWord = strtok_s(sStr, " ,:;!.?", &pContext);
	while (pWord != nullptr)//!= /0
	{
		pWords[ind] = pWord;
		ind++;
		pWord = strtok_s(NULL, " ,:;!.?", &pContext);
	}
	sortwords(pWords, nSize);
	for (int i = 0; i < nSize; ++i)
	{
		cout << pWords[i] << endl;
	}
}
