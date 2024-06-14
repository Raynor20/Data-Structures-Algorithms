#include <stdio.h>
#include <stdlib.h>

#include "Queues Linked List.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    Queue q;
    initQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    printf("First 3 Values:\n");
    displayQueue(q);

    printf("\nFront: %d\n", front(q));
    printf("Rear: %d\n", rear(q));

    deQueue(&q);
    printf("\nAfter first Dequeue:\n");
    displayQueue(q);

    deQueue(&q);
    deQueue(&q);
    printf("\nAfter Dequeueing all the values: ");
    displayQueue(q);

    printf("\nQueue is empty: %s\n", isEmpty(q) ? "true" : "false");

    return 0;
}
