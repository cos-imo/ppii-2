#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include "trip.h"
#include "borne.h"

Trip *dijkstra(BorneElectrique *tableauBornes, int n, int range, int start, int end);

#endif // DIJKSTRA_H
