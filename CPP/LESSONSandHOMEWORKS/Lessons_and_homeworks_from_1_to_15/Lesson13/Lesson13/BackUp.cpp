#include "pch.h"
#include "BackUp.h"

void BackUp::save(char *pFileName, int *data, int size)
{
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, pFileName, "wb");
	if (pFile != nullptr) //if opening is complete
	{
		fwrite(data, sizeof(int), size, pFile);
		fclose(pFile);
	}
	return; //err
}
int *BackUp::read(char *pFileName, int size)
{
	int *pBuff = new int[size];
	FILE * pFile = nullptr;
	errno_t err = fopen_s(&pFile, pFileName, "rb");
	if (pFile != nullptr) //if opening is complete
	{
		fread_s(pBuff, size*sizeof(int), sizeof(int), size, pFile);
		fclose(pFile);
	}

	return pBuff;
}

BackUp::BackUp()
{
}


BackUp::~BackUp()
{
}
