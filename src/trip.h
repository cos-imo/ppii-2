
#ifndef TRIP_H
#define TRIP_H


#include "bool.h"

// Trip structure
typedef struct Trip{
    int id_borne; // Place de la borne dans le tableau de bornes
    struct Trip *next;
} Trip;



// Trip Functions
Trip* createTrip(void);
Bool tripEmpty(Trip *trip);
Bool stopInTrip(Trip *trip, int id_station);
void addStop(Trip *trip, int id_station);
void removeStop(Trip *trip, int id_station);
int get_nb_stops(Trip *trip);
void showTrip(Trip *trip);
void freeTrip(Trip *trip);

#endif
