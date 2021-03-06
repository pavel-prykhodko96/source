
#include "pch.h"
#include "../../std_lib_facilities.h"

//TASK: LAST

long  factorial(int nPrimordialVal);
long  permutation(int nAllVal, int nCurrentVal);
long  combination(int nAllVal, int nCurrentVal);

int main()
{
	int a(0), b(0);
	string doing("");
	cout << "Programm can solve the equations: permutation(a,b) = a!/(a-b)!"
		<< endl << "and combination(a,b) = permutation(a,b)/b!" << endl
		<< "write a number, b number and what to do: permitation (perm) or combination (comb)"
		<< endl << "If you put wrong data you will obtain error!" << endl
		<< ": ";
	cin >> a >> b >> doing;
	if (a < b) error("'a' must be bigeer then 'b'");
	if (a <= 0||b<=0) error("Factorial doesn't work with negative values or zero!");
	if (doing == "perm") cout << "The result is: " << permutation(a, b) << endl;
	else if (doing == "comb") cout << "The result is: " << combination(a, b) << endl;
	else error("Wrong condition");
}

long  factorial(int nPrimordialVal)
{
	long double result = 1;
	for (int i = 1; i <= nPrimordialVal; ++i)
	{
		result *= i;
	}
	return result;
}
long  permutation(int nAllVal, int nCurrentVal)
{
	long  result(1);
	for (int i = nAllVal; i > nCurrentVal; --i)
	{
		result *= i;
	}
	if (result <= 0) error("Out of range!");
	return result;
}
long  combination(int nAllVal, int nCurrentVal)
{
	long  result = permutation(nAllVal, nCurrentVal) / factorial(nCurrentVal);
	if (result <= 0) error("Out of range!");
	return result;
}



//TASK input numbers and create value
/*
int main()
{
	vector <char> symbols(4);
	char cInput(0);
	int nCounterOfNumbers(0);
	int nExponent(0);
	int nValue = 0;
	cout << "Input the number from 0 to 9999, put the point '.' to the ending of input: ";
	for (int i = 0; i <= 3; ++i)
	{
		cin >> cInput;
		if (cInput >= 48 && cInput <= 57)
		{
			symbols[i] = cInput;
			++nCounterOfNumbers;
		}
		else if (cInput == '.')
			break;
		else
		{
			cout << "Incorrect symbol!" << endl;
			return 1;
		}
	}
	switch (nCounterOfNumbers)
	{
	case 4:
		cout << symbols[nExponent] << " thousands ";
		nValue += (symbols[nExponent++] - '0') * 1000;
	case 3:
		cout << symbols[nExponent] << " hundreds ";
		nValue += (symbols[nExponent++] - '0') * 100;
	case 2:
		cout << symbols[nExponent] << " decades ";
		nValue += (symbols[nExponent++] - '0') * 10;
	case 1:
		cout << symbols[nExponent] << " unities." << endl;
		nValue += (symbols[nExponent] - '0');
		break;
	default: 
		cout << "There is no numbers" << endl;
	}
	cout << "Your number is: " << nValue << endl;
	return 0;
}
*/
//TASK: Bull and Cows
/*
const int amount_of_letters = 26;
const char first_letter = 'A';
int main()
{
	vector <char> condition = { 0,0,0,0 };
	vector <char> input(4);
	bool ask(1);
	int bull(0), cow(0);
	srand(time(0));
	while (ask)
	{
		for (int i = 0; i < condition.size(); ++i)
		{
			for (int j = i + 1; j < condition.size(); ++j)
			{
				if (condition[i]==0 ||condition[i] == condition[j])
				{
					condition[i] = rand() % amount_of_letters + first_letter;
					condition[j] = rand() % amount_of_letters + first_letter;
					i = -1;
					break;
				}
			}
		}
		int finish = 0;
		cout << "Please enter the 4 hedder letters: ";
		while (!finish)
		{
			for (int i = 0; i < input.size(); ++i)
				cin >> input[i];
			for (int i = 0; i < condition.size(); ++i)
			{
				if (condition[i] == input[i])
					++bull;
				for (int j = 0; j < input.size(); ++j)
				{
					if (condition[i] != input[i] && condition[i] == input[j])
						++cow;
				}
			}
			if (bull != 4)
			{
				cout << "There are " << bull << " bulls and " << cow << " cows!" << endl;
				bull = 0;
				cow = 0;
			}
			else 
			{
				cout << "You win!" << endl;
				finish = true;
				cout << "Do you wish play once more?: 1(yes) or 0(no): ";
				cin >> ask;
			}
		}
	}
	return 0;
}
*/
//TASK: English grammar
/*
class word_type
{
public:
	string word;
	char type;
};
word_type get_word()
{
	string word;
	char type;
	word_type together;
	cin >> word;
	if (word == "and" || word == "or" || word == "but")
	{
		type = 'u';
	}
	else if (word == "birds" || word == "fish" || word == "C++")
	{
		type = 'n';
	}
	else if (word == "rules" || word == "fly" || word == "swim")
	{
		type = 'v';
	}
	else if (word == ".")
	{
		type = '.';
	}
	else
	{
		error("Incorrect word!");
	}
	together.type = type;
	together.word = word;
	return together;
}
int first();
int second();
int third();

int main()
{
	int result = first();
	if (result == 1)
	cout << "That's correct!" << endl;
	else cout << "That's incorrect!";
}
int third()
{
	int result(0);
	word_type third = get_word();
	if (third.type == 'u')
	{
		result = first();
	}
	else if (third.type == '.')
	{
		result = 1;
	}
	else
	{
		error("Point is missed!");
	}
	return result;
}
int second()
{
	int result = 0;
	word_type second = get_word();
	if (second.type != 'v')
	{
		error("Verb is missed!");
	}
	else
	{
		result = third();
	}
	return result;
}
int first()
{
	int result(0);
	word_type first = get_word();
	if (first.type != 'n')
	{
		error("Missed noun!");
	}
	else
	{
		result = second();
	}
	return result;
}
*/
//TASK: input Names Scores and create 2 vectors: 1 for the names, 2 for the scores 
//with compatibility: Name [i] Score [i], stop with noname 0 and output all of them
//with 1 class
/*
class name_value
{
public:
	string name;
	int value;
};

int main()
{
	vector <name_value> nam_val;
	name_value input;
	cout << "Please, enter the names and scores, for example: Sasha 17 Paul 2" << endl
		<< "Finish with noname 0:" << endl;
	while(true)
	{
		cin >> input.name >> input.value;
		if (input.name == "noname"&&input.value == 0) break;
		nam_val.push_back(input);
	}
	for (int i = 0; i < nam_val.size(); ++i)
	{
		cout << nam_val[i].name << " " << nam_val[i].value << endl;
	}
}
*/
//Calculator
/*

class Token
{
public:
	char kind;
	double value;
};
class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

void Token_stream::putback(Token t)
{
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case ';': case 'q':
	case '(': case ')': case '{': case '}': case '+':
	case '-': case '*': case '/': case '!':
		return Token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		error("Incorrect token");
	}
}

Token_stream ts;
double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
		{
			error("')' is missed!");
		}
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
		{
			error("'}' is missed!");
		}
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary is missed");
	}
}
double factorial() 
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '!':
			left = (int)left;
			if (left == 0)
			{
				left = 1;
			}
			else
			{
				for (int i = left - 1; i > 0; --i)
				{
					left *= i;
				}
			}
			t = ts.get();
			if (t.kind == '8')
			{
				error("Operator missed!");
			}
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}
double term()
{
	double left = factorial();
	Token t = ts.get();
	while (true)
	{
		double d(0);
		switch (t.kind)
		{
		case '*':
			left *= factorial();
			t = ts.get();
			break;
		case '/':
			d = factorial();
			if (d == 0)
			{
				error("Dividing on zero");
			}
			left /= d;
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}
double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int main()
try
{
	double val(0);
	while (cin)
	{
		Token t = ts.get();
		if (t.kind == 'q') break;
		if (t.kind == ';')
			cout << "=" << val << endl;
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open();
}
catch (exception& e)
{
	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...)
{
	cerr << "exception!\n";
	keep_window_open();
	return 2;
}
*/