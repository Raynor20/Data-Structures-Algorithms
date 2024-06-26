#include <stdio.h>
#include "fcfs.h"

int main(void) {
    Queue queue = createQueue();
    populateQueue(&queue);
    scheduleFCFS(&queue);
    displayQueue(queue);
    return 0;
}

