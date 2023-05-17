#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"


Trip *dijkstra(BorneElectrique *tableauBornes, int n, int range, int start, int end){
    // Initialisation des structures nécessaires
    // Initialisation du tableau des distances depuis la borne de départ
    int d[n];
    for (int i=0;i<n;i++){
        d[i] = 40000;
    }
    d[start] = 0;

    // Initialisation du tableau des prédécesseurs
    int pre[n];
    for (int i=0;i<n;i++){
        pre[i] = -1;
    }
    
    // Initialisation de P : un tableau de booléens
    int P[n];
    for (int i=0;i<n;i++){
        P[i] = 0;
    }
    //P[start] = 1;

    // Algorithme de Dijkstra
    while (P[end] == 0){
        // Recherche du sommet de distance minimale
        int min = -1;
        int min_index = -1;
        for (int i=0;i<n;i++){
            if (P[i]==0 && (d[i]<min || min==-1)){
                min = d[i];
                min_index = i;
            }
        }
        
        // C'est le sommet min_index
        P[min_index] = 1;
        
        // Parcours des sommets accessibles
        for (int i=0; i<n; i++){
            int dist = distance(tableauBornes, min_index, i);
            // Distance entre min_index et i : dist
            if (P[i]==0 && dist < range){
                // Première condition passée
                if (d[i] > d[min_index] + dist){
                    // Mise à jour de la distance de i
                    d[i] = d[min_index] + dist;
                    pre[i] = min_index;
                }
            }
        }
        // Le minimum de distance est i
        // Son prédecesseur est pre[min_index]

    }
    
    // Calcul du trajet terminé
    if (d[end] == 40000){
        // Pas de trajet possible
        Trip *trip = createTrip();
        return trip;
    }

    // Reconstruction du trajet
    Trip *trip = createTrip();
    int current = end;
    while (current != start){
        // Ajout de l'arrêt
        addStopBeginning(trip, current);
        current = pre[current];
    }
    addStopBeginning(trip, start);
    

    return trip;
}




// int main(void){
//     Trip* trip = createTrip();
//     addStop(trip, 0);
//     addStop(trip, 1);
//     addStop(trip, 4);
//     showTrip(trip);
//     freeTrip(trip);
    
//     BorneElectrique tableauBornes[] = {
//         {0, 2, 5, 48.8566, 2.3522}, // Paris
//         {1, 1, 3, 49.1833, -0.3594}, // Caen
//         {2, 0, 4, 45.7640, 4.8357}, // Lyon
//         {3, 2, 2, 43.2965, 5.3698}, // Marseille
//         {4, 1, 3, 48.1173, -1.6778}, // Rennes
//         {5, 1, 2, 40.440058, -3.689336} // Madrid
//     };    
// }
