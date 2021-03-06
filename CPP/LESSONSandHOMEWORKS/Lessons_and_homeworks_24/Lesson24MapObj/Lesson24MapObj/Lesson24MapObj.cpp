#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

DWORD WINAPI FirstProgrammThread(void *pData);
DWORD WINAPI SecondProgrammThread(void *pData);

int main()
{
	HANDLE hMutFoSecondVer = nullptr, hThread = nullptr;
	HANDLE hMutFirVer = CreateMutexA(NULL, FALSE, "MutexForFirstAppRealization");
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		HANDLE hMutSecVer = CreateMutexA(NULL, FALSE, "MutexForSecondAppRealization");
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			cout << "Can't create third copy of application!" << endl;
			return 0;
		}
		else
		{
			cout << "SecVer is opened\n";
			hThread = CreateThread(NULL, NULL, SecondProgrammThread, NULL, NULL, NULL);
		}
	}
	else
	{
		cout << "FirVer is opened\n";
		hThread = CreateThread(NULL, NULL, FirstProgrammThread, NULL, NULL, NULL);
	}
	WaitForSingleObject(hThread, INFINITE);
	return 0;
}

DWORD WINAPI FirstProgrammThread(void* pData)
{
	std::cout << "I'm a firstProgramThread" << std::endl;
	HANDLE hEvForWriting = CreateEventA(NULL, FALSE, TRUE, "eventForWritingDataToFileMap");
	HANDLE hEvForReading = CreateEventA(NULL, FALSE, FALSE, "eventForReadingDataToFileMap");
	HANDLE hFileMap = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4 * 1024, "FMForProcessCommunication");
	if (NULL == hFileMap)
	{
		std::cout << "Cannot create File Mapping Object!" << std::endl;
		CloseHandle(hEvForWriting);
		CloseHandle(hEvForReading);

		return 0;
	}
	char* pFMData = (char*)MapViewOfFile(hFileMap, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, 0);
	if (nullptr == pFMData)
	{
		std::cout << "Cannot get MapViewOfFile!" << std::endl;
		CloseHandle(hEvForWriting);
		CloseHandle(hEvForReading);
		CloseHandle(hFileMap);
		return 0;
	}
	while (true)
	{
		std::cout << "I am waiting for event to write" << std::endl;
		WaitForSingleObject(hEvForWriting, INFINITE);
		char buff[20];
		cin >> buff;
		strcpy_s(pFMData, strlen(buff) + 1, buff);
		SetEvent(hEvForReading);
		cout << "data was wrote to file map obj" << endl;
		if (strcmp("quit", pFMData) == 0)
		{
			CloseHandle(hFileMap);
			return 0;
		}

	}
	return 0;
}

DWORD WINAPI SecondProgrammThread(void* pData)
{
	std::cout << "I'm a secondProgramThread" << std::endl;

	HANDLE hFileMap = OpenFileMappingA(FILE_MAP_WRITE | FILE_MAP_READ, FALSE, "FMForProcessCommunication");
	if (NULL == hFileMap)
	{
		std::cout << "cannot open FileMap" << std::endl;
		return 0;
	}
	char* pFMData = (char*)MapViewOfFile(hFileMap, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, 0);
	if (nullptr == pFMData)
	{
		std::cout << "cannot get MapView" << std::endl;
		CloseHandle(hFileMap); //???
		return 0;
	}

	HANDLE hEvForReading = OpenEventA(EVENT_ALL_ACCESS, FALSE, "eventForReadingDataToFileMap");
	HANDLE hEvForWriting = OpenEventA(EVENT_ALL_ACCESS, FALSE, "eventForWritingDataToFileMap");
	if (NULL == hEvForReading)
	{
		std::cout << "cannot get hEvForReading" << std::endl;
		CloseHandle(hFileMap);
		return 0;
	}
	while (true)
	{
		std::cout << "I am waiting for event to read" << std::endl;
		WaitForSingleObject(hEvForReading, INFINITE);
		if (strcmp("quit", pFMData) == 0)
		{
			CloseHandle(hFileMap);
			break;
		}
		std::cout << "data from map: " << pFMData << std::endl;
		SetEvent(hEvForWriting);
	}
	return 0;
}
