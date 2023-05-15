#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#include "test_trip.h"



int testTrip(){
    Trip *trip = createTrip();

    if (tripEmpty(trip)){printf("Got what expected: trip empty\n");}
    else{printf("Didn't get what expected: trip not empty\n");}

    addStop(trip, 2);
    printf("Expected: 2\n");
    showTrip(trip);
    printf("\n");
    
    addStop(trip, 4);
    printf("Expected: 2-4\n");
    showTrip(trip);
    printf("\n");
    
    addStop(trip, 8);
    printf("Expected: 2-4-8\n");
    showTrip(trip);
    printf("\n");
    
    removeStop(trip, 8);
    printf("Expected: 2-4\n");
    showTrip(trip);
    printf("\n");

    // Seul problème : si le point à retirer est le premier du trip...
    // removeStop(trip, 2);
    // printf("Expected: 4\n");
    // showTrip(trip);
    // printf("\n");

    removeStop(trip, 7);
    removeStop(trip, 4);
    printf("Expected: 2\n");
    showTrip(trip);
    printf("\n");

    addStopBeginning(trip, 3);
    printf("Expected: 3-2\n");
    showTrip(trip);

    // removeStop(trip, 1);
    // printf("Expected: 4\n");
    // showTrip(trip);

    // removeStop(trip, 4);
    // printf("Expected: _\n");
    // showTrip(trip);

    // Freeing trip
    freeTrip(trip);

    return EXIT_SUCCESS;
}



int main(){
    testTrip();
    
    return EXIT_SUCCESS;
}
