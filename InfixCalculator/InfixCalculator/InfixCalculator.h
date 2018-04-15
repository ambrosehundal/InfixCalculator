#pragma once

#ifndef INFIX_CALCULATOR_H
#define INFIX_CALCULATOR_H

#include "stdafx.h"
#include <string>
#include "Stack.h"

using namespace std;


class InfixCalculator {

public:

	bool IsOperator(char c);
	bool IsOperand(char c);
	int OperatorWeight(char op);

	int HigherPrecedence(char op1, char op2);

	string infixToPostfix(string s, Stack<char>* charPtr);
	int EvaluatePostfix(string postfix);

	string infixToPrefix(string expression);
	int EvaluatePrefix(string prefix);
	int PerformOperation(char operation, int op1, int op2);

};

#endif