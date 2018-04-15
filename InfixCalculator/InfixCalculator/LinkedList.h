#pragma once


#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

#include "Node.h"


/*
UML form
+insertNode(entry: const T& , position: int) : bool
+pushNode(entry: const T& ) : bool
+deleteNode(index : int) : bool
+findNode(entry: const T&) : bool
+getSize() const : int
+clear() : void
+isEmpty const () : bool
*/


using namespace std;


template <class T>
class LinkedList : public Node<T> {

private:
	Node<T>* head;
	Node<T>* tail;
	int itemcount;

public:
	LinkedList();
	LinkedList(const Node<T>* headptr);


	bool insertNode(const T& entry, int position);
	bool pushNode(const T& entry);
	bool deleteNode(int index);
	bool findNode(const T& entry);
	int  getSize() const;
	void clear();
	bool isEmpty() const;
	int getValue() const;

	template <class T>
	friend ostream& operator<< (ostream &output, const LinkedList<T>* stackptr);

};




/*******Implementation************/




/******************************************
* LinkedList()
* default constructor
*/
template <class T>
LinkedList<T>::LinkedList() {

	head = nullptr;
	itemcount = 0;
}

/******************************************
* LinkedList()
* parametrized constructor
*/
template <class T>
LinkedList<T>::LinkedList(const Node<T>* headptr) {

	head = headptr;
	itemcount++;
}




/******************************************
* void insertNode();
* adds a node entry to the linkedlist at the specified index
* temp1 is current node, temp2 is previous node
*/
template <class T>
bool LinkedList<T>::insertNode(const T& entry, int position) {
	int i;
	Node<T>* temp1 = new Node<T>();
	temp1->setData(entry);
	temp1->setPtr(nullptr);

	if (position == 1) {
		temp1->setPtr(head);
		head = temp1;
		itemcount++;
		return true;
	}

	Node<T>*temp2 = new Node<T>();
	for (i = 0; i < position - 2; i++) {
		temp2 = temp2->getPtr();
	}

	temp1->setPtr(temp2->getPtr());
	temp2->setPtr(temp1);
	itemcount++;


	return true;
}


/******************************************
* void pushNode();
* adds a node entry to the linkedlist at
the beginning/
*/
template <class T>
bool LinkedList<T>::pushNode(const T& entry) {
	Node<T>* newNode = new Node<T>(entry);
	newNode->setPtr(nullptr);
	if (isEmpty()) {
		head = newNode;
	}
	else {
		newNode->setPtr(head);
		head = newNode;
	}
	itemcount++;
	return true;
}



/******************************************
* void deleteNode();
* deletes a node entry
*/
template <class T>
bool LinkedList<T>::deleteNode(int index) {
	Node<T>* temp1 = head;

	if (isEmpty()) {
		cout << "Stack is empty! Nothing to delete" << endl;
		return false;
	}

	if (index == 1) {
		head = temp1->getPtr();
		delete temp1;
		temp1->setPtr(nullptr);
		itemcount--;
		return true;
	}

	for (int i = 0; i < index - 2; i++) {
		temp1 = temp1->getPtr();
	}

	Node<T>*temp2 = temp1->getPtr();
	temp1->setPtr(temp2->getPtr());
	delete temp2;
	itemcount--;
	return true;
}




/******************************************
* bool findNode();
* returns true if the node specified in the parameter is found
*/
template <class T>
bool LinkedList<T>::findNode(const T& entry) {
	Node<T>* curr;

	while (curr != nullptr) {
		if (curr->getData() = entry) return true;
		else curr = curr->getPtr();
	}

	return false;
}


/******************************************
* int getsize()
* returns the number of items in the list
*/
template <class T>
int LinkedList<T>::getSize() const {
	return itemcount;
}



/******************************************
* void clear();
* clears the list
*/
template <class T>
void LinkedList<T>::clear() {
	head = nullptr;
	itemcount = 0;
}


/******************************************
* bool isEmpty;
* checks if the list is empty
*/
template <class T>
bool LinkedList<T>::isEmpty() const {
	if (itemcount == 0) return true;
	return false;
}

/****************************************
  int getValue();
  returns the value of first node in list

******************************************/
template <class T>
int LinkedList<T>::getValue() const{
	Node<T>* curr;
	
	if (isEmpty()) {
		return 0;
	}
	
	curr = head;
	return curr->getData();

}

#endif