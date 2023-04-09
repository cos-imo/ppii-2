#include "bases.h"
#include "electric_station.h"





// Link structure
typedef struct Link{
    int id_borne_1;
    int id_borne_2;
    float distance;
    struct Link *next;
} Link;

// Graph structure
typedef struct Graph{
    int *electric_station_id;
    Link *link_list;
} Graph;


// Trip structure
typedef struct Trip{
    int id_borne;
    struct Trip *next;
} Trip;



// Graph Functions
int get_nb_vertices(Graph *graph);
Bool are_connected(Graph graph, int a, int b);//Inutile puisque graph complet
float distance_between(Graph graph, int id_borne1, int id_borne2);
