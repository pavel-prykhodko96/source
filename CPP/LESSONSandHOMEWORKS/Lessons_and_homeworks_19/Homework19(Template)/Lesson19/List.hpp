#pragma once
#include <new>
#include <iostream>
using namespace std;

template <typename T>
class List
{
	struct Node;
	//class iterator;
public:
	List() = default;
	~List() 
	{
		Node* pCur = m_pBeg;
		while (pCur != nullptr)
		{
			m_pBeg = pCur->m_pNext;
			delete pCur;
			pCur = m_pBeg;
		}
	}
	void push_back(T elem)
	{
		Node* N = new (std::nothrow) Node(elem); // nothrow - check if memory
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
	void show() const
	{
		Node *pCur = m_pBeg;
		while (pCur != nullptr)
		{
			cout << pCur->m_element << " ";
			pCur = pCur->m_pNext;
		}
		cout << endl;
	}
	int size() const
	{
		return m_nSize;
	}
	T sum() const
	{
		Node* pCur = m_pBeg;
		T sum = 0;
		while (pCur != nullptr)
		{
			sum += pCur->m_element;
			pCur = pCur->m_pNext;
		}
		return sum;
	}
	Node* find(T elem) //what should it return?
	{
		Node *pCur = m_pBeg;
		while (pCur != nullptr)
		{
			if (pCur->m_element == elem) return pCur;
			pCur = pCur->m_pNext;
		}
		cout << endl;
	}
	void delete_val (T elem)
	{
		Node *pCur;
		while (m_pBeg->m_element == elem)
		{
			pCur = m_pBeg;
			m_pBeg = m_pBeg->m_pNext;
			delete pCur;
		}
		Node *pPrev = m_pBeg;
		pCur = pPrev->m_pNext;
		while (pCur != nullptr)
		{
			if (pCur->m_element == elem)
			{
				pPrev->m_pNext = pCur->m_pNext;
				delete pCur;
			}
			else pPrev = pPrev->m_pNext;
			pCur = pPrev->m_pNext;
		}
		m_pEnd = pPrev;
	}
	class iterator
	{
		Node *pNode;
	public:
		iterator(Node *N = nullptr) :pNode(N) {};
		bool operator ==(const iterator & right) const
		{
			return (pNode == right.pNode);
		}
		bool operator !=(const iterator & right) const
		{
			return !(*this == right);
		}
		T operator* () const
		{
			return pNode->m_element;
		}
		iterator& operator++()
		{
			pNode = pNode->m_pNext;
			return *this;
		}
	};
	iterator begin() const
	{
		return List::iterator(m_pBeg);
	}
	iterator end() const //iterator(node* == nullptr)
	{
		return List::iterator(m_pEnd->m_pNext); // ==nullptr;
	}	
private:
	struct Node
	{
		Node(T n) : m_element(n), m_pNext(nullptr) {}
		T m_element;
		Node *m_pNext;
	};
	Node *m_pBeg = nullptr;
	Node *m_pEnd = nullptr;
	int m_nSize = 0;
};