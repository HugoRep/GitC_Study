#pragma once
#include <stdio.h>
#include <iostream>
class Node
{
public:
	int value = 0;
	Node* Next;
	Node* Prev;
};
template<typename T>
class LList
{
public:
	LList(){};
	virtual ~LList() {};

	class Iterator
	{
	public:
		Iterator(Node* init = nullptr) :Current(init) {}
		~Iterator() { delete Current; }
		Iterator operator++()
		{
			Current = Current->Next;
			return *this;
		}
	private:
		Node* Current;
	};

	void Insert(int NewVlaue);

	Iterator Begin() { return Iterator(Head->Next); };
	//Iterator* End();

protected:
	Node* Tail;
	Node* Head;
};

template<typename T>
inline void LList<T>::Insert(int NewVlaue)
{

}
