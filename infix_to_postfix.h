#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

/**
 * @brief Checks if a charachter is an operator
 * 
 * @param c the parameter to be checked
 * @return 1 if is an operator otherwise 0
 */
int isOperator(char c);

/**
 * @brief Checks if a charachter is an valid operand
 * 
 * @param c the charachter to be checked
 *
 * @return 1 if it is an operand or 0 otherwise
 */
int isOperand(char c); 

/**
 * @brief Returns the level of precedence of an operator
 *
 * @param op The operatot that we want to find level of precedence of
 *
 * @return 1 if is an + or -, 2 for * or / or 0 otherwise
 */
int precedenceLevel(char op);

/**
 * @brief Checks if an operator has higher precedence than other
 *
 * @param op1 The first opeartor
 * @param op2 The second operator
 *
 * @return 1 if op1 has higher precedence than op2
 */
int hasHigherPrecedence(char op1, char op2); 

/**
 * @brief Returns the postfix for of a string with infix notation
 *
 * @param exp The string that we want to return the postfix represenatation
 *
 * @return Returns a pointer to the string that contains the postfix representation of exp
 */
char *infixToPostfix(const char *exp); 

#endif // INFIX_TO_POSTFIX_H