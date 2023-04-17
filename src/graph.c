#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
//#include "electric_station.h"



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



// Function to create an empty trip
Trip* createTrip(int id_station){
    Trip *trip = (Trip*)malloc(sizeof(Trip));
    trip->id_borne = id_station;
    trip->next = NULL;

    return trip;
}


// Function to tell if a trip is empty
Bool isEmpty(Trip *trip){
    if (trip == NULL){
        return TRUE;
    }
    else {
        return FALSE;
    };
}


// Function to add an electric station to a trip
void addStop(Trip *trip, int id_station){
    Trip *new = (Trip*)malloc(sizeof(Trip));
    new->id_borne = id_station;
    new->next = NULL;

    Trip *current = trip;
    while (current->next != NULL){
        current = current->next;
    }
    
    current->next = new;
}


// Function to remove last step of a trip
void removeStop(Trip *trip){
    Trip *predecessor = trip;
    Trip *current = trip->next;
    while (current->next != NULL){
        predecessor = predecessor->next;
        current = current->next;
    }

    // predecessor.next = current AND current.next = NULL
    predecessor->next = NULL;
    free(current);
}


// Function returning the number of stops in a trip
int get_nb_stops(Trip *trip){
    int res = 0;
    Trip *current = trip;
    while (current != NULL){
        current = current->next;
        res++;
    }

    return res;
}


// Function to show all vertices of a trip
void showTrip(Trip *trip){
    printf("Trip: ");
    Trip *current = trip;
    while (current != NULL){
        printf("%d", current->id_borne);
        current = current->next;
        if (current != NULL){
            printf("-");
        }
    }
    printf("\n");
}


// Function to free memory of a trip
void freeTrip(Trip *trip){
    Trip *current = trip;
    Trip *to_come = trip->next;
    while (to_come != NULL){
        current->next = NULL;
        free(current);
        current = to_come;
        to_come = to_come->next;
    }
    free(current); // Freeing last element
}


// Function to compute the total distance of a trip
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


// Function to compute the distance between 2 vertices
int distance(int idBorne1, int idBorne2){
    // A toi Thomas
    return idBorne1 + idBorne2; // Pour pas avoir d'erreur...
}


// Function computing Dijkstra Algorithm
Trip dijkstra(Graph graph);



int main(){
    return EXIT_SUCCESS;
}
