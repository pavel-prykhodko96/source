
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	vector <string> data;
	string line;
	bool is_bracket = false;
	char *ch;
	while (getline(cin, line))
	{
		if (line == "StOp") break;
		for (int i = 0; i<line.size();++i)
		{
			ch = &line[i];
			switch (*ch)
			{
			case '-':
				if (i>0&&i<line.size()-1)
					if (isalpha(line[i-1])
						&&isalpha(line[i+1]))
						break;
			case '.': case ';': case ',':
			case '?': case '`':
				if (!is_bracket) *ch = ' ';
				break;
			case '"':
				if (!is_bracket) is_bracket = true;
				else
					is_bracket = false;
			default:
				if (isalpha(*ch)) *ch = tolower(*ch);
			}
		}
		
		data.push_back(line);
	}
	if (is_bracket)
	{
		cout << "You probably forgot to close the brackets\n";
		return 0;
	}
	vector <string> changed_lines;
	string changed_line;
	for (string s : data)
	{ 
		stringstream data_stream(s);
		for (string word; data_stream >> word;)
		{
			if (word == "don't") word = "do not";
			if (word == "can't") word = "can not";
			changed_line += word += ' ';
		}
		changed_lines.push_back(changed_line);
		changed_line = "";
	}
	for (string s : changed_lines)
		cout << s << endl;
}