#ifndef BORNE_H
#define BORNE_H

#include "trip.h"

#define RAYON_TERRE 6371.0 // Rayon de la Terre
#ifndef M_PI
#define M_PI 3.141593
#endif

// Structure BorneElectrique
typedef struct {
    int id;
    int nbVoitures;
    int nbVoituresMax;
    double latitude;
    double longitude;
} BorneElectrique;



// Borne Functions
int distance(BorneElectrique tableauBornes[], int id1, int id2);
BorneElectrique trouverBorneLaPlusProche(BorneElectrique tableauBornes[], int nbBornes);
float distance_trip(Trip *trip, BorneElectrique tableauBornes[]);
BorneElectrique* *init_bornes();

#endif
