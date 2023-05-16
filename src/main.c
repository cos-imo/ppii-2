#include <stdio.h>
#include <stdlib.h>


#include "main.h"
// #include "trip.h"
// #include "borne.h"
// #include "vehicle.h"
// #include "graph.h"



int main(int argc, char** argv){
    // Arguments argv : least battery percentage, max minutes
    // Nombre d'arguments varie : mode 1 renvoie tous les véhicules, mode 2 renvoie le Trip lat1,long1+lat2,long2+...

    int not_below;
    int max_minutes_at_station;
    //Vehicle *vehicle;

    // Least battery percentage
    printf("Enter least battery percentage you can go down to: ");
    scanf("%d", &not_below);

    // Maximum time at same station
    printf("Enter maximum number of minutes you can spend at the same station: ");
    scanf("%d", &max_minutes_at_station);


    // Updatint with parameters
    // vehicle->battery_pourcentage = (100 - not_below) * vehicle->battery_pourcentage;
    // vehicle->max_time = max_time_at_station;

    // // Computing final trip
    // Trip final_trip = dijkstra(sta);


    return EXIT_SUCCESS;
}
