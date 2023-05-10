#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "borne.h"
#include "trip.h"


// Distance entre deux coordonnées GPS (pas touche au nom, Kieran)
int distance(int id1, int id2, BorneElectrique tableauBornes[]) {
    BorneElectrique borne1 = tableauBornes[id1];
    BorneElectrique borne2 = tableauBornes[id2];
    
    double lat1Rad = borne1.latitude * M_PI / 180.0;
    double long1Rad = borne1.longitude * M_PI / 180.0;
    double lat2Rad = borne2.latitude * M_PI / 180.0;
    double long2Rad = borne2.longitude * M_PI / 180.0;
    
    double deltaLong = long2Rad - long1Rad;
    
    double distance = acos(sin(lat1Rad)*sin(lat2Rad) + cos(lat1Rad)*cos(lat2Rad)*cos(deltaLong)) * RAYON_TERRE;
    
    return (int) round(distance);
}


// Fonction qui trouve la borne la plus proche de coordonnées GPS données
BorneElectrique trouverBorneLaPlusProche(BorneElectrique tableauBornes[], int nbBornes) {
    double distanceMin = INFINITY; // Initialisation de la distance minimale à l'infini
    BorneElectrique borneLaPlusProche; // Initialisation de la borne la plus proche
    
    for (int i = 2; i < nbBornes; i++) {
        double d = distance(0, i, tableauBornes);
        if (d < distanceMin) {
            distanceMin = d;
            borneLaPlusProche = tableauBornes[i];
        }
    }
    
    return borneLaPlusProche;
}


//Function to compute the total distance of a trip
float distance_trip(Trip *trip, BorneElectrique tableauBornes[]){
    int total_distance= 0;
    
    Trip *current_station = trip;
    Trip *trip_tail = trip->next;

    while (trip_tail != NULL) {
        int a = current_station->id_borne;
        int b = trip_tail->id_borne;

       total_distance += distance(a, b, tableauBornes);
        
        // Moving to next stop
        current_station = trip_tail;
        trip_tail = trip_tail->next;
    }

    return total_distance;
}













// int main() {
//     // Test pour un tableau de bornes random
//     BorneElectrique tableauBornes[] = {
//         {1, 2, 5, 48.8566, 2.3522},
//         {2, 1, 3, 49.1833, -0.3594},
//         {3, 0, 4, 45.7640, 4.8357},
//         {4, 2, 2, 43.2965, 5.3698},
//         {5, 1, 3, 48.1173, -1.6778}
//     };
    
//     // Recherche de la borne la plus proche d'une position GPS donnée
//     double latitude = 48.8584;
//     double longitude = 2.2945;
//     BorneElectrique borneProche = trouverBorneLaPlusProche(tableauBornes, sizeof(tableauBornes)/sizeof(tableauBornes[0]));
    
//     // Affichage des informations sur la borne la plus proche
//     printf("La borne la plus proche de la position (%f, %f) est la borne %d, située à la position (%f, %f)\n", latitude, longitude, borneProche.id, borneProche.latitude, borneProche.longitude);
    
//     return EXIT_SUCCESS;
// }

int main(){
    return EXIT_SUCCESS;
}
