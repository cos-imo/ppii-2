#include <stdlib.h>
#include <stdio.h>
#include "../src/borne.c"
#include "../src/graphe_borne.c"

int main(){
    // Creating a known graph and a list of bornes
    Graph *graph = createGraph();
    addVertex(graph, 1, 0, 10, 1.0, 1.0);
    addVertex(graph, 2, 0, 10, 2.0, 2.0);
    addVertex(graph, 3, 0, 10, 1.0, 2.0);
    addVertex(graph, 4, 0, 10, 2.0, 1.0);
    showGraph(graph);
    printf("\n\n");
    freeGraph(graph);



}