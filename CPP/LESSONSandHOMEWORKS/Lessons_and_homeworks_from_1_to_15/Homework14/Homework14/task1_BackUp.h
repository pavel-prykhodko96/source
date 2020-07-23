#pragma once
#include <iostream>
using namespace std;

enum error_enum {ok=0};

class BackUp
{
public:
	int get_size() { return arr_size; }
	error_enum save(char *pFileName, int *data, int size);
	error_enum read(char *pFileName, int* pBuff);
private:
	int arr_size;
};

