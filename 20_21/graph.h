#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

typedef enum {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;
typedef struct graphrec *graph;

extern graph graph_new();
extern graph graph_free(graph g);
extern void  graph_print(graph g);
extern void  graph_add_edge_directed(graph g, int u, int v);

#endif
