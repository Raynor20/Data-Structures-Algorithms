#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueCircularArray.h"

void initQueue(CircularQ *q) {
	q->front = 1;
	q->rear = 0;
	int i;
	for(i=0; i<MAX; i++){
		q->data[i]= EMPTY;
	}
}

void enqueue(CircularQ *q, int item) {
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = item;
	}
}

void dequeue(CircularQ *q){
	if(!isEmpty(*q)){
		q->data[q->front] = EMPTY;
		q->front = (q->front +1) % MAX;
	}
	
}

int front(CircularQ q){
	if(!isEmpty(q)){
		return q.data[q.front];
	}
	return EMPTY;
}

bool isEmpty(CircularQ q){
	return (q.rear + 1) % MAX == q.front;
}

bool isFull(CircularQ q){
	return (q.rear + 2) % MAX == q.front;
}

void display(CircularQ q){
	int i;
	printf("Queues:\n");
	for(i=0; i<MAX; i++){
		if(q.data[i] != EMPTY){
			printf("%d\n", q.data[i]);
		}else{
			printf("");
		}
	}
}

void visualize(CircularQ q){
	printf("%5s | %5s | %5s\n", "INDEX", "VALUE", "STATUS");
	printf("----------------------\n");
	int i;
	for(i=0; i<MAX; i++){
		printf("%5d | ", i);
		if(q.data[i] != EMPTY){
			printf("%5d | ", q.data[i]);
		}else{
			printf("%5s | ", " ");
		}
			if(i == q.front) {
				printf("Front");
			} if(i == q.rear) {
				printf("Rear");
			}
			printf("\n");
	}
	printf("----------------------\n\n");
}
