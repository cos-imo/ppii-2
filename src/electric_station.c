#include <stdio.h>
#include <stdlib.h>
#include "bases.h"
#include "electric_station.h"



Bool is_occupied(Electric_station station){
    if (station.nb_cars_here >= station.nb_cars_possible){
        return FALSE;
    }
    else {
        return TRUE;
    }

}


int nb_waiting(Electric_station station){
    int difference = station.nb_cars_here - station.nb_cars_possible;
    if (difference < 0){
        return 0; // Peut-être à changer pour partie 2
    }
    else {
        return station.nb_cars_here - station.nb_cars_possible;
    }
}


int main(){
    Electric_station station;
    station.id = 1;
    station.nb_cars_here = 2;
    station.nb_cars_possible = 4;
    return 0;
}
