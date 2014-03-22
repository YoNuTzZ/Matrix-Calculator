#include <stdio.h>

#define STACKSIZE 100

static char stack[STACKSIZE];
static char *pStack = stack; // next free element

int c_isEmpty()
{
	if(pStack - stack == 0) {
		return 1;
	}
	return 0;
}

char c_top() 
{
	return *(pStack - 1);
}

char c_pop()
{
	if(pStack - stack > 0) {
		return *--pStack;
	}
	return '\0';
}

void c_push(char c)
{
	if(pStack - stack <= STACKSIZE) {
		*pStack++ = c;
	}
	else {
		printf("the stack is full\n");
	}
}
