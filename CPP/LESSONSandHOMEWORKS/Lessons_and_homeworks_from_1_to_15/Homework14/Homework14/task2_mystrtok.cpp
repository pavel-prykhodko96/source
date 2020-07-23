
#include "pch.h"
#include <iostream>
using namespace std;

char* my_strtok(char* pStr, const char* delim)
{
	static int size = strlen(pStr);
	static int cur_ind = 0;
	static char *cur_letter = pStr;
	int delim_size = strlen(delim);
	for (int i = 0; ; ++i)
	{
		if (cur_ind > size) return NULL;
		++cur_ind;
		for (int j = 0; j < delim_size; ++j)
			if (cur_letter[i] == delim[j])
				cur_letter[i] = '\0';
		if (cur_letter[i] == '\0')
		{
			cur_letter += i + 1;
			return cur_letter - i - 1;
		}
	}
}

int main()
{
	char cStr[] = "Hi my name is PASHA / // / / and I'm  . .  OK";
	char *pWord = my_strtok(cStr, "./ ");
	while (pWord !=NULL)
	{
		cout << pWord << endl;
		pWord = my_strtok(NULL, "./ ");
	}
}
