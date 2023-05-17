#include <stdio.h>
#include <stdlib.h>

#include "coordinates.h"


void show_coordinates(Trip *trip, BorneElectrique tableauBornes[]){
    // Format de sortie : lat1,long1+lat2,long2+lat3,long3
    Trip *current = trip;

    while (current->next != NULL){
        printf("%f,", tableauBornes[current->id_borne].latitude);
        printf("%f+", tableauBornes[current->id_borne].longitude);

        current = current->next;
    }

    printf("%f,", tableauBornes[current->id_borne].latitude);
    printf("%f\n", tableauBornes[current->id_borne].longitude);
}



int main(void){
    Trip* trip = createTrip();
    addStop(trip, 0);
    addStop(trip, 1);
    addStop(trip, 4);
    // showTrip(trip);
    
    BorneElectrique tableauBornes[] = {
        {0, 2, 5, 48.8566, 2.3522}, // Paris
        {1, 1, 3, 49.1833, -0.3594}, // Caen
        {2, 0, 4, 45.7640, 4.8357}, // Lyon
        {3, 2, 2, 43.2965, 5.3698}, // Marseille
        {4, 1, 3, 48.1173, -1.6778}, // Rennes
        {5, 1, 2, 40.440058, -3.689336} // Madrid
    };

    show_coordinates(trip, tableauBornes);
    freeTrip(trip);
}
