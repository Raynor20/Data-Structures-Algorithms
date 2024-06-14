#ifndef QUEUES_LINKEDLIST
#define QUEUES_LINKEDLIST

#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}Node, *nodePtr;

typedef struct {
	nodePtr front;
	nodePtr rear;
}Queue;

void initQueue(Queue *q);
void  enQueue(Queue *q, int data);
void deQueue(Queue *q);

int front(Queue q);
int rear(Queue q);

bool isEmpty(q);

void displayQueue(Queue q);

#endif
