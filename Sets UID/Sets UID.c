#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Sets UID.h"

Set newSet() {
	int i;
	Set s;
	
	s.count = 0;
	for(i=0; i<MAX; i++) {
		s.elems[i] = 0;
	}
	return s;
}

bool addElem(Set *s, int item){
	s->elems[item] = 1;
	s->count++;
	return true;
}

bool deleteElem(Set *s, int item){
	s->elems[item] = 0;
	s->count--;
	return true;
}

void display(Set s){
	int i;
	for(i=0; i<MAX; i++){
		if(s.elems[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

Set unionSet(Set a, Set b){
	Set res = newSet();
	int i;
	for(i=0; i<MAX; i++) {
		if(a.elems[i] || b.elems[i]){
			addElem(&res, i);
		}
	}
	return res;
}

Set intersectionSet(Set a, Set b) {
	Set res = newSet();
	int i;
	for(i=0; i<MAX; i++) {
		if(a.elems[i] && b.elems[i]) {
			addElem(&res, i);
		}
	}
	return res;
}
