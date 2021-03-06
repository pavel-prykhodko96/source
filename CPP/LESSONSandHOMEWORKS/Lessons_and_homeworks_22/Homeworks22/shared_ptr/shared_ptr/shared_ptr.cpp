#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
class MySharedPtr
{
public:
	MySharedPtr() 
	{};
	MySharedPtr(T* ptr) : m_pPointer(ptr)
	{}
	MySharedPtr(MySharedPtr& R)
	{
		this->m_pPointer = R.m_pPointer;
		if (R.m_bIsLast == false)
			this->m_bIsLast = false;
		else R.m_bIsLast = false;
	}
	~MySharedPtr()
	{
		if (m_bIsLast)
		  if (m_pPointer!=nullptr)
			delete m_pPointer;
	}
	MySharedPtr& operator = (MySharedPtr& R)
	{
		this->m_pPointer = R.m_pPointer;
		if (R.m_bIsLast == false)
			this->m_bIsLast = false;
		else R.m_bIsLast = false; 
		return *this;
	}
	T& operator *() { return *this->m_pPointer; }
	int use_count() { return m_nCounter; }

	static int m_nCounter;
	T* m_pPointer = nullptr;
	bool m_bIsLast = true;
};

int main()
{
	{
		int *a = new int(1);
		MySharedPtr <int> b(a);
		MySharedPtr <int> c(b);
		MySharedPtr <int> d;
		MySharedPtr <int> g(b);
		MySharedPtr <int> f;
		MySharedPtr <int> j(new int (5));
		
		d = c;
		f = b;
		cout << *b << " " << f.use_count();
	}if (_CrtDumpMemoryLeaks()) std::cout << "TAKOE";
}
