
#include "pch.h"
#include <stdlib.h>
#include "Array.h"
#include "BackUp.h"

using namespace std;

int main()
{

	Array ar1(10);
	for (int i = 0; i < 20; ++i)
		ar1.push_back(10000+i);
	char cStr[] = "1.txt";
	BackUp setBU;           //To initialize BackUp               
	ar1.setBackUp(&setBU);  //And allocate memory
	ar1.setName(cStr);
	ar1.writeToFile();
	Array ar2(10);
	ar2.setBackUp(&setBU);  //This is the same, 
							//need to do it each time
	ar2.setName(cStr);
	ar2.createArrFromFile();
	//ar2.show();
	Array ar3 = std::move(ar2);
	ar3.show();
	Array ar4(0);
	cout << "This is for + operator\n\n\n\n\n\n\n\n";
	ar4 = ar3;
	ar4.show();
	ar4 = ar4 + 1;
	ar4.show();
	ar4 = 1 + ar4 + 1 + ar4 + 5 +5 +8 + 8 +9 +164 +546516+4+ 54+54+54 +546+1;
	ar4.show();

	return 0;
}




