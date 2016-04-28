#include "node1.h"

Node:: Node(){
	SetVar(Type());
	SetNext(NULL);
	SetPrevous(NULL);
}
Node:: Node(Type a){
	SetVar(a);
	next = NULL;
	prev = NULL;
}
Node::Node(Type a, Node *n, Node *p){
	SetVar(a);
	SetNext(n);
	SetPrevous(p);
}
Node :: ~Node(){
	this->var = NULL;
}
ostream &operator<<(ostream &ostr, const Node head)
{
	ostr << head.var << " ";
	return ostr;
}
Node Node :: CreateNode(){	
		cin >> this->var;
		return *this;
}