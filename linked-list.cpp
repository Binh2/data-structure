#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "linked-list.h"

#include <iostream>

template <typename T>
Node<T>::Node(T element) {
	data = element;
	pNext = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
	pHead = nullptr;
	pTail = nullptr;
}

template <typename T>
void LinkedList<T>::add(const T& element) {
	if (pTail == nullptr) {
		pHead = new Node<T>(element);
		pTail = pHead;
	} else {
		pTail->pNext = new Node<T>(element);
		pTail = pTail->pNext;
	}
}

template <typename T>
void LinkedList<T>::addAt(const T &element, unsigned pos) {
	if (pos == 0) {
		if (pHead == nullptr) {
			pHead = new Node<T>(element);
		} else {
			Node<T> *temp = new Node<T>(element);
			temp->pNext = pHead;
			pHead = temp;
		}
		return;
	}
	
	unsigned j = 0;
	for (Node<T> *i = pHead; i != nullptr; i = i->pNext, j++) {
		if (j == pos - 1) {
			Node<T> *temp = new Node<T>(element);
			temp->pNext = i->pNext;
			i->pNext = temp;
			return;
		}
	}
}

template <typename U>
std::ostream& operator<<(std::ostream &out, const LinkedList<U> &list) {
	for (Node<U> *i = list.pHead; i != nullptr; i = i->pNext) {
		out << i->data << " ";
	}
	return out;
}

#endif
