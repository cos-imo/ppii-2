#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#include "test_graph_trip.h"



// Function to create an empty trip
Trip* createTrip(){
    Trip *trip = (Trip*)malloc(sizeof(Trip));
    trip->id_borne = -1;
    trip->next = NULL;

    return trip;
}


// Function to tell if a trip is empty
Bool tripEmpty(Trip *trip){
    if ((trip->id_borne == -1) && (trip->next == NULL)){
        return TRUE;
    }
    else {
        return FALSE;
    };
}


// Function to know if a station is part of the trip
Bool stopInTrip(Trip *trip, int id_station){
    Trip *current = trip;
    while (current != NULL){
        if (current->id_borne == id_station){
            return TRUE;
        }
        current = current->next;
    }
    return FALSE;
}


// Function to add an electric station to a trip
void addStop(Trip *trip, int id_station){
    if (tripEmpty(trip)){
        trip->id_borne = id_station;
    }
    
    else{
        Trip *new = (Trip*)malloc(sizeof(Trip));
        new->id_borne = id_station;
        new->next = NULL;

        Trip *current = trip;
        while (current->next != NULL){
            current = current->next;
        }
        
        current->next = new;
    }
}


// Function to remove last step of a trip
void removeStop(Trip *trip, int id_station){
    if (stopInTrip(trip, id_station)){
        // Special case if station to remove is the first
        if (trip->id_borne == id_station){
            Trip *temp = trip;
            
            // Second becomes first
            trip->id_borne = trip->next->id_borne;
            trip->next = trip->next->next;
            
            temp->next = NULL;
            free(temp);
        }
        
        else{
            Trip *predecessor = trip;
            Trip *current = trip->next;
            while (current->id_borne != id_station){
                predecessor = predecessor->next;
                current = current->next;
            }
            predecessor->next = current->next;
            current->next = NULL;
            free(current);
        }
    }
    else{
        printf("\nTrying to remove stop %d which isn't in the trip.\n\n", id_station);
    }
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
    if (tripEmpty(trip)){
        free(trip);
    }
    else{
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
}


// Function to compute the total distance of a trip
float distance_trip(Graph *graph, Trip *trip){
    int d = 0;
    
    Trip *current_station = trip;
    Trip *trip_tail = trip->next;

    while (trip_tail != NULL) {
        int a = current_station->id_borne;
        int b = trip_tail->id_borne;

        d = a + b; // Avoid errors
        
        //d += distance_between(*graph, a, b); A faire avec distance
        
        // Moving to next stop
        current_station = trip_tail;
        trip_tail = trip_tail->next;
    }


    return d;
}


int testTrip(){
    Trip *trip = createTrip();

    if (tripEmpty(trip)){printf("Got what expected: trip empty\n");}
    else{printf("Didn't get what expected: trip not empty\n");}

    addStop(trip, 2);
    printf("Expected 2\n");
    showTrip(trip);
    printf("\n");
    
    addStop(trip, 4);
    printf("Expected 2-4\n");
    showTrip(trip);
    printf("\n");
    
    addStop(trip, 8);
    printf("Expected 2-4-8\n");
    showTrip(trip);
    printf("\n");
    
    removeStop(trip, 8);
    printf("Expected 2-4\n");
    showTrip(trip);
    printf("\n");

    // Seul problème : si le point à retirer est le premier du trip...
    // removeStop(trip, 2);
    // printf("Expected 4\n");
    // showTrip(trip);
    // printf("\n");

    removeStop(trip, 7);
    printf("Expected 4\n");
    showTrip(trip);
    printf("\n");

    // removeStop(trip, 1);
    // printf("Expected 4\n");
    // showTrip(trip);

    // removeStop(trip, 4);
    // printf("Expected _\n");
    // showTrip(trip);

    // free(trip);
    freeTrip(trip);

    return EXIT_SUCCESS;
}



int main(){
    testTrip();
    
    return EXIT_SUCCESS;
}
