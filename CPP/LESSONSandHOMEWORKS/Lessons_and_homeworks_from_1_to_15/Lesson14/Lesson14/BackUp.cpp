#include "pch.h"
#include "BackUp.h"

error_enum BackUp::save(char *pFileName, int *data, int size)
{
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, pFileName, "wb");
	if (pFile != nullptr) //if opening is complete
	{
		arr_size = size;
		for (int i = 0; i < size; ++i)
			fwrite(data+i, sizeof(int), 1, pFile);
		fclose(pFile);
	}
	return error_enum::ok;
}
error_enum BackUp::read(char *pFileName, int* pBuff)
{
	FILE * pFile = nullptr;
	errno_t err = fopen_s(&pFile, pFileName, "rb");
	if (pFile != nullptr) //if opening is complete
	{
		for (int i = 0; i < arr_size; ++i)
			fread_s(pBuff + i, arr_size * sizeof(int), sizeof(int), 1, pFile);
		fclose(pFile);
	}
	return error_enum::ok;
}
