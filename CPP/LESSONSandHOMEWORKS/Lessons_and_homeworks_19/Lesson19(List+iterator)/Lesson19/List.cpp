#include "pch.h"
#include "List.h"


List::~List()
{
	Node* pCur = m_pBeg;
	while (pCur != nullptr)
	{
		m_pBeg = pCur->m_pNext;
		delete pCur;
		pCur = m_pBeg;
	}
}
void List::push_back(int el)
{
	Node* N = new (std::nothrow) Node(el); // nothrow - check if memory
	                                       // obtained
	if (N != nullptr)
	{
		++m_nSize;
		if (m_pBeg == nullptr)
		{
			m_pBeg = N;
		}
		else
		{
			m_pEnd->m_pNext = N;
		}
		m_pEnd = N;
	}
}
void List::show() const
{
	Node *pCur = m_pBeg;
	while (pCur != nullptr)
	{
		cout << pCur->m_val << " ";
		pCur = pCur->m_pNext;
	}
	cout << std::endl;
}
int List::size() const
{
	return m_nSize;
}
List::iterator::iterator(Node *N):pNode(N){};
List::iterator& List::iterator::operator++()
{
	pNode = pNode->m_pNext;
	return *this;
}
bool List::iterator::operator==(const iterator & right) const
{
	return (pNode == right.pNode);
}
bool List::iterator::operator!=(const iterator & right) const
{
	return !(*this == right);
}
int List::iterator::operator*() const
{
	return pNode->m_val;
}
List::iterator List::begin() const
{
	return List::iterator(m_pBeg);
}
List::iterator List::end() const
{
	return List::iterator(m_pEnd->m_pNext); // ==nullptr;
}