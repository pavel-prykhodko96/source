
#include "pch.h"

const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char let = 'L';
const char sqr = 'S'; //SQRT FUNCTION
const char pw = 'P'; //POW FUNCTION
const char declkey = '#';
const char FROM = 'F';
const char TO = 'T';
const char CLOSE = 'C';
const string prompt = "> ";
const string result = "= "; //We understand that we see result after this
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string exitkey = "exit";
const string from = "from";
const string to = "to";
const string close = "close";

class Token
{
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind{ ch } {};
	Token(char ch, double val) :kind{ ch }, value{ val }{};
	Token(char ch, string n) :kind{ ch }, name{ n }{};
};
class Token_stream //Stream to getting symbols
{
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void putback(Token t);
	void ignore(char c);
	void open_file_read_from(string file_name);
	void open_file_write_to(string file_name);
	bool is_file_wr = 0;
	ofstream ost;
	bool is_file_read = 0;
	ifstream ist;
private:
	bool full{ false };
	Token buffer;
};
void Token_stream::open_file_read_from(string file_name)
{
	if (is_file_read == true)
	{
		error( "File is already opened!\n"); 
		return;
	}
	ist.open(file_name);
	if (!ist) error("file not opened!");
	is_file_read = true;
}
void Token_stream::open_file_write_to(string file_name)
{
	if (is_file_wr == true)
	{
		error("File is already opened!\n");
		return;
	}
	ost.open(file_name);
	if (!ost) error("file not opened!");
	is_file_wr = true;
}
void Token_stream::putback(Token t) //Function to write save symbol in the buffer
{
	buffer = t;
	full = true;
}
Token Token_stream::get() //Reading the symbols from the stream and 
{                         //decide to calculate or crating the variable
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	if (is_file_read)
	{
		ist >> ch;
		if (ist.eof())
		{
			is_file_read = false;
			ist.close();
			cin >> ch;
		}
	}
	else cin >> ch;
	switch (ch)
	{
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
		return Token{ch}; // Return operation
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		double val;
		if (is_file_read)
		{
			ist.putback(ch);
			ist >> val;
		}
		else
		{
			cin.putback(ch);
			cin >> val;
		}
		return Token{number, val}; // Return value
	}
	case declkey: 
		return Token{ let }; //Starting initialization of variable
	default:
		if (isalpha(ch) || ch == '_') // Reading names of functions, operations, names of variables
		{
			string s;
			s += ch;
			if (is_file_read)
			{
				while (ist.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'|| ch == '.')) s += ch;
				ist.putback(ch);
			}
			else
			{
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_' || ch == '.')) s += ch;
				cin.putback(ch);
			}
			if (s == from) 
				return Token{ FROM };
			if (s == to) 
				return Token{ TO };
			if (s == close)
				return Token{ CLOSE };
			if (s == sqrtkey) // run sqrt func
				return Token{ sqr };
			if (s == powkey) // run pow func
				return Token{ pw };
			if (s == exitkey) // run pow func
				return Token{ quit };
			return Token(name, s); // else getting the name and value to the variable
		}
		error("Incorrect token");
	}
}
void Token_stream::ignore(char c) //Skip all symbols until 'print' or another 'c'
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;
	char ch = 0; 
	if (is_file_read)
	{
		while (ist >> ch)
		{
			if (ch == c) return;
		}
	}
	else
	while (cin >> ch)
		if (ch == c) return;
}
class Variable
{
public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

Token_stream ts; //Variable to work with symbols and call .get .putback .ignore
vector <Variable> var_table;
double statement();
double expression();

double get_value(string s) //Find needed value of variable in the var_table
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undifined identifier ", s);
}
void set_value(string s, double d) //Reinitialization of variable, 
{                                  //not used in the code yet
	for (Variable& v : var_table)
	{
		if (v.name == s)
		{
			v.value = d;
			return;
		}
	}
	error("set: undifined identifier ", s);
}
bool is_declared(string var) //Checking is the name initialized it is not
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}
double define_name(string var, double val) //Write the variable
{
	if (is_declared(var)) error(var, " repeated declaration");
	var_table.push_back(Variable(var,val));
	return val;
}
double declaration() //Checking the right of the decleration of variable
{                    //according to sample: "let abc = 5-(31*9)/9;"
	Token t = ts.get();
	if (t.kind != name)
		error(" no name of variable");
	string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=')
		error ("'=' missing in declaration of ",var_name);
	double d = expression();
	define_name(var_name, d); //If it accords, creating new variable in the var_table
	return d;
}
void clean_up_mess() //Do not to close the window if error and continue after print;
{
	ts.ignore(print);
}
void calculate() //Starting the prompt and finding the end
{                //of desired action to complete
	while (cin)
	try
	{
		if (!ts.is_file_read) cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); //Output the determination same times like
		if (t.kind == quit) return;           //quit the programm
		if (t.kind == TO)
		{
			Token t = ts.get();
			if (t.kind != name)
				error("no name of file");
			string fil_nam = t.name;
			ts.open_file_write_to(fil_nam);
			continue;
		}
		if (t.kind == FROM)
		{
			Token t = ts.get();
			if (t.kind != name)
				error("no name of file");
			string fil_nam = t.name;
			ts.open_file_read_from(fil_nam);
			continue;
		}
		if (t.kind == CLOSE)
		{
			if (ts.is_file_wr)
			{
				ts.ost.close();
				ts.is_file_wr = false;
			}
			else error("file to write hasn't been opened yet!");
			continue;
		}
		ts.putback(t);
		if (ts.is_file_wr) ts.ost << result << statement() << endl;
		else cout << result << statement() << endl; 
	}
	catch (exception& e)
	{
		if (ts.is_file_wr) ts.ost << e.what() << '\n';
		else cerr << e.what() << '\n';
		clean_up_mess();
	}
	catch (...)
	{
		if (ts.is_file_wr) ts.ost << "exception!\n";
		else cerr << "exception!\n";
		keep_window_open("~~");
	}
}
double primary() //returns values and names of variables
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
	case sqr:
	{
		double d = expression();
		if (d < 0) error("Value can't be lower then 0 for sqrt func!");
		return sqrt(d);
	}
	case pw:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' is missed!");
		double x = expression();
		t = ts.get();
		if (t.kind != ',') error("',' is missed!");
		int i = narrow_cast<int>(expression()); //Cheking is the value integer or not
		t = ts.get();
		if (t.kind != ')') error("')' is missed!");
		return pow(x, i);
	}
	case number:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
	case name: 
		return get_value(t.name);
	default:
		error("primary is missed");
	}
}
double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		double d(0);
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			d = primary();
			if (d == 0)
			{
				error("Dividing on zero");
			}
			left /= d;
			t = ts.get();;
			break;
		case '%':
		{
			int i1 = narrow_cast<int>(left); //Checking is the value integer or not
			int i2 = narrow_cast<int>(primary());
		    if (i2 == 0) error("%: division at zero");
		    left = i1%i2; 
		    t = ts.get();         
		    break;
		}
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
double statement() //Just decide to write the variable
{                  //Or to start the calculate process
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}
int main()
{
	define_name("k", 1000);
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	calculate();
	keep_window_open();
	return 0;
}

