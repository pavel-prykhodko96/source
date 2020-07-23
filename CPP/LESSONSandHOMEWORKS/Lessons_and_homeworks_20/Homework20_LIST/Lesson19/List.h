#pragma once
#include <new>
#include <iostream>
using namespace std;

class List
{
	struct Node;
	class iterator;
public:
	List() = default;
	~List();
	List & operator = (const List& R);
	void push_back(int el);
	void show() const;
	int size() const;
	int sum() const;
	void bubblesort();
	Node* find(int val); //what should it return?
	void delete_val (int val);
	void setBeg(int val);
	void setEnd(int val);
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
		void set_val(int val);
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
};