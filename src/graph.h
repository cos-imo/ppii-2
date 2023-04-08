#include "bases.h"
#include "electric_station.h"



// Link type
typedef struct Link{
    int id_borne_1;
    int id_borne_2;
    float distance;
} Link;


// List type
typedef struct ListElement{
    element head;
    struct ListElement* tail;
} linked_list_int_t;


// Graph type
typedef struct Graph{
    int *electric_station_id;
    Link *link_list;
} Graph;


// Graph Functions
int get_nb_vertices(Graph graph);

