// Stroustrup_section8.02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "../../std_lib_facilities.h"

int f(const int l)
{
	return l;
}

int main()
{
	int x = 7;
	cout << f(x);
	x = 8;
	cout << f(x);
	
}

/*
vector <int> how_much(vector <string> words)
{
	vector <int> scores;
	string short_word, long_word;
	int index_l(0), index_h(0);
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i].size() <= words[index_l].size())
		{
			short_word = words[i];
			index_l = i;
		}
		if (words[i].size() >= words[index_h].size())
		{
			long_word = words[i];
			index_h = i;
		}
		scores.push_back(words[i].size());
	}
	cout << "the lowest score of symbols has a '" << short_word << "'" << endl
		<< "the highest score of symbols has a '" << long_word << "'" << endl;
	sort(words);
	cout << "The first word by the alphabet is: " << words[0] << endl
		<< "The last word by the alphabet is: " << words[words.size() - 1] << endl;
	return scores;
}
int main()
{
	vector <string> words{ "hi", "a", "cry_monster_devil_may_cry",
		"reebook", "jack", "nice", "life_is_good", "bye-bye", "p" };
	vector <int> scores = how_much(words);
	for (int i = 0; i < words.size(); ++i) cout << words[i] 
		<< ": " << scores[i] << " symbols" << endl;
	return 0;
}
*/

/*
void print_until_s(vector<string> v, string quit)
{
	int counter(0);
	for (string s : v)
	{
		if (s == quit)
		{
			++counter;
			if (counter > 1) return;
		}
		cout << s << endl;
	}
}

int main()
{
	vector <string> q = { "abc", "cad", "quit" };
	print_until_s(q, "quit");
}
*/

/*
struct clresult
{
	double a;
	double m;
	double min;
	double max;
	clresult(double av, double med, double minv, double maxv) 
		: a{ av }, m{ med }, min{ minv }, max{ maxv }{};
};
void print(const vector<double>& numbers)
{
	if (numbers.size() > 0)
	{
		for (int i = 0; i < numbers.size() - 1; ++i)
		{
			cout << numbers[i] << ", ";
		}
		cout << numbers[numbers.size() - 1] << endl;
	}
	else error("No values in the vector!");
}
double sum(const vector <double>& vec)
{
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		sum += vec[i];
	}
	return sum;
}
clresult super_func(vector <double> vec)
{
	double average(0), median(0), min_val(0), max_val(0);
	sort(vec);
	average = sum(vec) / vec.size();
	if (vec.size() % 2 == 0) median = (vec[vec.size()/2 - 1] 
		+ vec[vec.size()/2]) / 2;
	else median = vec[vec.size() / 2];
	min_val = vec[0];
	max_val = vec[vec.size() - 1];
	clresult ret(average, median, min_val, max_val);
	return ret;
}
int main()
{
	vector <double> values{ 165,23,348,41,325,26,997,8,11,1065,1209 };
	clresult result = super_func(values);
	print(values);
	cout << result.a << " -average " << result.m << " -median " << result.min
		<< " -min_val " << result.max << " -max_val " << endl;
	return 0;
}
*/


void sort_ages(vector <string>& names, vector <string>& names_copy,
	vector <int>& ages, int value,int index)
{
	int temp = 0;
	for (int j = 0; j < names.size(); ++j)
	{
		if (names_copy[index] == names[j])
		{
			temp = ages[j];
			ages[j] = value;
			names_copy[index] = " ";
			sort_ages(names, names_copy, ages, temp, j);
		}
	}
}
/*
int main()
{
	vector <string> names;
	vector <string> names_copy;
	vector <int> ages;
	string name("");
	int age(0);
	for (int i = 0;; ++i)
	{
		cin >> name;
		if (name == "stop") break;
		names.push_back(name);
	}
	for (int i = 0; i < names.size(); ++i)
	{	
		cin >> age;
		ages.push_back(age);
	}
	names_copy = names;
	sort(names.begin(), names.end());
	for (int i = 0; i < names_copy.size(); ++i)
	{
		sort_ages(names, names_copy, ages, ages[i], i);
	}
	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << " " << ages[i] << endl;
	}
	return 0;
}
*/

/*void print(const vector<string>& numbers)
{
	if (numbers.size() > 0)
	{
		for (int i = 0; i < numbers.size() - 1; ++i)
		{
			cout << numbers[i] << ", ";
		}
		cout << numbers[numbers.size() - 1] << endl;
	}
	else error("No values in the vector!");
}
void changer(vector<string> vec)
{
	vector <string> duplicate;
	for (int i = vec.size()-1; i >= 0; --i)
	{
		duplicate.push_back(vec[i]);
	}
	print(duplicate);
}
void ref_changer(vector<string>& vec)
{
	for (int i = 0; i < vec.size() / 2; ++i)
	{
		swap(vec[i], vec[vec.size()-1-i]);
	}
	print(vec);
}
int main()
try{
	vector <string> numbers;
	for (int i = 0; i < 5; ++i)
	{
		numbers.push_back("a"+8+i);
	}
	changer(numbers);
	ref_changer(numbers);
	return 0;
}
catch (runtime_error & e)
{
	cerr << e.what();
	return 1;
}
*/

/*
void fibonacci(int x, int y, int n, vector<int>& v)
{
	int next(0);
	v.push_back(x);
	v.push_back(y);
	for (int i = 0; i < n; ++i)
	{
		next = x + y;
		x = y;
		y = next;
		v.push_back(next);
	}
	print(v);
}
void fibonacci_for_max(int x, int y, int n, vector<int>& v)
{
	int next(0);
	v.push_back(x);
	v.push_back(y);
	while (true)
	{
		next = x + y;
		if (next < 0)
		{
			cout << y;
			break;
		}
		x = y;
		y = next;
		v.push_back(next);
	}
}
int main()
{
	int x(0), y(0), n(0);
	vector <int> v;
	cout << "Enter the x, y and n: \n";
	cin >> x >> y >> n;
	fibonacci_for_max(x, y, n, v);
	return 0;
}*/