
#include "pch.h"
#include <Windows.h>

int main()
{
	WIN32_FIND_DATA fd;

	HANDLE pHand = FindFirstFile("C:\\*.*", &fd);
	bool bNext = (INVALID_HANDLE_VALUE != pHand);
	while (bNext)
	if (INVALID_HANDLE_VALUE != pHand)
	{ 
		if (fd.cFileName[0]=='P')
		cout << fd.cFileName << endl;
		bNext = FindNextFile(pHand, &fd);
	}
	return 0;
}