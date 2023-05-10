#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "borne.c"



Trip *dijkstra(BorneElectrique tableauBornes, int n, float range, int start, int end){
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
    P[start] = 1;

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
        // Parcours des sommets accessibles
        for (int i=0;i<n;i++){
            int dist = distance(min_index, i, tableauBornes);
            if (P[i]==0 && dist < range){
                if (d[i] > d[min_index] + dist){
                    d[i] = d[min_index] + dist;
                    pre[i] = min_index;
                }
            }
        }

    }
    // Reconstruction du trajet
    Trip *trip;
    int current = end;
    while (current != start){
        addStop(trip, current);
        current = pre[current];
    }
    return trip;


}