#ifndef GRAPH_H
#define GRAPH_H


#include "bool.h"


// Vertices type
typedef struct Vertices{
    int id_station;
    struct Vertices *next;
} Vertices;


// Link type
typedef struct Edges{
    int id_borne_1;
    int id_borne_2;
    struct Edges *next;
} Edges;


// Graph structure
typedef struct Graph{
    Vertices *list_vertices;
    Edges *list_edges;
} Graph;



// Graph Functions
Graph* createGraph();
Bool verticesEmpty(Graph *graph);
Bool edgesEmpty(Graph *graph);
Bool graphEmpty(Graph *graph);
void addVertex(Graph *graph, int id_station);
void addVertexComplete(Graph *graph, int id_station);
void removeVertex(Graph *graph, int id_station);
Bool vertexInGraph(Graph *graph, int id_station);
Bool edgeInGraph(Graph *graph, int id_station1, int id_station2);
void addEdge(Graph *graph, int id_station1, int id_station2);
void removeEdge(Graph *graph, int id_station1, int id_station2);
int get_nb_vertices(Graph *graph);
void showGraph(Graph *graph);
void freeGraph(Graph *graph);
float distance_between(Graph graph, int id_borne1, int id_borne2);



// Graph and Trip Functions
float distance_trip(Graph *graph, Trip *trip);
Trip dijkstra(int n, Graph *graph, int range, int start, int end);


#endif
