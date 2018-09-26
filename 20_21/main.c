#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(void) {

    graph g = graph_new(5);

    graph_free(g);

    return EXIT_SUCCESS;
}

    
