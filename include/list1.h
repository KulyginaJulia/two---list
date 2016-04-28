#pragma once
#include "node1.h"
#include <iostream>

using namespace std;

class List{
public:
	Node *head;

	List(){ head = NULL;}
	List(List &m);
	
	Node *GetHead() { return head; }
	Node* Search(Type key);
	void Delete(Node *toDel, Node *&head);
	void Insert(Node *prev, Node *toAdd);
	void InsertOrdered(Type var);
	void InsertBeforeHead(Node *temp);
	void DeleteKey(Type key);


	List& operator=(const List &A);
	~List();
	friend ostream &operator<<(ostream &ostr, const List& p) ;
	void DeleteFirst();
	void DeleteList();
};