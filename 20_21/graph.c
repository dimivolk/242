#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"
#include "graph.h"

typedef struct vertex *vertex;

struct vertex {
    int predecessor;
    int distance;
    state_t state;
    int finish;
};

struct graphrec{
    int size;
    int **edges;
    vertex *vertices;
};

graph graph_new(int s) {
    int i, j;
    graph result = emalloc(sizeof *result);
    result->size = s;
    result->edges = emalloc(result->size * sizeof result->edges[0]);
    result->vertices = emalloc(result->size * sizeof result->vertices[0]);

    for (i = 0; i < result->size; i++) {
        result->edges[i] = emalloc(result->size * sizeof result->edges[0]);
        for(j = 0; j < result->size; j++) {
            result->edges[i][j] = 0;
        }
    }
    return result;
}
graph graph_free(graph g) {
    int i;
    for(i = 0; i < g->size; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g->vertices);
    free(g);
    return g;
}

void graph_add_edge_directed(graph g, int u, int v) {
    g->edges[u][v] = 1;
}

void graph_print(graph g) {
    int i, j;
    printf("adjacency list: ");
    for(i = 0; i < g->size; i++) {
        for(j = 0; j < g->size; j++) {
            printf("%d | %ls %d\n", i, g->edges[i], g->edges[i][j]);
        }
        printf("\n");
        printf("vertex distance pred\n");
        for(i = 0; i < g->size; i++) {
            printf("%d   %d   %d\n ", i, g->vertices[i].distance, g->vertices[i].predecessor);
        }  
    
    }
}

void graph_bfs(graph g) {
    

/* void graph_add_edge_undirected(graph g, int u, int v) { */

/* } */

