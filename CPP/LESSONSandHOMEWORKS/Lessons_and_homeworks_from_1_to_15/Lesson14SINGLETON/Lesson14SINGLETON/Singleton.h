
#include <iostream>
using namespace std;
class Singleton
{
public:
	Singleton(int size);
	~Singleton();
	void show();
private:
	static int* m_pArr;
	static int m_nSize;
	static int m_nCountObj;
};