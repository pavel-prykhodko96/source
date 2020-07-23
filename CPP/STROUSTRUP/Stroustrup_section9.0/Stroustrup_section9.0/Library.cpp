
#include "pch.h"
#include "../../std_lib_facilities.h"

enum class Genre
{fantasy, triller, action, drama, rom_com,
detective, anime, cartoon, scientific,
children_lit, biography};

class Date
{
public:
	Date(int y, int m, int d);
	Date();
	int month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }
private:
	int y;
	int m;
	int d;
};
Date::Date(int y, int m, int d) : y{ y }, m{ m }, d{ d }
{
	if (m <= 12 && m >= 1 && d > 0 && d < 32)
	{
		return;
	}
	else error("Wrong date!");
};
Date::Date()
	: y{2000},m{2},d{2}{}
class Book
{
public:
	Book(string ISBN, string titl, Genre genr, string surnam, Date dat, bool is_issued);
	Book() : I{ "1234" }, t{ "Bleach" }, G{ Genre::anime }, d{ Date() }, is_{ true } {}
	string ISBN() const {return I;}
	string title() const {return t;}
	Genre genre() const {return G;}
	string surname() const {return  s;}
	Date date() const {return d;}
	bool is_issued() const {return is_;}
private:
	Genre G;
	string I;
	string t;
	string s;
	Date d;
	bool is_; //Is issued
};
Book::Book(string ISBN, string titl, Genre genr, string surnam, Date dat, bool is_issue)
	:I{ ISBN }, t{ titl }, G{ genr }, s{ surnam }, d{ dat }, is_{ is_issue }
{
	if (ISBN.size() != 4 || !isdigit(ISBN[0]) || !isdigit(ISBN[1])
		|| !isdigit(ISBN[2]) || (!isalpha(ISBN[3]) && !isdigit(ISBN[3])))
			error("Wrong ISBN code");
}
class Patron
{
public:
	Patron(string u_n, int c_n, double m_f) : u_n{ u_n }, c_n{ c_n }, m_f{ m_f }{}
	Patron() : u_n{ "John" }, c_n{ 1 }, m_f{ 0 }{}
	string user_name() { return u_n; }
	int card_num() { return c_n; }
	double membership_fee() { return m_f; }
	void set_fee(double how_much) { m_f = how_much; }
	bool is_payed();
private:
	string u_n;
	int c_n;
	double m_f = 0;
};
bool Patron::is_payed()
{
	if (m_f != 0) return false;
	else return true;
}

class Transaction
{
public:
	Transaction(Book b,Patron p,Date d):B{b},P{p},D{d}{}
	Book B;
	Patron P;
	Date D;
private:
	
};

class Library
{
public:
	vector <Book> Books;
	vector <Patron> Patrons;
	vector <Transaction> Transactions;
	void add_transaction();
private:
	Book check_book(string book_name);
	Patron check_patron_and_fee(string patron_name);
};
Book Library::check_book(string book_name)
{
	for (Book x : Books)
		if (x.title() == book_name)return x;
	error("There are no book in library with title: ", book_name);
}
Patron Library::check_patron_and_fee(string patron_name)
{
	for (Patron x : Patrons)
		if (x.user_name() == patron_name) 
		if (x.membership_fee()==0) return x;
		else error("The patron has a debt!");
	error("There are no patrons with name: ", patron_name);
}
void Library::add_transaction()
{
	string book_name;
	string patron_name;
	cin >> book_name >> patron_name;
	Book current_book = check_book(book_name);
	Patron current_pat = check_patron_and_fee(patron_name);
	Date today;
	Transaction T(current_book, current_pat, today);
	Transactions.push_back(T);
}

bool operator == (const Book& a, const Book& b)
{
	return a.ISBN() == b.ISBN();
}
bool operator != (const Book& a, const Book& b)
{
	return !(a==b);
}
ostream& operator << (ostream& os, Book& b)
{
	return os << "Title: " << b.title() << endl
		<< "Author's surname: " << b.surname() << endl
		<< "ISBN: " << b.ISBN() << endl;
}

int main()
try{
	Library L;
	Book B{ "1321","BLEACH", Genre::anime,"Kubo",{1999,8,8},1 };
	L.Books.push_back(B);
	Patron P {"Pasha",10,5};
	L.Patrons.push_back(P);
	L.add_transaction();
}
catch (runtime_error& e)
{
	cerr << e.what();
}