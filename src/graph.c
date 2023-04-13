#include <stdio.h>
#include <stdlib.h>

#include "graph.h"



// Function to get the number of vertices in the graph
int get_nb_vertices(Graph *graph) {
    int size = 0;
    Link *current_link = graph->link_list;

    while (current_link != NULL) {
        size++;
        current_link = current_link->next;
    }

    return size;
}



// Function to return the distance between two electric stations
float distance_between(Graph graph, int id_station1, int id_station2){
    Link *current_link = graph.link_list;
    
    while (current_link != NULL){
        if ((current_link->id_borne_1 == id_station1 && current_link->id_borne_2 == id_station2) || (current_link->id_borne_1 == id_station2 && current_link->id_borne_2 == id_station1)){
            // We identified the two stations
            return distance(id_station1, id_station2);
        }
        else{
            current_link = current_link->next;
        }
    }

    // Final check on last element
    if ((current_link->id_borne_1 == id_station1 && current_link->id_borne_2 == id_station2) || (current_link->id_borne_1 == id_station2 && current_link->id_borne_2 == id_station1)){
        return distance(id_station1, id_station2);
    }
    return -1.;
}


float distance_trip(Graph *graph, Trip *trip){
    int d = 0;
    
    Trip *current_station = trip;
    Trip *trip_tail = trip->next;

    while (trip_tail != NULL) {
        int a = current_station->id_borne;
        int b = trip_tail->id_borne;
        
        d += distance_between(*graph, a, b);
        
        // Moving to next stop
        current_station = trip_tail;
        trip_tail = trip_tail->next;
    }


    return d;
}


// Function computing Dijkstra Algorithm
Trip dijkstra(Graph graph);
