#include <stdio.h>
#include <stdlib.h>
#include "fcfs.h"

Queue createQueue() {
    Queue q;
    initQueue(&q);
    return q;
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

void populateQueue(Queue *q) {
    int numProcesses, i;
    Process p;
    printf("Enter Number of Processes: ");
    scanf("%d", &numProcesses);
    for (i = 0; i < numProcesses; i++) {
        printf("Process %c\n", 'A' + i); 
        p.id = 'A' + i;
        printf("Burst Time: ");
        scanf("%d", &p.burst);
        printf("Arrival Time: ");
        scanf("%d", &p.arrival);
        enqueue(q, p);
        printf("\n");
    }
}

void scheduleFCFS(Queue *q) {
    Queue temp = createQueue();
    NodePtr currNode;
    while (!isEmpty(*q)) {
        currNode = front(*q);
        enqueue(&temp, currNode->process);
        dequeue(q);
    }
    *q = temp;
}

void displayQueue(Queue q) {
    if (!isEmpty(q)) {
        printf("FCFS Queue Visualization\n");
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
        printf("| Process ID | Burst Time | Arrival Time | Execution Time | Waiting Time | Turnaround Time |\n");
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");

        int count = 0, currentTime = 0, execTime, waitTime, turnTime, totalWait = 0, totalTurn = 0;
        NodePtr temp = q.front;

        while (temp != NULL) {
            Process p = temp->process;

            if (currentTime < p.arrival) {
                currentTime = p.arrival;
            }

            waitTime = currentTime - p.arrival;
            execTime = currentTime;
            turnTime = execTime + p.burst;
            currentTime += p.burst;

            totalWait += waitTime;
            totalTurn += turnTime;

            printf("| %-10c | %-10d | %-12d | %-14d | %-12d | %-15d |\n", p.id, 
                                                                        p.burst, 
                                                                        p.arrival, 
                                                                        execTime, 
                                                                        waitTime, 
                                                                        turnTime);

            temp = temp->next;
            count++;
        }

        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
        printf("| %-10s | %-10s | %-12s | %-14s | %-12d | %-15d |\n", "", "", "", "Total ", totalWait, totalTurn);
        printf("| %-10s | %-10s | %-12s | %-14s | %-12.2f | %-15.2f |\n", "", "", "", "Average ", (float)totalWait / count, (float)totalTurn / count);
        printf("+------------+------------+--------------+----------------+--------------+-----------------+\n");
    } else {
        printf("FCFS Queue is Empty!\n");
    }
}

int enqueue(Queue *q, Process p) {
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    if (temp != NULL) {
        temp->process = p;
        temp->next = NULL;
        if (isEmpty(*q)) {
            q->front = q->rear = temp;
        } else {
            q->rear->next = temp;
            q->rear = temp;
        }
        return 1;
    }
    return 0;
}

NodePtr front(Queue q) {
    return (!isEmpty(q)) ? q.front : NULL;
}

int dequeue(Queue *q) {
    if (!isEmpty(*q)) {
        NodePtr temp = q->front;
        q->front = temp->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
        return 1;
    }
    return 0;
}

NodePtr rear(Queue q) {
    return (!isEmpty(q)) ? q.rear : NULL;
}

int isEmpty(Queue q) {
    return (q.front == NULL && q.rear == NULL);
}

