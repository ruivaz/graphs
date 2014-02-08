#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/* *
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

 * */

vertexT *graph_get_vertex(graphT *graph, char value);

void graph_add_vertex(graphT **graph, char element) {
  vertexT *new_vertex = malloc(sizeof(vertexT));
  new_vertex->element = element;
  if((*graph)->vertices==NULL)
     new_vertex->next = NULL;
  else
     new_vertex->next = (*graph)->vertices;

  (*graph)->vertices = new_vertex;
}

void graph_add_edge(graphT *graph, char source, char dest) {
  vertexT *dst_vertex = graph_get_vertex(graph, dest);
  vertexT *src_vertex = graph_get_vertex(graph, source);
  edgeT *new_edge = malloc(sizeof(edgeT)); 
  new_edge->connectsTo = dst_vertex;
  if(src_vertex->edges==NULL)
    new_edge->next=NULL;
  else
    new_edge->next=src_vertex->edges;  
  src_vertex->edges=new_edge;
}

vertexT *graph_get_vertex(graphT *graph, char element) {
  vertexT *temp = graph->vertices;
  while(temp!=NULL) {
    if(temp->element==element) {
      return temp;
    }
    temp=temp->next; 
  }
  return NULL;   
}

void printEdges(graphT *graph, char element) {

  printf("Element %c\n", element);

  vertexT *temp = graph_get_vertex(graph, element);
  if(temp==NULL){
    printf("There's no Vertex with %c Element\n", element);
    exit(-1);
  }
  edgeT *edge = temp->edges;
  while(edge!=NULL){
    printf("Connected to %c \n", edge->connectsTo->element);
    edge=edge->next;
 }
  
}

int GraphIsReachableRecursive(vertexT *source, char destination){
  //If this element is NULL or was visited before let's return to parent 
  if(source==NULL || source->visited==1)
    return 0;
  //Test if this is the element we are looking for
  if(source->element == destination)
    return 1;

  source->visited=1;
  edgeT *edge = source->edges;
  while(edge!=NULL){
    if(GraphIsReachableRecursive(edge->connectsTo, destination)==1)
      return 1;
    edge=edge->next;
  }
}

int GraphIsReachable(graphT *graph, char source, char destination){  
  //Set all the Vertex to not visited
  vertexT *temp = graph->vertices;
  while(temp!=NULL){
    temp->visited=0;
    temp=temp->next;
  }
  vertexT *temp1 = graph_get_vertex(graph, source);
  return GraphIsReachableRecursive(temp1, destination);
}


