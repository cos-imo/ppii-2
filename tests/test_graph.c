#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

void main(){
    // Create a new Graph object
    Graph my_graph;
    my_graph.electric_station_id = NULL;
    my_graph.link_list = NULL;

    // Add three vertices to the graph
    Link* link1 = (Link*)malloc(sizeof(Link));
    link1->id_borne_1 = 1;
    link1->id_borne_2 = 2;
    link1->next = NULL;

    Link* link2 = (Link*)malloc(sizeof(Link));
    link2->id_borne_1 = 2;
    link2->id_borne_2 = 3;
    link2->next = NULL;

    Link* link3 = (Link*)malloc(sizeof(Link));
    link3->id_borne_1 = 3;
    link3->id_borne_2 = 1;
    link3->next = NULL;

    link1->next = link2;
    link2->next = link3;
    my_graph.link_list = link1;

    // Display the size of the graph
    int graph_size = get_nb_vertices(&my_graph);
    printf("The graph has %d vertices.\n", graph_size);
    printf("Vertices 1 and 2 are separated by %fm.\n", distance_between(my_graph, 1, 2));
    
    
    
    // Building Trip variable
    Trip* trip1 = (Trip*)malloc(sizeof(Trip));
    trip1->id_borne = 1;
    trip1->next = NULL;

    // Create the second Trip object
    Trip* trip2 = (Trip*)malloc(sizeof(Trip));
    trip2->id_borne = 2;
    trip2->next = NULL;

    // Create the third Trip object
    Trip* trip3 = (Trip*)malloc(sizeof(Trip));
    trip3->id_borne = 3;
    trip3->next = NULL;

    // Link the Trip objects together in a chain
    trip1->next = trip2;
    trip2->next = trip3;

    // Set the trip variable to point to the first Trip object
    Trip* trip = trip1;
    printf("Distance trajet devrait être 8: %f\n", distance_trip(&my_graph, trip));

    // Free memory
    free(link1);
    free(link2);
    free(link3);

    free(trip1);
    free(trip2);
    free(trip3);



    return 0;
}