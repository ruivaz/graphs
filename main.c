#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main(){
  graphT * graph1 = malloc(sizeof(graphT));
  graph_add_vertex(&graph1, 'b');
  graph_add_vertex(&graph1, 'c');
  graph_add_vertex(&graph1, 'l');
  graph_add_edge(&graph1, 'b','c');
  graph_add_edge(&graph1, 'c', 'l');
  graph_add_edge(&graph1, 'l', 'b');
  graph_add_edge(&graph1, 'l', 'c');
  graph_add_edge(&graph1, 'l', 'l');


  printEdges(graph1, 'b');
  printEdges(graph1, 'c');
  printEdges(graph1, 'l');

  return 0;
}
