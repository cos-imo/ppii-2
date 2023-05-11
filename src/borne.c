#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "borne.h"


// Distance entre deux coordonnées GPS (pas touche au nom, Kieran)
int distance(BorneElectrique tableauBornes[], int id1, int id2){
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


// // Fonction qui trouve la borne la plus proche de coordonnées GPS données
// BorneElectrique trouverBorneLaPlusProche(BorneElectrique tableauBornes[], int nbBornes){
//     double distanceMin = INFINITY; // Initialisation de la distance minimale à l'infini
//     BorneElectrique borneLaPlusProche; // Initialisation de la borne la plus proche
    
//     for (int i = 2; i < nbBornes; i++) {
//         int d = distance(tableauBornes, 0, i);
//         if (d < distanceMin) {
//             distanceMin = d;
//             borneLaPlusProche = tableauBornes[i];
//         }
//     }
    
//     return borneLaPlusProche;
// }


//Function to compute the total distance of a trip
float distance_trip(Trip *trip, BorneElectrique tableauBornes[]){
    int total_distance= 0;
    
    Trip *current_station = trip;
    Trip *trip_tail = trip->next;

    while (trip_tail != NULL) {
        int a = current_station->id_borne;
        int b = trip_tail->id_borne;

       total_distance += distance(tableauBornes, a, b);
        
        // Moving to next stop
        current_station = trip_tail;
        trip_tail = trip_tail->next;
    }

    return total_distance;
}



// int main(){
//     return EXIT_SUCCESS;
// }
