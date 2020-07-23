
#include "pch.h"
#include "../../../std_lib_facilities.h"

vector <string> split(const string& s)
{
	stringstream sstream(s);
	string word;
	vector <string> words;
	while (sstream >> word)
		words.push_back(word);
	return words;
}
vector <string> split(const string& s, const string& w)
{
	stringstream sstream(s);
	string word;
	vector <string> words;
	bool is_spacee = false;
	char symb;
	while (sstream.get(symb))
	{
		for (char space_symb : w)
		{
			if (symb == space_symb)
			{
				if (word.size() > 0) words.push_back(word);
				word = "";
				is_spacee = true;
				break;
			}
		}
		if (!is_spacee) word += symb;
		is_spacee = false;
	}
	return words;
}

int main()
{
	string my_sentence = "Hi   ,  Jack   !  How  are  you ?  ?  Do  you  want  this  kitchen  ?!";
	vector <string> words = split(my_sentence, " ,!.?");
	for (string s : words)
		cout << s << endl;
}