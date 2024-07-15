#ifndef GRAPH_H
#define GRAPH_H

struct Node {
  int vertex;
  struct Node* next;
};

struct AdjList {
  struct Node* head;
};

struct Graph {
  int numVertices;
  struct AdjList* array;
};

struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
int** createAdjacencyMatrix(struct Graph* graph);
void printAdjacencyMatrix(int** matrix, int numVertices);

#endif 
