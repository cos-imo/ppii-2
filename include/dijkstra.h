#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include <string.h>

#include "trip.h"
#include "borne.h"
#include "coordinates.h"

Trip *dijkstra(BorneElectrique *tableauBornes, int n, int range, int start, int end);
char* tripToList(Trip *trip, BorneElectrique *tableauBornes);

#endif // DIJKSTRA_H
