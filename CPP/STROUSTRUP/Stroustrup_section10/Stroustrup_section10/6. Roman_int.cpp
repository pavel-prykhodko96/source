
#include "pch.h"


	class Roman_int
	{
	public:
		int as_int();
		vector <char> value;
	private:
		const int I = 1;
		const int V = 5;
		const int X = 10;
		const int L = 50;
		const int C = 100;
		const int D = 500;
		const int M = 1000;
	};
	vector <char> symbols{ 'I','V','X','L','C','D','M' };
	//for functions write_to_vec and rom_to_int
	void write_to_vect(vector <char>& vect, int how_many,
		int what)
		//int what according to vector symbols [i]
	{
		if (what == 6)
			for (int i = 0; i < how_many; ++i)
				vect.push_back(symbols[what]);
		else
		{
			if (how_many == 4)
			{
				vect.push_back(symbols[what]);
				vect.push_back(symbols[what + 1]);
			}
			else if (how_many == 9)
			{
				vect.push_back(symbols[what]);
				vect.push_back(symbols[what + 2]);
			}
			else
			{
				if (how_many >= 5) vect.push_back(symbols[what + 1]);
				for (int i = 0; i < how_many % 5; ++i)
				{
					vect.push_back(symbols[what]);
				}
			}
		}
	}
	void int_to_rom(vector <char> &val, int x)
	{
		int sym_thous = 6, sym_hundrs = 4, sym_tens = 2, sym_ones = 0;
		//According to vector symbols!
		int dividing(0), rem_of_the_div(0);
		dividing = x / 1000;
		rem_of_the_div = x % 1000;
		write_to_vect(val, dividing, sym_thous);
		dividing = rem_of_the_div / 100;
		rem_of_the_div = rem_of_the_div % 100;
		write_to_vect(val, dividing, sym_hundrs);
		dividing = rem_of_the_div / 10;
		rem_of_the_div = rem_of_the_div % 10;
		write_to_vect(val, dividing, sym_tens);
		dividing = rem_of_the_div;
		write_to_vect(val, dividing, sym_ones);
	}
	int Roman_int::as_int()
	{
		vector <int> int_val;
		vector <char> check;
		for (char c : value)
		{
			switch (c)
			{
			case 'I': int_val.push_back(I); break;
			case 'V': int_val.push_back(V); break;
			case 'X': int_val.push_back(X); break;
			case 'L': int_val.push_back(L); break;
			case 'C': int_val.push_back(C); break;
			case 'D': int_val.push_back(D); break;
			case 'M': int_val.push_back(M); break;
			}
		}
		bool up = 0;
		bool down = 0;
		int result = 0;
		for (int i = 0; i < int_val.size(); ++i)
		{
			if (i < int_val.size() - 1)
				if (int_val[i] < int_val[i + 1])
				{
					result -= int_val[i];
				}
				else
				{
					result += int_val[i];
				}
			else
				result += int_val[i]; //For the last symbol or fow only one symbol
		}
		return result;
	};
	bool is_rom_correct(Roman_int &rom)
	{
		int val = rom.as_int();
		vector <char> check;
		int_to_rom(check, val);
		if (check == rom.value) return true;
		rom.value = check;
		return false;
	}
	ostream &operator <<(ostream &ost, Roman_int &rom)
	{
		for (char ch : rom.value)
			ost << ch;
		return ost;
	}
	istream &operator >>(istream &ist, Roman_int &rom)
	{
		bool mark = 0;
		char c;
		while (cin.get(c))
			switch (c)
			{
			case 'I':
			case 'V':
			case 'X':
			case 'L':
			case 'C':
			case 'D':
			case 'M':
				rom.value.push_back(c);
				break;
			default:
				if (!is_rom_correct(rom)) 
				{
					cerr << "The order of symbols or symbols "
						<< "is wrong!\n"
						<< "Value was changed to: " << rom << endl;
				}
				if (c == ' ') return ist;
				cin.unget();
				return ist;
			}
	}

