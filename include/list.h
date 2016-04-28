#pragma once
#include "node.h"
#include <iostream>

class List{
public:
	Node *head;

	List(){ head = NULL;}
	List(List &m);
	
	Node *GetHead() { return head; }
	Node *Search();
	void Delete(Node *toDel, Node *&head);
	void Insert(Node *prev, Node *toAdd);
	void InsertFirst(Node *prev, Node * toAdd);

	List& operator=(const List &B);
	~List();
	friend ostream &operator<<(ostream &ostr, const List& p) ;
	void DeleteFirst();
	void DeleteList();
	List Entering();
	List Sort();
};