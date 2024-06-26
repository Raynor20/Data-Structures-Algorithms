#ifndef FCFS_H
#define FCFS_H

typedef struct {
    char id;
    int burst;
    int arrival;
} Process;

typedef struct node {
    Process process;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
} Queue;

Queue createQueue();
void initQueue(Queue *q);
void populateQueue(Queue *q);

void scheduleFCFS(Queue *q);

int enqueue(Queue *q, Process p);
NodePtr front(Queue q);
int dequeue(Queue *q);
NodePtr rear(Queue q);

int isEmpty(Queue q);

void displayQueue(Queue q);

#endif

