#include "pch.h"
#include <iostream>
#include <memory>
using namespace std;

class memGuard
{
public:
	memGuard(int *pData) : m_pData(pData) {};
	~memGuard() { delete[] m_pData; }
private:
	int *m_pData;
};

int main()
{
	{
		try 
		{
			int *pData = new int[200];
			//memGuard mProtector(pData);
			unique_ptr <int> upData (pData);
			shared_ptr <int> sh1(new int(1));
			shared_ptr <int> sh2(sh1);
			shared_ptr <int> sh3;
			sh3 = sh2;
			cout << sh1.use_count() << endl;
			*sh3 = 124;
			cout << *sh2 << endl;
			if (true)
				throw (1);
			delete[] pData; // мы сюда можем просто не дойти 
		}
		catch (int& n) 
		{
			cout << n << " is cathced!\n";
		}
	}if (_CrtDumpMemoryLeaks()) cout << "Memory Leaks!!!!!!!\n";
}