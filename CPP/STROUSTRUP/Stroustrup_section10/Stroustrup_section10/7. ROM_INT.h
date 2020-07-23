
#pragma once


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

	void write_to_vect(vector <char>& vect, int how_many,
		int what);
	void int_to_rom(vector <char> &val, int x);
	// Roman_int::as_int();
	bool is_rom_correct(Roman_int &rom);
	ostream &operator <<(ostream &ost, Roman_int &rom);
	istream &operator >>(istream &ist, Roman_int &rom);
