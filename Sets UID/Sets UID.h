#ifndef Sets_UID
#define Sets_UID

#include <stdbool.h>
#define MAX 20

typedef struct {
	bool elems[MAX];
	int count;
} Set;

Set newSet();
bool addElem(Set *s, int item);
bool deleteElem(Set *s, int item);
void display(Set s);
Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);


#endif
