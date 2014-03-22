#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
		return 1;
	}
	return 0;
}

int isOperand(char c) 
{

	if(c >= 'A' && c <= 'Z') {
		return 1;
	}
	return 0;
}

int precedenceLevel(char op) 
{
	switch(op) {
		case '*':
		case '/':
			return 2;
			break;
		case '+':
		case '-':
			return 1;
			break;
		case '=':
			return 3;
	}
	return 0;
}

int hasHigherPrecedence(char op1, char op2) 
{
	return (precedenceLevel(op1) >= precedenceLevel(op2)) ? 1 : 0;
}

char *infixToPostfix(const char *exp) 
{
	char *rtn  = malloc((strlen(exp) + 1) * sizeof(char));
	if(rtn == NULL) {
		return NULL;
	}

	int j = 0;
	for(int i = 0; i < strlen(exp); i++) {
		if(isOperand(exp[i])) {
			rtn[j] = exp[i];
			j++;
		}
		else if(isOperator(exp[i])) {
			while(!c_isEmpty() && hasHigherPrecedence(c_top(), exp[i])) {
				rtn[j] = c_pop();
				j++;
			}
			// push the operator
			c_push(exp[i]);
		}
	}
	while(!c_isEmpty()) {
		rtn[j] = c_pop();
		j++;
	}
	rtn[j] = '\0';
	return rtn;
}
