#include <iostream>
using namespace std;

template <typename T = int>
struct Node {
    T data;
    Node *pNext;
	
	Node(T element) {
		data = element;
		pNext = nullptr;
	}
};

template <typename T = int>
class LinkedList {
private:
	Node<T> *pHead, *pTail;

public:
	LinkedList() {
		pHead = nullptr;
		pTail = nullptr;
	}
	
	void add(T element) {
		if (pTail == nullptr) {
			pHead = new Node<T>(element);
			pTail = pHead;
		} else {
			pTail->pNext = new Node<T>(element);
			pTail = pTail->pNext;
		}
	}
	
	friend ostream& operator<<(ostream &out, const LinkedList<T> &list) {
		for (Node<T> *i = list.pHead; i != nullptr; i = i->pNext) {
			out << i->data << " ";
		}
		return out;
	}
};

int main() {
//	LinkedList<> list;
//	int element;
////	cout << "Press Ctrl + D to escape: \n";
//	while (cin >> element) {
//		list.add(element);
//	}
//	cout << list;
	return 0;
}
