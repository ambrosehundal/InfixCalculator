/*
 Ambrose Hundal
 Lab 3 CIS22C
 InfixExpressionCalculator
 Winter 2018


*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Stack.h"
#include "InfixCalculator.h"


using namespace std;

Stack <char> S;
Stack <int>  D;

Stack <char>* stack1 = &S;
Stack <int>* stack2 = &D;

bool IsOperator(char c);
bool IsOperand(char c);
int OperatorWeight(char op);

int HigherPrecedence(char op1, char op2);

string infixToPostfix(string s, Stack<char>* charPtr);
int EvaluatePostfix(string postfix, Stack<int>* intPtr);

string infixToPrefix(string expression);
int EvaluatePrefix(string prefix, Stack<int>* intPtr);
int PerformOperation(char operation, int op1, int op2);






/******************************
  RightAssociative
*******************************/
 int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}






/**************************
bool IsOperator
	function to check if
	a character is an operator
	or not
	*/
	bool IsOperator(char c) {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			return true;
		}
		return false;
	}


	/*****************************
	PerformOperation
	Performs the operation on the
	two operands associated
	*/
	int PerformOperation(char operation, int op1, int op2)
	{
		if (operation == '+') return op1 + op2;
		else if (operation == '-') return op1 - op2;
		else if (operation == '*') return op1 * op2;
		else if (operation == '/') return op1 / op2;

		else cout << "Unexpected Error \n";
		return -1;
	}






	/***************************
	bool IsOperand()
	- Takes in a character and
	checks if its a letter or
	digit
	****************************/
	bool IsOperand(char c) {
		if (c >= '0' && c <= '9') return true;
		if (c >= 'a' && c <= 'z') return true;
		if (c >= 'A' && c <= 'Z') return true;
		return false;
	}


	/**************************
	int OperatorWeight
	function to get  order of
	precedence of an operator
	***************************/
	int OperatorWeight(char op) {
		int weight = -1;
		switch (op) {
		case '+':
		case '-':
			weight = 1;

		case '*':
		case '/':
			weight = 2;

		}
		return weight;
	}

	/****************************
	int HigherPrecedence
	checks operators to see which
	one has higher order of
	precedence
	*****************************/
	int HigherPrecedence(char op1, char op2) {
		int op1Weight = OperatorWeight(op1);
		int op2Weight = OperatorWeight(op2);

		// If operators have equal precedence, return true if they are left associative. 
		// return false, if right associative. 
		// if operator is left-associative, left one should be given priority. 
		if (op1Weight == op2Weight)
		{
			if (IsRightAssociative(op1)) return false;
			else return true;
		}
		return op1Weight > op2Weight ? true : false;

	}





	/****************************
	infixToPostfix
	converts an infix expression to
	a postfix expression
	****************************/
	string infixToPostfix(string s, Stack <char>* charPtr) {
		
		string postfix = "";
		for (unsigned int i=0;i<s.length();i++) {

			// Scanning each character from left. 
			// If character is a delimitter, move on. 
			//if (expression[i] == ' ' || expression[i] == ',') continue;

			// If character is operator, pop two elements from stack, perform operation and push the result back. 
			if (IsOperator(s[i]))
			{
				while (!charPtr->isEmpty() && charPtr->top() != '(' && HigherPrecedence(charPtr->top(), s[i]))
				{
					postfix += charPtr->top(); //use *top
					charPtr->pop();
				}
				charPtr->push(s[i]);
			}
			/*if character is a digit or letter */
			else if (IsOperand(s[i]))
			{
				postfix += s[i];
			}

			else if (s[i] == '(')
			{
				charPtr->push(s[i]);
			}

			else if (s[i] == ')')
			{
				while (!charPtr->isEmpty() && charPtr->top() != '(') { 
					postfix += charPtr->top();
					charPtr->pop();
				}
				charPtr->pop();
			}
		}

		while (!charPtr->isEmpty()) {
			postfix += charPtr->top();
			charPtr->pop();
		}
		charPtr->clear();
		return postfix;
	}

	/****************************
	EvaluatePostfix
	- calculate postfix expression
	and print result
	****************************/
	int EvaluatePostfix(string n, Stack<int>* intPtr)
	{
	

		for (unsigned int i = 0; i< n.length(); i++) {
	/* If character is an operator, pop two elements from stack, 
	   perform the operation using PerformOperation
	   and push the result back. 
	*/
			if (IsOperator(n[i])) {
			
				int operand2 = intPtr->top(); 
				intPtr->pop();
				int operand1 = intPtr->top();
				intPtr->pop();
			
				int result = PerformOperation(n[i], operand1, operand2); 
				intPtr->push(result);
			}
			else if (IsOperand(n[i])) {
				int operand = 0;
				while ( i<n.length() && IsOperand(n[i])) {
					operand = (operand * 10) + (n[i] - '0');
					i++;
				}
				i--;
				intPtr->push(operand);
			}
		}
	
		return intPtr->top();
		intPtr->clear();
	}

	/******************************
	
	
	*/

	string infixToPrefix(string infix)
	{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix  *  */
	int l = infix.size();

	reverse(infix.begin(), infix.end());

	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}

	string prefix = infixToPostfix(infix, stack1);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

	/****************************
	 EvaluatePrefix
	 - Evaluates the prefix notation
	 string and returns and prints 
	 the result.
	****************************/
	int EvaluatePrefix(string expression, Stack<int>* intPtr)
	{
	

		for (int j = expression.size() - 1; j >= 0; j--) {

			// Push operand to Stack
			// To convert exprsn[j] to digit subtract
			// '0' from exprsn[j].
			if (IsOperand(expression[j]))
				intPtr->push(expression[j] - '0');

			else { 

				// Operator encountered
				// Pop two elements from Stack
				int o1 = intPtr->top();
				intPtr->pop();
				int o2  = intPtr->top();
				intPtr->pop();

				
				switch (expression[j]) {
				case '+':
					intPtr->push(o1 + o2);
					break;
				case '-':
					intPtr->push(o1 - o2);
					break;
				case '*':
					intPtr->push(o1 * o2);
					break;
				case '/':
					intPtr->push(o1 / o2);
					break;
				}
			}
		}

		return intPtr->top();
	}



	

	int main()
	{

		string input = "";

		while (true) {

			cout << "Enter an Infix Expression: " << endl;
			cin >> input;
			//verify input is a valid infix expression

			string postfix = infixToPostfix(input, stack1);
			int res1 = EvaluatePostfix(postfix, stack2);

			string prefix = infixToPrefix(input);
			int res2 = EvaluatePrefix(prefix, stack2);

			cout << "Postfix Notation: " << postfix << endl;
			cout << "Postfix evaluation result: " << res1 << endl;

			cout << "Prefix Notation: " << prefix << endl;
			cout << "Prefix expression result: " << res2 << endl;




		}

		



		return 0;
	}

