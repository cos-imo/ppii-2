#include "bases.h"



// Type véhicule :
// 	- ID pour différencier les mêmes véhicules
// 	- Modèle (pk pas)
// 	- Capacité
// 	- Consommation
// 	- Charge actuelle du véhicule en pourcentages : int
// 	- Temps depuis lequel il charge sa voiture (pas plus de 20min et initialisé à 0)
// 	- Latitude et longitude (à calculer avec les distances entre les bornes et vitesse)


typedef struct Vehicle{
    int id;
    char model[20];
    float capacity;
    float consumption;
    float actual_battery_percentage;
    int time_charging;
    double latitude;
    double longitude; // Regarder si ça vaut vraiment le coup tous ces doubles
} Vehicle;




// Fonctions pour type Véhicule :
// 	- getBatteryPourcentage
// 	- autonomy_left (distance  en prenant en compte les 30%)
// 	- update_location : change pour pas de 10min pour 2ème partie
// 	- can_go_to_next : bool (vrai si le véhicule peut aller à la prochaine borne de son trajet avec son pourcentage de batterie actuel)
