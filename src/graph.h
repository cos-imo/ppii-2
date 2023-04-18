#ifndef GRAPH_H
#define GRAPH_H


// Boolean type
typedef enum Bool{
    FALSE,
    TRUE
} Bool;



// Vertices type
typedef struct Vertices{
    int id_station;
    struct Vertices *next;
} Vertices;


// Link type
typedef struct Link{
    int id_borne_1;
    int id_borne_2;
    struct Link *next;
} Link;


// Graph structure
typedef struct Graph{
    int *electric_station_id; // A changer en fonction du nom
    Link *link_list;
} Graph;


// Graph structure
typedef struct Graph{
    Vertices *list_vertices;
    Link *link_list;
} Graph;


// Trip structure
typedef struct Trip{
    int id_borne;
    struct Trip *next;
} Trip;




// Graph Functions
Graph* createGraph(int station_id);
Bool graphEmpty(Graph *graph);
void addVertex(Graph *graph, int id_station);
Bool vertexInGraph(Graph *graph, int id_station);
void addLink(Graph *graph, int id_station1, int id_station2);
void freeVertices(Graph *graph);
int get_nb_vertices(Graph *graph);
float distance_between(Graph graph, int id_borne1, int id_borne2);
int distance(int idBorne1, int idBorne2);
Trip dijkstra(Graph graph);


// Trip Functions
Trip* createTrip(int id_station);
Bool tripEmpty(Trip *trip);
void addStop(Trip *trip, int id_borne);
void removeStop(Trip *trip);
int get_nb_stops(Trip *trip);
void showTrip(Trip *trip);
void freeTrip(Trip *trip);


// Graph and Trip Functions
float distance_trip(Graph *graph, Trip *trip);


#endif
