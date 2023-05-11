#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#include "test_graph.h"


int testGraph(){
    // Creating empty graph
    Graph *graph = createGraph();
    showGraph(graph);

    // Adding vertices and making the graph complete at the same time
    addVertexComplete(graph, 0);
    showGraph(graph);

    addVertexComplete(graph, 2);
    showGraph(graph);

    addVertexComplete(graph, 9);
    showGraph(graph);
    
    addVertexComplete(graph, 4);
    showGraph(graph);

    addVertexComplete(graph, 4);
    showGraph(graph);

    addVertexComplete(graph, 12);
    showGraph(graph);

    // Freeing the entire graph
    freeGraph(graph);


    return EXIT_SUCCESS;
}




int main(){
    testGraph();
    return EXIT_SUCCESS;
}
