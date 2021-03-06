
#include "pch.h"
#include <iostream>

#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>


using namespace std;

int main()
{
	//-----------------------------------------
	// Declare and initialize variables
	WSADATA wsaData = { 0 };
	int iResult = 0;

	// Initialize Winsock - just windows option
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		cout << "WSAStartup failed\n";
		return 0;
	}

	SOCKET soc = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == soc)
	{
		cout << "Socket creation was failed\n";
		WSACleanup();
		return 0;
	}
	sockaddr_in addr = { 0 }; //who programm should connect with
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2222); //PORT 2222
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	int bin = bind(soc, (sockaddr*)&addr, sizeof(sockaddr_in));// connect port to socke
	if (INVALID_SOCKET == bin)
	{
		cout << "bind() was failed\n";
		closesocket(soc);
		WSACleanup();
		return 0;
	}
	int lis = listen(soc, 0);
	if (INVALID_SOCKET == lis)
	{
		cout << "listen() was failed\n";
		closesocket(soc);
		WSACleanup();
		return 0;
	}
	int len = sizeof(sockaddr_in);
	cout << "Waiting for connection\n";
	SOCKET workSoc = accept(soc, (sockaddr*)&addr, &len);
	
	
	
	char buff[] = "Message for client";
	int nDataSize = send(workSoc, buff, strlen(buff), 0);
	cout << "Message was sent\n";

	char buffrec[500];
	int nSize = recv(workSoc, buffrec, 500, 0);
	if (nSize > 0)
	{
		buffrec[nSize] = 0;
		cout << "Data: " << buffrec << endl;
	}

	WSACleanup();
	return 0;
}
