#ifndef CIRCULAR_ARRAYs
#define CIRCULAR_ARRAY

#include <stdbool.h>

#define EMPTY 999
#define MAX 10

typedef struct {
	int data[MAX];
	int front;
	int rear;
}CircularQ;

void initQueue(CircularQ *q);
void enqueue(CircularQ *q, int item);
void dequeue(CircularQ *q);
int front(CircularQ q);
bool isEmpty(CircularQ q);
bool isFull(CircularQ q);
void display(CircularQ q);
void visualize(CircularQ q);

#endif

