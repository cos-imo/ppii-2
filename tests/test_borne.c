#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#include "test_borne.h"


int testBorne() {
    // Test pour un tableau de bornes random
    BorneElectrique tableauBornes[] = {
        {1, 2, 5, 48.8566, 2.3522},
        {2, 1, 3, 49.1833, -0.3594},
        {3, 0, 4, 45.7640, 4.8357},
        {4, 2, 2, 43.2965, 5.3698},
        {5, 1, 3, 48.1173, -1.6778}
    };
    
    // Recherche de la borne la plus proche d'une position GPS donnée
    double latitude = 48.8584;
    double longitude = 2.2945;
    //BorneElectrique borneProche = trouverBorneLaPlusProche(tableauBornes, sizeof(tableauBornes)/sizeof(tableauBornes[0]));
    
    // Affichage des informations sur la borne la plus proche
    printf("La borne la plus proche de la position (%f, %f) est la borne %d, située à la position (%f, %f)\n", latitude, longitude, borneProche.id, borneProche.latitude, borneProche.longitude);
    
    return EXIT_SUCCESS;
}

