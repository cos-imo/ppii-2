#include <stdlib.h>
#include <stdio.h>
#include "test_dijkstra.h"

int main(){
    // Creating a known graph and a list of bornes

    BorneElectrique tableauBornes[] = {
        {0, 2, 5, 48.8566, 2.3522}, // Paris
        {1, 1, 3, 49.1833, -0.3594}, // Caen
        {2, 0, 4, 45.7640, 4.8357}, // Lyon
        {3, 2, 2, 43.2965, 5.3698}, // Marseille
        {4, 1, 3, 48.1173, -1.6778}, // Rennes
        {5, 1, 2, 40.440058, -3.689336} // Madrid
    };

    Trip *trip;
    trip = dijkstra(tableauBornes, 5, 500, 1, 3); // Caen -> Marseille
    showTrip(trip); // Caen -> Paris -> Lyon -> Marseille
    freeTrip(trip);

    Trip *trip2;
    trip2 = dijkstra(tableauBornes, 5, 500, 3, 1); // Marseille -> Caen
    showTrip(trip2); // Marseille -> Lyon -> Paris -> Caen
    freeTrip(trip2);

    Trip *trip3;
    trip3 = dijkstra(tableauBornes, 5, 500, 0, 0); // Paris -> Paris
    showTrip(trip3); // Paris
    freeTrip(trip3);
    
    Trip *trip4;
    trip4 = dijkstra(tableauBornes, 6, 500, 0, 5); // Paris -> Madrid
    showTrip(trip4); // Erreur
    freeTrip(trip4);

    return EXIT_SUCCESS;
}
