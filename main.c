#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "graph.h"

int main(){
  graphT * graph1 = malloc(sizeof(graphT));
  graph_add_vertex(&graph1, 'b');
  graph_add_vertex(&graph1, 'c');
  graph_add_vertex(&graph1, 'd');
  graph_add_vertex(&graph1, 'e');
  graph_add_vertex(&graph1, 'f');
  graph_add_vertex(&graph1, 'a');
 
 
  graph_add_edge(graph1, 'b','c');
  graph_add_edge(graph1, 'd', 'f');
  graph_add_edge(graph1, 'f', 'e');
  graph_add_edge(graph1, 'e', 'f');
  graph_add_edge(graph1, 'd', 'a');


  printEdges(graph1, 'b');
  printEdges(graph1, 'c');
  printEdges(graph1, 'd');
  printEdges(graph1, 'e');
  printEdges(graph1, 'f');
  printEdges(graph1, 'a');

  
  assert(GraphIsReachable(graph1, 'c', 'd')==0);
  assert(GraphIsReachable(graph1, 'd', 'a')==1);
  assert(GraphIsReachable(graph1, 'd', 'f')==1);
  assert(GraphIsReachable(graph1, 'd', 'e')==1);
  assert(GraphIsReachable(graph1, 'b', 'c')==1);
  assert(GraphIsReachable(graph1, 'b', 'a')==0);
  assert(GraphIsReachable(graph1, 'a', 'd')==0);
  assert(GraphIsReachable(graph1, 'f', 'a')==0);
  assert(GraphIsReachable(graph1, 'a', 'b')==0);



  
  return 0;
}
