#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"


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
        //printf("Recherche du sommet de distance minimale\n");
        int min = -1;
        int min_index = -1;
        for (int i=0;i<n;i++){
            if (P[i]==0 && (d[i]<min || min==-1)){
                min = d[i];
                min_index = i;
            }
        }
        //printf("C'est le sommet %d\n", min_index);
        P[min_index] = 1;
        // Parcours des sommets accessibles
        for (int i=0;i<n;i++){
            int dist = distance(tableauBornes, min_index, i);
            //printf("distance entre %d et %d : %d\n", min_index, i, dist);
            //printf("P[%d] = %d\n", i, P[i]);
            if (P[i]==0 && dist < range){
                //printf("Première condition passée\n");
                //printf("d[%d] = %d\n", i, d[i]);
                //printf("d[%d] + dist = %d\n", min_index, d[min_index] + dist);
                if (d[i] > d[min_index] + dist){
                    //printf("Mise à jour de la distance de %d\n", i);
                    d[i] = d[min_index] + dist;
                    pre[i] = min_index;
                }
            }
        }
        //printf("le minimum est %d\n", min_index);
        //printf("son predescesseur est %d\n", pre[min_index]);

    }
    //printf("Calcul du trajet terminé\n");
    if (d[end] == 40000){
        //Pas de trajet possible
        Trip *trip = createTrip();
        return trip;
    }
    // Reconstruction du trajet
    Trip *trip = createTrip();
    int current = end;
    while (current != start){
        //printf("Ajout de l'arrêt %d\n", current);
        addStop(trip, current);
        current = pre[current];
    }
    addStop(trip, start);
    
    return trip;
}


// int main(void){
//     return EXIT_SUCCESS;
// }
