#ifndef STACK_H
#define STACK_H

/**
 * @brief check if the stack is empty 
 *
 */
int d_isEmpty();
int c_isEmpty();

/**
 * @brief return the top of the stack
 *
 */
char c_top();
char d_top();

/**
 * @brief push a new value to the stack 
 *
 */
void c_push(char c);
void d_push(char a);

/**
 * @brief extract a new value from the stack 
 *
 */
char c_pop();
char d_pop();

#endif // STACK_H