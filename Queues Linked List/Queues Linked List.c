#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queues Linked List.h"

void initQueue(Queue *q) {
	q->front = q->rear = NULL;
}

void  enQueue(Queue *q, int data){
	nodePtr newNode = malloc(sizeof(Node));
	
	if(newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
	}
	if (q->front == NULL) {
		q->front = q->rear = newNode;
	}
	else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
}


void deQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    nodePtr temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int front(Queue q) {
    if (q.front != NULL) {
        return q.front->data;
    }
    printf("Queue is empty.\n");
    return -1; 
}

int rear(Queue q) {
    if (q.rear != NULL) {
        return q.rear->data;
    }
    printf("Queue is empty.\n");
    return -1;
}

bool isEmpty(Queue q) {
    return q.front == NULL;
}

void displayQueue(Queue q) {
    nodePtr temp = q.front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
