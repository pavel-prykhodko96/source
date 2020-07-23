#include "pch.h"
#include "A.h"


A::A(int n) :m_a(n) { ++m_nCountObj; }
A::~A() 
{ --m_nCountObj; }
A::A() 
{ 
	++m_nCountObj; 
	m_a = 0; 
}
int A::getStatVar() { return m_nStatVar; }
int A::m_nStatVar = 7;
int A::m_nCountObj = 0;