#include<stdio.h>


typedef struct vertexTag {
  char element;
  int visited;
  struct edgeTag *edges;
  struct vertexTag *next;
} vertexT;

typedef struct edgeTag {
  struct vertexTag *connectsTo;
  struct edgeTag *next;
} edgeT;

typedef struct graphTag {
  struct vertexTag *vertices;
} graphT;


void graph_add_vertex(graphT **graph, char element);
void graph_add_edge(graphT **graph, char dest, char source);
int GraphIsReachable(graphT *graph, char dest, char source);
