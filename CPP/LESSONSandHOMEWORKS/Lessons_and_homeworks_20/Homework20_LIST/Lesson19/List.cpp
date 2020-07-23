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
List &List::operator = (const List& R)
{
	m_pBeg = R.m_pBeg;
	m_pEnd = R.m_pEnd;
	m_nSize = R.m_nSize;
	return *this;
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
	cout << endl;
}
int List::size() const
{
	return m_nSize;
}
int List::sum() const //HOMEWORK
{
	Node* pCur = m_pBeg;
	int sum = 0;
	while (pCur != nullptr)
	{
		sum += pCur->m_val;
		pCur = pCur->m_pNext;
	}
	return sum;
}
void List::bubblesort()
{
	int nListSize = this->size();
	Node* pCur;
	for (int i = 0; i < nListSize; ++i)
	{
		pCur = m_pBeg;
		for (int j = 0; j < nListSize - i - 1; ++j)
		{
			if (pCur->m_val > pCur->m_pNext->m_val)
			{
				int temp = pCur->m_val;
				pCur->m_val = pCur->m_pNext->m_val;
				pCur->m_pNext->m_val = temp;
			}
			pCur = pCur->m_pNext;
		}
	}
	return;
}
List::Node* List::find(int val) //what should it return? //HOMEWORK
{
	Node *pCur = m_pBeg;
	while (pCur != nullptr)
	{
		if (pCur->m_val == val) return pCur;
		pCur = pCur->m_pNext;
	}
	cout << endl;
}
void List::delete_val(int val) //HOMEWORK
{
	/*Node *pCur;
	while (m_pBeg->m_val == val)
	{
		pCur = m_pBeg;
		m_pBeg = m_pBeg->m_pNext;
		delete pCur;
	}*/
	Node *pCur = m_pBeg, *pPrev = m_pBeg;
	while (pCur != nullptr)
	{
		if (pCur->m_val == val)
		{
			if (pCur == pPrev)
			{
				m_pBeg = pCur->m_pNext;
				delete pCur;
				pCur = pPrev = m_pBeg;
			}
			else
			{
				pPrev->m_pNext = pCur->m_pNext;
				delete pCur;
				pCur = pPrev->m_pNext;
			}
		}
		else
		{
			if (pCur != pPrev) pPrev = pPrev->m_pNext;
			pCur = pPrev->m_pNext;
		}
	}
	m_pEnd = pPrev;
}
void List::setBeg(int val)
{
	Node* N = new (std::nothrow) Node(val); // nothrow - check if memory
										    // obtained
	if (N != nullptr)
	{
		if (m_pBeg != nullptr)		
			delete m_pBeg;
		m_pBeg = N;
	}
}
void List::setEnd(int val)
{
	Node* N = new (std::nothrow) Node(val); // nothrow - check if memory
											// obtained
	if (N != nullptr)
	{
		if (m_pBeg != nullptr)
			delete m_pEnd;
		m_pEnd = N;
	}
}

List::iterator List::begin() const
{
	return List::iterator(m_pBeg);
}
List::iterator List::end() const
{
	return List::iterator(m_pEnd->m_pNext); // ==nullptr;
}
List::iterator::iterator(Node *N):pNode(N){};
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
List::iterator& List::iterator::operator++()
{
	pNode = pNode->m_pNext;
	return *this;
}
void List::iterator::set_val(int val)
{
	pNode->m_val = val;
}
