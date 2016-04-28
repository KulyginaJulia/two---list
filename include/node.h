#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef int Type;

class Node{
public:
	Type var;
	Node *next;
	Node *prev;

	void SetVar(Type a){ var = a; }
	void SetNext(Node *n){ next = n; }
	void SetPrevous(Node *n){ prev = n; }
	Node *GetNext(){ return next; }
	Node *GetPrevous(){ return prev; }
	Type GetVar(){ return var; }
	
	Node();
	Node(Type a);
	Node(Type a, Node *p, Node *n);
	~Node();	
	Node CreateNode();
	friend ostream &operator<<(ostream &ostr, const Node *head);
};