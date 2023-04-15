#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "vehicle.h"
#include "electric_station.h"



int main(int argc, char** argv){
    int not_below;
    int max_time_at_station;
    //Vehicle *vehicle;

    // Least battery percentage
    printf("Enter least battery percentage you can go down to: ");
    scanf("%d\n", &not_below);

    // Maximum time at same station
    printf("Enter maximum time you can spend at the same station: ")
    scanf("%d\n", &max_time_at_station);


    // Updatint with parameters
    vehicle->battery_pourcentage = (100 - not_below) * vehicle->battery_pourcentage;
    vehicle->max_time = max_time_at_station;


    Trip final_trip = dijkstra()

    return EXIT_SUCCESS;
}
