#pragma once
#include <iostream>
using namespace std;
class BackUp
{
public:
	BackUp(); 
	~BackUp();
	void save(char *pFileName, int *data, int size);
	int *read(char *pFileName, int size);
};

