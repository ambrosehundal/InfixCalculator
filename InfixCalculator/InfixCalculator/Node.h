#pragma once
#pragma once
/*
Ambrose Hundal
Lab 2 CIS22C
StackADT
Winter 2018

Node.h

UML Notation
+getData const() : T
+setData(info : const T) : void
+getPtr() const : Node<T>*
+setPtr(nextPtr: Node<T>*): void


*/

#ifndef NODE_H
#define NODE_H


template <class T>
class Node {

protected:
	T data;
	Node<T>* next;

public:

	//Constructors and destructors
	Node();
	Node(const T& info);
	~Node();

	//getter and setter methods
	T getData() const;
	void setData(const T& info);
	Node<T>* getPtr() const;
	void setPtr(Node<T>* nextptr);

};

/****************************************/
/*Implementation*/
/*Default constructor */

template <class T>
Node<T>::Node() {

	next = nullptr;
}

/****************************************
***Constructor**********/
template <class T>
Node<T>::Node(const T& info) {
	data = info;
	next = nullptr;

}

/******************************************
/*******Destructor*/
template <class T>
Node<T>::~Node() {
	next = nullptr;

}


/******************************************
* getData();
* returns the data value stored in the Node
*/

template <class T>
T Node<T>::getData() const {

	return data;
}



/******************************************
* void setData();
* sets the data value in the node to the parameter
value inside function
*/
template <class T>
void Node<T>::setData(const T& info) {

	data = info;
}


/******************************************
* Node<T>* getPtr();
* returns the pointer (address value) stored in the Node
*/
template <class T>
Node<T>* Node<T>::getPtr() const {

	return next;
}

/******************************************
* void setPtr();
* sets the pointer (address value) stored in the Node
*/

template <class T>
void Node<T>::setPtr(Node<T>* nextptr) {

	next = nextptr;

}

#endif