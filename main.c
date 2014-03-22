#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "infix_to_postfix.h"
#include "libMatrix/matrici.h"

#define MAX_MATRICES 26
#define MATRIX 1
#define UNRECOGNIZED 0

#define TEMP1 '['
#define TEMP2 92

// limited implementation
int getToken(char c) 
{
	if(isOperator(c)) {
		return c;
	}
	else if(c >= 'A' && c <= 'Z') {
		return MATRIX;
	}
	else if(c == '=') {
		return c;
	}
	return UNRECOGNIZED;
}

int main() 
{
	// variables need for call to getline
	char *line        = NULL;
	size_t linelength = 0;

	// variable to store the postfix form of an experssion
	char *postfixForm;
	int token;

	// variables for handling matrices operations
	size_t lines;
	size_t rows;
	char op1  = '\0';
	char op2  = '\0';
	struct Matrix *tmp        = NULL; // coresponding letter is [ 
	struct Matrix *tmp2       = NULL; /* coresponfing letter is \ */
	struct Matrix *subHandler =	NULL;

	// the array that stores pointer to all inserted matrices
	struct Matrix *matrices[MAX_MATRICES + 2];
	memset(matrices, 0, sizeof(struct Matrix *) * (MAX_MATRICES + 2));

	while(getline(&line, &linelength, stdin) != -1) {
		postfixForm = infixToPostfix(line);

		for(int i = 0; i < strlen(postfixForm); i++) { 
			token = getToken(postfixForm[i]);
			switch(token) {
				case MATRIX:
					d_push(postfixForm[i]);
					break;
				case '+':
					op1 = d_pop();
					op2 = d_pop();

					if(op1 == TEMP1 || op2 == TEMP1) {
						add_matrices(matrices[op1 - 'A'], matrices[op2 - 'A'], &tmp2);
						distroy_matrix(matrices[TEMP1 - 'A']);
						matrices[TEMP2 - 'A'] = tmp2;
						d_push(TEMP2);
					}
					else if(op1 == TEMP2 || op2 == TEMP2) {
						add_matrices(matrices[op1 - 'A'], matrices[op2 - 'A'], &tmp);
						distroy_matrix(matrices[TEMP2 - 'A']);
						matrices[TEMP1 - 'A'] = tmp;
						d_push(TEMP1);
					}
					else {
						add_matrices(matrices[op1 - 'A'], matrices[op2 - 'A'], &tmp);
						matrices[TEMP1 - 'A'] = tmp;
						d_push(TEMP1);	
					}
					break;
				case '*':
					op1 = d_pop();
					op2 = d_pop();

					if(op1 == TEMP1 || op2 == TEMP1) {
						multiply_matrices(matrices[op1 - 'A'], matrices[op2 - 'A'], &tmp2);
						distroy_matrix(matrices[TEMP1 - 'A']);
						matrices[TEMP2 - 'A'] = tmp2;
						d_push(TEMP2);
					}
					else if(op1 == TEMP2 || op2 == TEMP2) {
						multiply_matrices(matrices[op1 - 'A'], matrices[op2 - 'A'], &tmp);
						distroy_matrix(matrices[TEMP2 - 'A']);
						matrices[TEMP1 - 'A'] = tmp;
						d_push(TEMP1);
					}
					else {
						multiply_matrices(matrices[op1 - 'A'], matrices[op2 - 'A'], &tmp);
						matrices[TEMP1 - 'A'] = tmp;
						d_push(TEMP1);	
					}
					break;
				case '-':
					op1 = d_pop();
					op2 = d_pop();
					subHandler = create_matrix(matrices[op1 - 'A']->lines, matrices[op1 - 'A']->columns);
					copy_matrix(matrices[op1 - 'A'], &subHandler);
					multiply_matrix_with_scalar(subHandler, -1);

					if(op1 == TEMP1 || op2 == TEMP1) {
						add_matrices(subHandler, matrices[op2 - 'A'], &tmp2);
						distroy_matrix(matrices[TEMP1 - 'A']);
						matrices[TEMP2 - 'A'] = tmp2;
						d_push(TEMP2);
					}
					else if(op1 == TEMP2 || op2 == TEMP2) {
						add_matrices(subHandler, matrices[op2 - 'A'], &tmp);
						distroy_matrix(matrices[TEMP2 - 'A']);
						matrices[TEMP1 - 'A'] = tmp;
						d_push(TEMP1);
					}
					else {
						add_matrices(subHandler, matrices[op2 - 'A'], &tmp);
						matrices[TEMP1 - 'A'] = tmp;
						d_push(TEMP1);	
					}
					distroy_matrix(subHandler);
					break;
				case '=':
					op1 = d_top();

					if(op1 >= 'A' && op1 <= 'Z') { 
						// read de sizez of a matrix
						printf("introdu numaruld de linii: ");
						scanf("%u", &lines);

						printf("introdu nuamruld e coloane: ");
						scanf("%u", &rows);

						if(matrices[op1 - 'A'] != NULL) {
							distroy_matrix(matrices[op1 - 'A']);
						}
						tmp = create_matrix(lines, rows);
						read_matrix(tmp);
						matrices[op1 - 'A'] = tmp;
						
						// get rid of the matrix symbol
						d_pop();
					}
					else {
						printf("se pot salva maxim 26 de matrici din intervalul A-Z");
					}
					break;
			}
		}
		if(token != '=') {
			print_matrix(matrices[d_pop() - 'A']);
		}
	}
	free(line);
	
	return 0;
}