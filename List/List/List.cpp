#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
	head = NULL;
}

List::List(Worker* a, int n)
{
	head = NULL;
	Node* temp;
	Node* ptr = NULL;
	for (int i = 0; i < n; i++)
	{
		temp = new Node(a[i], NULL);
		if (head == NULL)
			head = ptr = temp;
		else
			ptr->next = temp;
		ptr = temp;
	}
}

List::List(const List& l)
{
	head = NULL;
	Node* temp;
	Node* ptr = NULL;
	for (Node* i = l.head; i; i = i->next)
	{
		temp = new Node(i->item, NULL);
		if (head == NULL)
			head = ptr = temp;
		else
			ptr->next = temp;
		ptr = temp;
	}
}

List::~List()
{
	while (head) del(head);
}

void List::delAll()
{
	while (head) del(head);
}


void List::add(Worker a)
{
	Node* temp = new Node(a, NULL);
	if (head == NULL)
		head = temp;
	else
	{
		Node* i;
		for (i = head; i->next; i = i->next);
		i->next = temp;
	}
}

void List::del(Node* ptr)
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
			Node* i;
			for (i = head; i->next != ptr && i->next; i = i->next);
			i->next = ptr->next;
			delete ptr;
		}
	}
}

Node* List::findNode(Worker a)
{
	Node* i;
	for (i = head; i && i->item != a; i = i->next);
	return i;
}

bool List::empty()
{
	return !head;
}

void List::addstart(Worker a)
{
	Node* temp = new Node(a, head);
	head = temp;
}

void List::delv(Worker a)
{
	del(findNode(a));
}

void List::insert(Worker a)
{
	Node* ptr = this->head;
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
	Node* temp = new Node(a, ptr->next);
	ptr->next = temp;
}

int List::getSize()
{
	int counter;
	Node* i;
	for (i = head, counter = 0; i; i = i->next, counter++);
	return counter;
}

void List::sort()
{
	for (int i = 1; i < getSize(); i++)
	{
		Node* b = findNodeID(i);
		int j = i - 1;
		while (j >= 0 && findNodeID(j)->item > b->item)
			j = j - 1;
		Node* ptr = head;
		while (ptr->next != b)
			ptr = ptr->next;
		Node* temp = ptr->next;
		ptr->next = ptr->next->next;
		temp->next = findNodeID(j + 1);
		if (j + 1 == 0)
			head = temp;
		else
			findNodeID(j)->next = temp;
	}
}

Node* List::findNodeID(const int id)
{
	Node* i;
	int counter;
	for (i = head, counter = 0; i && counter < id; i = i->next, counter++);
	return i;
}

void List::reverse()
{
	Node* ptr = head->next;
	Node* ptr2 = head->next->next;
	Node* temp = head; temp->next = NULL;
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

ostream& operator<<(ostream& os, List& l) {
	if (l.head == NULL) os << "list is empty \n";
	for (Node* i = l.head; i; i = i->next)
		os << i->item << endl;
	return os;
}

istream& operator>>(istream& is, List& l) {
	if (l.head != NULL)
		l.delAll();
	l.head = NULL;
	Node* temp;
	Node* ptr = NULL;
	Worker k;
	while (is >> k) {
		temp = new Node(k, NULL);
		if (!l.head) l.head = ptr = temp;
		else ptr->next = temp;
		ptr = temp;
	}
	if (is.bad()) cout << "bad";

	return is;
}
