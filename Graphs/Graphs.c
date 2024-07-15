#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"

struct Node* newNode(int dest) {
	int i;
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->vertex = dest;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int numVertices) {
	int i;
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;
  graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

  for (i = 0; i < numVertices; ++i) {
    graph->array[i].head = NULL;
  }

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct Node* newNodeDest = newNode(dest);
  newNodeDest->next = graph->array[src].head;
  graph->array[src].head = newNodeDest;

  struct Node* newNodeSrc = newNode(src);
  newNodeSrc->next = graph->array[dest].head;
  graph->array[dest].head = newNodeSrc;
}

void printGraph(struct Graph* graph) {
	int i;
  for (i = 0; i < graph->numVertices; ++i) {
    printf("%d -> ", i);
    struct Node* temp = graph->array[i].head;
    while (temp) {
      printf("%d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int** createAdjacencyMatrix(struct Graph* graph) {
	int i, j;
  int** matrix = (int**)malloc(graph->numVertices * sizeof(int*));
  for (i = 0; i < graph->numVertices; ++i) {
    matrix[i] = (int*)malloc(graph->numVertices * sizeof(int));
    for (j = 0; j < graph->numVertices; ++j) {
      matrix[i][j] = 0;
    }
  }

  for (i = 0; i < graph->numVertices; ++i) {
    struct Node* temp = graph->array[i].head;
    while (temp) {
      matrix[i][temp->vertex] = 1;
      temp = temp->next;
    }
  }

  return matrix;
}

void printAdjacencyMatrix(int** matrix, int numVertices) {
	int i, j;
  for (i = 0; i < numVertices; ++i) {
    for (j = 0; j < numVertices; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
