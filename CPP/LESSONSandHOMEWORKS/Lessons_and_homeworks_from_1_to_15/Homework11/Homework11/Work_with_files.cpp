
#include "pch.h"
#include <Windows.h>
#include <iostream>
using namespace std;

char SEPARATOR = '\\';
int SEPARSIZE = 1;

void to_next_folder(char *cStr, char *cFolderName, char* cEnd)
{
	int nOriginSize = strlen(cStr);
	int nFolderSize = strlen(cFolderName);
	int nEndSize = strlen(cEnd);
	bool bIfNoSep = false;
	char * cFull;
	char * cFullWithEnd;

	cFull = new char[nOriginSize + nFolderSize + SEPARSIZE + 1];
	strcpy_s(cFull, nOriginSize + 1, cStr);
	if (cFull[nOriginSize - 1] != SEPARATOR)
	{
		bIfNoSep = true;
		cFull[nOriginSize] = SEPARATOR;
	}
	strcpy_s(cFull + nOriginSize + bIfNoSep, nFolderSize + 1, cFolderName);
	
	bIfNoSep = false;
	int nFullLenght = strlen(cFull);
	cFullWithEnd = new char[nFullLenght + nEndSize + SEPARSIZE + 1];
	strcpy_s(cFullWithEnd, nFullLenght + 1, cFull);
	if (cFullWithEnd[nFullLenght - 1] != SEPARATOR)
	{
		bIfNoSep = true;
		cFullWithEnd[nFullLenght] = SEPARATOR;
	}
	strcpy_s(cFullWithEnd + nFullLenght + bIfNoSep, nEndSize + 1, cEnd);

	WIN32_FIND_DATA fd;  //For writing data about file
	HANDLE pHand = FindFirstFile(cFullWithEnd, &fd); //To work with numbers of files in the system 
	bool bNext = (INVALID_HANDLE_VALUE != pHand);
	while (bNext)
	{
		//if (fd.cFileName[0] == 'A')
			cout << fd.cFileName << endl;
		if (fd.cFileName[0]!='.')
		    to_next_folder(cFull, fd.cFileName, cEnd);
		bNext = FindNextFile(pHand, &fd);
	}
}

int main()
{
	char cStr[] = "C:";
	char cFoldName[] = "";
	char cEnd[] = "**";
	char cWhatToPrint;
	to_next_folder(cStr, cFoldName, cEnd);
	WIN32_FIND_DATA fd;
	char cStr[] = "C:\\";
	
	HANDLE pHand = FindFirstFile(cStr, &fd);
	bool bNext = (INVALID_HANDLE_VALUE != pHand);
	while (bNext)
		if (INVALID_HANDLE_VALUE != pHand)
		{
			//if (fd.cFileName[0] == 'P')
				cout << fd.cFileName << endl;
				to_next_folder(cStr, NULL, );
			bNext = FindNextFile(pHand, &fd);
		}
	return 0;
}