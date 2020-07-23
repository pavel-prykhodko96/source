#include "pch.h"
#include "List.h"
/*
class List
{
	struct Node;
	class iterator;
public:
	List() = default;
	~List();
	void push_back(int el);
	void show() const;
	int size() const;
	int sum() const;
	// ____ find(int val); //what should it return?
	void delete_val (int val);
	iterator begin() const;
	iterator end() const; //iterator(node* == nullptr)
	class iterator
	{
		Node *pNode;
	public:
		iterator(Node *N = nullptr);
		bool operator ==(const iterator & right) const;
		bool operator !=(const iterator & right) const;
		int operator* () const;
		iterator& operator++();
	};
private:
	struct Node
	{
		Node(int n) : m_val(n), m_pNext(nullptr) {}
		int m_val;
		Node *m_pNext;
	};
	Node *m_pBeg = nullptr;
	Node *m_pEnd = nullptr;
	int m_nSize = 0;
};*/

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
