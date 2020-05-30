#pragma once
#include "Worker.h"


struct Node
{
	Worker item;
	Node* next;
	Node(Worker k, Node* n)	{
		item = k;
		next = n;
	}
	Node() {
		next = NULL;
	}
};

class List
{
private:
	Node* head;
public:
	List();
	List(Worker* a, int);
	List(const List& l);
	virtual ~List();

	void add(Worker a);
	void del(Node*);
	void delAll();
	Node* findNode(Worker a);
	bool empty();
	void addstart(Worker a);
	void delv(Worker a);
	void insert(Worker a);
	int getSize();
	void sort();
	Node* findNodeID(const int id);
	void reverse();

	friend ostream& operator<<(ostream& os, List& l);
	friend istream& operator>>(istream& is, List& l);
};

