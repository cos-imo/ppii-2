#include <stdlib.h>
#include <stdio.h>
#include "../src/dijkstra.h"
#include "test_dijkstra.h"

int main(void){
    // Creating a known graph and a list of bornes

    BorneElectrique tableauBornes[] = {
        {1, 2, 5, 48.8566, 2.3522},
        {2, 1, 3, 49.1833, -0.3594},
        {3, 0, 4, 45.7640, 4.8357},
        {4, 2, 2, 43.2965, 5.3698},
        {5, 1, 3, 48.1173, -1.6778}
    };

    Trip *trip;
    trip = dijkstra(tableauBornes, 5, 500.0, 1, 2);
    showTrip(trip);
    freeTrip(trip);
    return EXIT_SUCCESS;
}
