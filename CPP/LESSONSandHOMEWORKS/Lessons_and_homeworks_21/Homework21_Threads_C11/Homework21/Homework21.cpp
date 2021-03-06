/*The Main goals of the task are : 
1. an overall architecture of app(OOP is required); 
2. threads communication design; 
3. how code is readable, code style; 
4. supposed strategy of error handling; 
5. testing.
Implementation: only C++ 98 / 11 and STL without 
any additional libraries.
1. Create an application which calculates prime 
numbers for intervals : 
-Load intervals from specified xml - based file; 
-For each interval start standalone thread for 
calculating prime numbers(threads calculations should be 
performed simultaneously); 
-Each calculation thread must store every calculated 
prime number to shared container(list, vector, etc); 
-Save unique prime numbers to xml - based file(primes tag). 
2. Implement unit tests for the app using any unit 
test framework(GoogleMock, MS Test and etc.)
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <exception>
using namespace std;

const int MINIMALDIVIDER = 2; //Number is not a primary if it divides by 2 or higher val;

//Function check numbers from nLower to nHigher and check is it primary
//If it is primary it writes it to the vector nData
void FindPrimValues(int nLower, int nHigher, vector <int>* nData, mutex* mMut);

int main()
try {
	string sInpName = "ABC.txt"; 
	ifstream fInFile(sInpName);
	if (!fInFile.is_open()) throw runtime_error("File to read data isn't opened!");

	string sOutName = "ABCDEF.txt";
	ofstream fOutFile(sOutName);
	if (!fOutFile.is_open()) throw runtime_error("File to write data isn't opened!");

	int nLoVal = 0, nHiVal = 0;
	mutex *mMut = new mutex;
	vector <int> nData;
	vector <thread*> tThreads;

	while (true)
	{
		fInFile >> nLoVal >> nHiVal;
		if (!fInFile) //processing of errors
		{
			if (fInFile.eof()) break; // END OF FILE 
			if (fInFile.bad()) throw runtime_error("The stream is spoiled!");
			if (fInFile.fail()) throw runtime_error("Wrong symbols in the input file!");
		}
		thread *pThr = new thread(FindPrimValues, nLoVal, nHiVal, &nData, mMut);
		tThreads.push_back(pThr);
	}

	for (thread *t : tThreads)
		if (t->joinable())
			t->join();


	for (int i = 0; i < nData.size(); ++i)
		fOutFile << nData[i] << " ";
	
	for (thread *t : tThreads)
		delete t;
	delete mMut;

	return 0;
}
catch (runtime_error& err)
{
	cerr << err.what();
}
catch (...)
{
	cerr << "Something unexpected has happened!";
}

void FindPrimValues(int nLower, int nHigher, vector <int>* nData, mutex* mMut)
{
	bool bNotPrimary = false;
	if (nLower > nHigher)
	{
		int temp = nLower;
		nLower = nHigher;
		nHigher = temp;
	}
	if (nLower < 0 || nHigher < 0)
		throw runtime_error("Values from diapason lower than 0!");
	for (double i = nLower; i <= nHigher; ++i) //select num
	{
		for (double j = MINIMALDIVIDER; j <= i / MINIMALDIVIDER; ++j) //select dividing num
		{                   //for example if we check number 100, diapason is [2,50], not higher
							//because to divide by nums from 51 to 99 hasn't sense 
			if (int(i / j) == double(i / j))
			{               //check if score 'i' is primary 
				bNotPrimary = true;
				break;
			}
		}
		if (!bNotPrimary)
		{
			mMut->lock(); //Mutex is needed to not write values from different
			nData->push_back(i); //threads in the same place
			mMut->unlock();
		}
		bNotPrimary = false;
	}
}