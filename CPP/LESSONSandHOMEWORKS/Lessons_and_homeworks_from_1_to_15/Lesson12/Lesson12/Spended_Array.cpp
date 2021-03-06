// Lesson12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

int for_q_sort(const void* a, const void * b)
{
	char **cA = (char**)a;
	char **cB = (char**)b;
	return strcmp(*cA, *cB);
}

int main()
{
	int nFileListSize = 3;
	char **pFileNames = new char *[nFileListSize];
	int ind = 0;
	WIN32_FIND_DATAA fd;
	HANDLE handl = FindFirstFileA("C:\\*.*", &fd);
	bool bFileExistance = (INVALID_HANDLE_VALUE != handl);
	while (bFileExistance)
	{
		if (ind == nFileListSize)
		{
			char ** pTemp = new char *[nFileListSize * 2];
			for (int i = 0; i < nFileListSize; ++i)
			{
				pTemp[i] = pFileNames[i];
			}
			delete[]pFileNames;
			pFileNames = pTemp;
			nFileListSize *= 2;
		}
		int nFileSize = strlen(fd.cFileName) + 1;
		pFileNames[ind] = new char[nFileSize];
		strcpy_s(pFileNames[ind], nFileSize, fd.cFileName);
		++ind;
		//cout << fd.cFileName << endl;
		bFileExistance = FindNextFileA(handl, &fd);
	}
	std::qsort(pFileNames, ind, sizeof(char*), for_q_sort);
	for (int i = 0; i < ind; ++i)
	{
		cout << pFileNames[i] << endl;
	}
	return 0;
}