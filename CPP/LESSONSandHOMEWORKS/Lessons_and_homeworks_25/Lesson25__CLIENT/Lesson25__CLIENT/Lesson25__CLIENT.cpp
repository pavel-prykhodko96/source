// Lesson25__CLIENT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	addr.sin_port = htons(2222); //13
	//addr.sin_addr.S_un.S_addr = InetPton("62.149.0.30");
	inet_pton(AF_INET, "192.168.0.203", &addr.sin_addr.S_un.S_addr);
	int con = connect(soc, (sockaddr*)&addr,sizeof(sockaddr_in));
	if (INVALID_SOCKET == con)
	{
		cout << "Connection was failed\n";
		closesocket(soc);
		WSACleanup();
		return 0;
	}

	cout << "Connection was set\n";

	char buffsend[100];
	cin >> buffsend;
	int nDataSize = send(soc, buffsend, strlen(buffsend), 0);
	cout << "Message was sent\n";

	char buff[500];
	int nSize =	recv(soc, buff, 500, 0);
	if (nSize > 0)
	{
		buff[nSize] = 0;
		cout << "Data: " << buff << endl;
	}




	WSACleanup();
	return 0;
}
