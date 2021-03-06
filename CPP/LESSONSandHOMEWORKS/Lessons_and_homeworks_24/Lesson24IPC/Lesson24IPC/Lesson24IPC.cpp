#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	char cComLine[] ("D:\\Homework4.exe");
	STARTUPINFOA si{ sizeof(STARTUPINFOA) };
	PROCESS_INFORMATION pi;
	HANDLE hRead(NULL), hWrite(NULL);
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = true;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = sizeof(sa);

	
	if (!CreatePipe(&hRead, &hWrite, &sa, 5000))
		cout << "Can't create a pipe\n";
	si.hStdOutput = hWrite;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	if (!CreateProcessA(NULL, cComLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL,
		&si, &pi))
		cout << "Can't start a process\n";
	
	cout << "I'm waiting...\n";

	WaitForSingleObject(pi.hProcess, INFINITE);
	cout << "Another .exe is closed\n";

	CloseHandle(hWrite);
	char buff[500];
	DWORD nReadedBytes = 0;
	if(!ReadFile(hRead,buff,500,&nReadedBytes,0))
		cout << "Can't read data from pipe" << endl;
	else
	{
		buff[nReadedBytes] = 0;
		cout << "Data from pipe: " << buff << endl;
	}
	return 0;
}
