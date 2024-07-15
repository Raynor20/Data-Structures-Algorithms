#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"

int main() {
	int i;
  int numVertices = 5;
  struct Graph* graph = createGraph(numVertices);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  printf("Adjacency List Representation:\n");
  printGraph(graph);

  int** matrix = createAdjacencyMatrix(graph);
  printf("\nAdjacency Matrix Representation:\n");
  printAdjacencyMatrix(matrix, numVertices);

  for (i = 0; i < numVertices; ++i) {
	free(matrix[i]);
  }
  free(matrix);
  free(graph->array);
  free(graph);

  return 0;
}
