#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
template <typename T = int>
struct Node {
    T data;
    Node *pNext;
	
	Node(T);
};

template <typename T = int>
class LinkedList {
private:
	Node<T> *pHead, *pTail;

public:
	LinkedList();
	void add(const T &);
	void addAt(const T &, unsigned);
	
	template <typename U>
	friend std::ostream& operator<< (std::ostream &, const LinkedList<U> &);
};

#include "linked-list.cpp"
#endif
