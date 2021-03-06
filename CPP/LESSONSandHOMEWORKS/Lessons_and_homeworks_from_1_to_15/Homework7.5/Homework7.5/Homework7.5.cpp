

#include "pch.h"
#include <iostream>
using namespace std;

// strlen - output lenght of the string
// strcmp - compare two strings
// strcpy - copy string from source to destination
// atoi - reading numbers in the string and creating int value
// isdigit 
// strcat - string1 = string1+string2

void clear_string (char c_str[])
{
	for (int i = 0; i < strlen(c_str); ++i)
		c_str[i] = ' ';
}

int main()
{
	char c_string[] = "  531abch214afg852fgg1a25a55sdfg90ti-or=g0e-908uursehr7gf87h7",
		c_number[10] = {'0'};
	clear_string(c_number);
	int n_current_position = 0;
	int n_values[25] = { 0 };
	int n_values_sc=0;
	for (int i = 0; i < strlen(c_string); ++i)
	{
		if (!isdigit(c_string[i]))
		{
			if (c_number[0]!=' '||'\0')
			{
				n_values[n_values_sc++] = atoi(c_number);
				clear_string(c_number);
			}
			n_current_position = 0;
			c_string[i] = ' ';
		}
		else
		{
			c_number[n_current_position++] = c_string[i];
			c_string[i] = ' ';
			if (i == strlen(c_string) - 1)
				n_values[n_values_sc] = atoi(c_number);
		}
	}
}

/*//second task

int main()
{
	char c_first_word[100]="\0", c_second_word[100]="\0", c_sentence[100]="\0";
	cin >> c_first_word >> c_second_word;
	if (strlen(c_first_word) <= strlen(c_second_word))
	{
		strcat_s(c_sentence, c_first_word);
		strcat_s(c_sentence, " ");
		strcat_s(c_sentence, c_second_word);
	}
	else 
	{
		strcat_s(c_sentence, c_second_word);
		strcat_s(c_sentence, " ");
		strcat_s(c_sentence, c_first_word);
	}

}
*/
/*//first task
	
int main()
{
	char fir_word[10], sec_word[10];
	char c;
	cin >> fir_word;
	cin >> sec_word;
	if(strcmp(fir_word,sec_word)<=0)
		cout << fir_word << " " << sec_word;
	else cout << sec_word << " " << fir_word;
	return 0;
}
*/