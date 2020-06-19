#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
struct Node
{
	T item;
	Node<T>* next;
	Node<T>(T k, Node<T>* n)	{
		item = k;
		next = n;
	}
	Node<T>() {
		next = NULL;
	}
};

template <class T>
class List
{
private:
	Node<T>* head;
public:
	List();
	List(T* a, int);
	List(const List& l);
	virtual ~List();

	void add(T a);
	void del(Node<T>*);
	void delAll();
	Node<T>* findNode(T a);
	bool empty();
	void addstart(T a);
	void delv(T a);
	void insert(T a);
	int getSize();
	void sort();
	Node<T>* findNodeID(const int id);
	void reverse();

	friend ostream& operator<<(ostream& os, List& l)
	{
		if (l.head == NULL) os << "list is empty \n";
		for (Node<T>* i = l.head; i; i = i->next)
			os << i->item << endl;
		return os;
	}
	friend istream& operator>>(istream& is, List& l)
	{
		if (l.head != NULL)
			l.delAll();
		l.head = NULL;
		Node<T>* temp;
		Node<T>* ptr = NULL;
		T k;
		while (is >> k) {
			temp = new Node<T>(k, NULL);
			if (!l.head) l.head = ptr = temp;
			else ptr->next = temp;
			ptr = temp;
		}
		if (is.bad()) cout << "bad";

		return is;
	}
};

template <class T>
List<T>::List()
{
	head = NULL;
}

template <class T>
List<T>::List(T* a, int n)
{
	head = NULL;
	Node<T>* temp;
	Node<T>* ptr = NULL;
	for (int i = 0; i < n; i++)
	{
		temp = new Node<T>(a[i], NULL);
		if (head == NULL)
			head = ptr = temp;
		else
			ptr->next = temp;
		ptr = temp;
	}
}

template <class T>
List<T>::List(const List& l)
{
	head = NULL;
	Node<T>* temp;
	Node<T>* ptr = NULL;
	for (Node<T>* i = l.head; i; i = i->next)
	{
		temp = new Node<T>(i->item, NULL);
		if (head == NULL)
			head = ptr = temp;
		else
			ptr->next = temp;
		ptr = temp;
	}
}

template <class T>
List<T>::~List()
{
	while (head) del(head);
}

template <class T>
void List<T>::delAll()
{
	while (head) del(head);
}

template <class T>
void List<T>::add(T a)
{
	Node<T>* temp = new Node<T>(a, NULL);
	if (head == NULL)
		head = temp;
	else
	{
		Node<T>* i;
		for (i = head; i->next; i = i->next);
		i->next = temp;
	}
}

template <class T>
void List<T>::del(Node<T>* ptr)
{
	if (ptr)
	{
		if (ptr == head)
		{
			head = head->next;
			delete ptr;
		}
		else
		{
			Node<T>* i;
			for (i = head; i->next != ptr && i->next; i = i->next);
			i->next = ptr->next;
			delete ptr;
		}
	}
}

template <class T>
Node<T>* List<T>::findNode(T a)
{
	Node<T>* i;
	for (i = head; i && i->item != a; i = i->next);
	return i;
}

template <class T>
bool List<T>::empty()
{
	return !head;
}

template <class T>
void List<T>::addstart(T a)
{
	Node<T>* temp = new Node<T>(a, head);
	head = temp;
}

template <class T>
void List<T>::delv(T a)
{
	del(findNode(a));
}

template <class T>
void List<T>::insert(T a)
{
	Node<T>* ptr = this->head;
	while (ptr->next)
	{
		if (ptr->item > ptr->next->item)
		{
			cout << "Not sorted!" << endl;
			return;
		}
		ptr = ptr->next;
	}
	ptr = this->head;
	while (ptr->next->item < a)
	{
		ptr = ptr->next;
	}
	Node<T>* temp = new Node<T>(a, ptr->next);
	ptr->next = temp;
}

template <class T>
int List<T>::getSize()
{
	int counter;
	Node<T>* i;
	for (i = head, counter = 0; i; i = i->next, counter++);
	return counter;
}

template <class T>
void List<T>::sort()
{
	for (int i = 1; i < getSize(); i++)
	{
		Node<T>* b = findNodeID(i);
		Node<T>* c = head;
		Node<T>* prev = NULL;
		while (b->item > c->item) {
			prev = c;
			c = c->next;
		}
		if (c == b)
			continue;
		Node<T>* ptr = head;
		while (ptr->next != b)
			ptr = ptr->next;
		ptr->next = ptr->next->next;
		if (prev)
		{
			prev->next = b;
			b->next = c;
		}
		else
		{
			b->next = c;
			head = b;
		}
		
	}
}

template <class T>
Node<T>* List<T>::findNodeID(const int id)
{
	Node<T>* i;
	int counter;
	for (i = head, counter = 0; i && counter < id; i = i->next, counter++);
	return i;
}

template <class T>
void List<T>::reverse()
{
	Node<T>* ptr = head->next;
	Node<T>* ptr2 = head->next->next;
	Node<T>* temp = head; temp->next = NULL;
	while (ptr2)
	{
		ptr->next = temp;
		temp = ptr;
		ptr = ptr2;
		ptr2 = ptr2->next;
	}
	ptr->next = temp;
	head = ptr;
}
