#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void isEmpty(StackArrayList s) {
	return s->top == -1;
}

void isFull(StackArrayList s) {
	return s->top == MAX - 1;
}

void initStack(StackArrayList *s) {
	s->top = -1;
}
StackArrayList createStack() {
	StackArrayList stack;
	initStack(&stack);
	return stack;
}

bool stack_push(StackArrayList *s, int elem) {
		if(isFull(s)) {
			printf("Stack is Full!\n");
		}
		return false;
	}
	s->data[++(s->top)] = elem;
	return true;
}
bool stack_pop(StackArrayList *s) {
	if(isEmpty(s)) {
		printf("Stack is Empty!\n");
	}
	s->top--;
}
int stack_peek(StackArrayList s) {
	if(isEmpty(s)) {
		printf("Stack is Empty!\n");
	}
	return s->data[s->top];
}

void display(StackArrayList s) {
	StackArrayList newStack;
	initStack(&newStack);
	
	while (!isEmpty(s)) {
		push(&newStack, peek(s));
		pop(s);
	}
	while (!isEmpty(&newStack)) {
		printf("%d", peek(&newStack));
		pop(&newStack);
	}
}
void visualize(StackArrayList s) {
	if (isEmpty(s)) {
		printf("Stack is Empty!\n");
		return;
	}
	
}

int main() {
	StackArrayList s;
	initStack(&s);
	
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	visualize(&s);
	
	return 0;
}
