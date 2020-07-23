#pragma once
#include <new>
#include <iostream>
using std::cout;

class List
{
	struct Node;
public:
	List() = default;
	~List();
	void push_back(int el);
	void show() const;
	int size() const;
	class iterator
	{
		Node *pNode;
	public:
		iterator(Node *N);
		iterator& operator++();
		bool operator ==(const iterator & right) const;
		bool operator !=(const iterator & right) const;
		int operator* () const;
	};
	iterator begin() const;
	iterator end() const; //iterator(node* == nullptr)
private:
	struct Node
	{
		int m_val;
		Node *m_pNext;
		Node(int n) : m_val(n), m_pNext(nullptr) {}
	};
	Node *m_pBeg = nullptr;
	Node *m_pEnd = nullptr;
	int m_nSize = 0;
};