// Stroustrup_section4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "../../std_lib_facilities.h"

int main()
{
	vector <string> disliked = { "Pizda","Jopa","Yaichki" };
	vector <string> words;
	cout << "please enter the words and press 'Enter' after each: " << endl;
	for (string word; cin >> word;) //Entering words
	{
		for (string x : disliked) //Testing the word
		{
			if (word == x) word = "BLEEP";
		}
		words.push_back(word);
	}
	cout << "Your words is: ";
	for (string x : words)
	{
		cout << x << " ";
	}
	return 0;
}
	