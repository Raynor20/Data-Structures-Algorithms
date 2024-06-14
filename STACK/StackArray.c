#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "StackArray.h"

bool isEmpty(StackArrayList *s) {
	return s->top == -1;
}

bool isFull(StackArrayList *s) {
	return s->top == MAX - 1;
}

void initStack(StackArrayList *s) {
	s->top = -1;
}
StackArrayList createStack() {
	StackArrayList s;
	initStack(&s);
	return s;
}

bool push(StackArrayList *s, int elem) {
		if(isFull(s)) {
			printf("Stack is Full!\n");
			return false;
		}
	s->data[++s->top] = elem;
	return true;
}
bool pop(StackArrayList *s) {
	if(isEmpty(s)) {
		printf("Stack is Empty!\n");
		return false;
	}
	s->top--;
	return true;
}
int peek(StackArrayList s) {
	if(isEmpty(&s)) {
		printf("Stack is Empty!\n");
		return -1;
	}
	return s.data[s.top];
}

void display(StackArrayList s) {
	StackArrayList newStack = createStack();
	
	while (!isEmpty(&s)) {
		push(&newStack, peek(s));
		pop(&s);
	}
	while (!isEmpty(&newStack)) {
		printf("%4d", peek(newStack));
		pop(&newStack);
	}
	printf("\n");
}
void visualize(StackArrayList s) {
	int i;
	if (isEmpty(&s)) {
		printf("Stack is Empty!\n");
	}
	printf("%s %7s %7s\n", "INDEX", "DATA", "TOP");
	for(i = s.top; i >= 0; i--) {
		printf("%3d %8d ", i, s.data[i]);
		if (s.data[i] == s.data[s.top]) {
			printf("%8s ", "<-- top");
		}
		printf("\n");
	}
	printf("\n");
}
StackArrayList getEven(StackArrayList *s) {
	StackArrayList newStack = createStack();
	StackArrayList tempStack = createStack();
	
	while(!isEmpty(s)) {
		int elem = peek(*s);
		pop(s);
	if (elem % 2 == 0) {
            push(&newStack, elem);
        } else {
            push(&tempStack, elem);
        }
    }

    while (!isEmpty(&tempStack)) {
        push(s, peek(tempStack));
        pop(&tempStack);
    }

    return newStack;
}
