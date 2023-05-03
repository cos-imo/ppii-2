#include "vehicule.h"

int main(int argc, char* *argv){
	return 0;
}

int init_vehicule(){
	vehicule *v = (vehicule *)malloc(sizeof(vehicule));

	v->id = 0;					//A calculer avec une fonction de hachage?
	char *modele_str = (char *)malloc(sizeof(char)*100)	//A discuter, là j'abuse peut-être un peu
	v->modele = modele_str;
	v->capacite = 0;
	v->consommation = 0;
	v->charge = 100;
	v->temps_chargement = 0;
	v->latitude = 0;
	v->longitude = 0;
}

int getBatteryPourcentage(vehicule *v){
	return(v->charge);
}
