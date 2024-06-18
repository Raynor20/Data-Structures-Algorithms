#include <stdio.h>
#include <stdlib.h>
#include "QueueCircularArray.h"

int main() {
	CircularQ q;
	initQueue(&q);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	
  //dequeue(&q);
  	visualize(q);
	display(q);
	
	return 0;
}
