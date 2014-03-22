#include <stdio.h>
#include "libMatrix/matrici.h"

#define STACKSIZE 100

static char stack[STACKSIZE];
static size_t pStack = 0; // next free element

int d_isEmpty()
{
	if(stack - pStack == stack) {
		return 1;
	}
	return 0;
}

char d_top() 
{
	return stack[pStack-1];
}

char d_pop()
{
	if(stack - pStack > 0) {
		--pStack;
		return stack[pStack];
	}
	return '\0';
}

void d_push(char a)
{
	if(pStack <= STACKSIZE) {
		stack[pStack] = a;
		pStack++;
	}
	else {
		printf("the stack is full %d\n", pStack);
	}
}
