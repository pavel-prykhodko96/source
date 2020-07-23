
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	FILE *pFile = NULL;
	fopen_s(&pFile, "123.txt", "rb+");
	fseek(pFile, 0, SEEK_END);
	long lFSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	char *buff = new char[lFSize];
	char XOR = 250;
	fread_s(buff, lFSize, sizeof(char), lFSize, pFile);
	fseek(pFile, 0L, SEEK_SET);
	for (int i = 0; i < lFSize; ++i)
	{
		buff[i] ^= XOR;
	}
	fwrite(buff, sizeof(char), lFSize, pFile);
}