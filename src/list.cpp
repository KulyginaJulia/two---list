#include "list1.h"

List :: List(List &m){
	Node *tmp = m.head->next;
	Node *tmp_this;
	if (!m.head)
	{
		this->head = NULL;
		return;
	}
	this->head = new Node(m.head->var);
	tmp_this = this->head; 
	while(tmp != NULL){
		this->Insert(tmp_this, new Node(tmp->var));
		tmp_this = tmp_this->next;
		tmp = tmp->next;
	}
	tmp_this->next = NULL;
}
Node* List :: Search(Type key){
	Node *tmp = this->head; 

	bool flag = false;
	while (tmp != NULL){
		if (tmp->var < key) 
			tmp = tmp->next;
		else 
		{
			flag = true;
			break;
		}
	}
	if (tmp->var != key) 
		throw "Wasn`t found";
	return tmp;
}
void List :: Delete(Node *toDel, Node *&head){
	if (toDel->prev != NULL)
		toDel->prev->next = toDel->next;
	if (toDel->next != NULL)
		toDel->next->prev = toDel->prev;
	if (toDel == head)
		head = toDel->next;
	delete toDel;
}
void List :: DeleteKey(Type key){
	Node *f = new Node;
	f = Search(key);
	Delete(f,head);
}


void List :: Insert(Node *prev, Node *toAdd){
	if (prev == NULL){
		InsertBeforeHead(toAdd);
	}
	else {
	if (prev->next != NULL){
		toAdd->next = prev->next;
		prev->next->prev = toAdd;
	}
	else{
		toAdd->next = NULL;
	}
	prev->next = toAdd;
	toAdd->prev = prev;
	}
}
void List :: InsertBeforeHead(Node *temp) { 
 	if (head == NULL)
 	{
 		head = temp;
 	}
 	else
 	{
 		head->prev = temp;
		temp->SetNext(head);
 		head = temp;
 	}
}
List& List :: operator = (const List &A){
		if (this == &A) {
		return *this;
		}
	else {	
		this->DeleteList();
		Node *tmp;
		Node *tmp_this;
		if (!A.head)
		{
			this->head = NULL;
			return *this;
		}
		this->head = new Node(A.head->var);
		tmp = A.head->next;
		tmp_this = this->head; 
		while(tmp != NULL){
			this->Insert(tmp_this, new Node(tmp->var));
			tmp_this = tmp_this->next;
			tmp = tmp->next;
		}
		tmp_this->next = NULL;
	}	
	return *this;
}
List :: ~List(){
	DeleteList();
}
void List :: DeleteFirst(){
	Node *tmp = head;
	head = head->next;
	delete tmp;
}
void List :: DeleteList(){
	while( head != NULL)
		DeleteFirst();
}
ostream &operator<<(ostream &ostr,  const List& p)
{
	Node* tmp = p.head;

	while (tmp != NULL){
		ostr << tmp->var;
		ostr << "  ";
		tmp = tmp->next;
	}
	ostr << endl;
	return ostr;
}
void List ::  InsertOrdered(Type var) { 
		Node* current = head;
		Node* temp = new Node(var);

		if ((current == NULL) || (var < current->var)) {
			InsertBeforeHead(temp);
			return;
		}
		Node *Prev;
		while ((current) && (var > current->var)) // current->next && var > current->next->var
		{
			Prev = current;
			current = current->next;

		}
		if (current != NULL){
		current->prev->SetNext(temp);
		temp->prev = current->prev;
		temp->SetNext(current);
		current->prev = temp;
		}
		else {
			Prev->SetNext(temp);
			temp->SetPrevous(Prev);
			temp->SetNext(NULL);
		}
}