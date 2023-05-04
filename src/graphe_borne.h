#ifndef GRAPH_H
#define GRAPH_H
#include "borne.c"

// Boolean type
typedef enum Bool{
    FALSE,
    TRUE
} Bool;



// Vertices type
typedef struct Vertices{
    BorneElectrique *borne;
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


// Trip structure
typedef struct Trip{
    BorneElectrique *borne;
    struct Trip *next;
} Trip;




// Graph Functions
Graph* createGraph();
Bool verticesEmpty(Graph *graph);
Bool edgesEmpty(Graph *graph);
Bool graphEmpty(Graph *graph);
void addVertex(Graph *graph, int id_station, int nb_voitures, int nb_voitures_max, double latitude, double longitude);
void addVertexComplete(Graph *graph, int id_station, int nb_voitures, int nb_voitures_max, double latitude, double longitude);
void removeVertex(Graph *graph, int id_station);
Bool vertexInGraph(Graph *graph, int id_station);
Bool edgeInGraph(Graph *graph, int id_station1, int id_station2);
void addEdge(Graph *graph, int id_station1, int id_station2);
void removeEdge(Graph *graph, int id_station1, int id_station2);
int get_nb_vertices(Graph *graph);
void showGraph(Graph *graph);
void freeGraph(Graph *graph);
float distance_between(Graph graph, int id_borne1, int id_borne2);
int distance(int idBorne1, int idBorne2);
Trip dijkstra(Graph graph);


// Trip Functions
Trip* createTrip(int id_station);
Bool tripEmpty(Trip *trip);
Bool stopInTrip(Trip *trip, int id_station);
void addStop(Trip *trip, int id_station);
void removeStop(Trip *trip, int id_station);
int get_nb_stops(Trip *trip);
void showTrip(Trip *trip);
void freeTrip(Trip *trip);


// Graph and Trip Functions
float distance_trip(Graph *graph, Trip *trip);


#endif
