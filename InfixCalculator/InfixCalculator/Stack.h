#pragma once
#pragma once
#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

/*
UML
+push(entry : T) : bool
+pop() : bool
+isEmpty() : bool



*/

using namespace std;


template <class T>
class Stack : public LinkedList<T> {

public:
	
	
	Stack();
	~Stack();


	bool push(T entry);
	bool pop();
	bool isEmpty();
	T top();



};


/*****************************************
 T Top()- returns the top value of stack
******************************************/
 template <class T>
 T Stack<T>::top() {
	 T top = LinkedList<T>::getValue();
	 return top;
 }

/******************************************
* Stack();
* constructor
*/
template <class T>
Stack<T>::Stack() {

	LinkedList<T>();
}


/******************************************
* Stack();
* destructor
*/
template <class T>
Stack<T>::~Stack() {
	LinkedList<T>::clear();
}


/******************************************
* bool push()
* pushes an entry onto the stack
*/
template <class T>
bool Stack<T>::push(T entry) {
	return LinkedList<T>::pushNode(entry);

}


/******************************************
* bool pop()
* pops an entry off the stack
*/
template <class T>
bool Stack<T>::pop() {

	return LinkedList<T>::deleteNode(1);

}


/******************************************
* bool isEmpty()
* checks if the stack is empty or not
*/
template <class T>
bool Stack<T>::isEmpty() {
	return LinkedList<T>::isEmpty();
}

#endif