#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Sets UID.h"

int main () {
	Set setUnion, setIntersection;
	Set setA = newSet();
	Set setB = newSet();
	
	addElem(&setA, 1);
	addElem(&setA, 2);
	addElem(&setA, 5);
	addElem(&setB, 2);
	addElem(&setB, 3);
	addElem(&setB, 4);
	
	printf("Set A: ");
		display(setA);
	printf("Set B: ");
		display(setB);
		printf("\n");
	
	setUnion = unionSet(setA, setB);
	setIntersection = intersectionSet(setA, setB);
	
	printf("Union Set: ");
	display(setUnion);
	printf("Intersection Set: ");
	display(setIntersection);
	
	return 0;
}
