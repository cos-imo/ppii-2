#include <stdio.h>
#include <stdlib.h>


#define MAX_MODEL_NAME 100
#define MAX_BRAND_NAME 100

typedef struct _vehicule{
	int id;				//A relier avec une table de hachage
	char *modele;
	int range;
	double acceleration;
	int top_speed;
	int efficiency;
	int fast_charge;
	char *marque;
	int charge;
	double temps_chargement;	//?
	double latitude;		//Pourquoi faire, si l'on se déplace sur un graphe?
	double longitude;		//Pareil

} vehicule;

typedef struct list_t {
	vehicule *Vehicule;
	struct list_t *nextNode;
} liste;
