#include <stdio.h>
#include <stdlib.h>

typedef struct _vehicule{
	int id;				//A relier avec une table de hachage
	char *modele;
	double capacite;		//Pas de type spécifié sur le document -> faut-il garder double?
	double consommation;
	int charge;
	double temps_chargement;	//?
	double latitude;		//Pourquoi faire, si l'on se déplace sur un graphe?
	double longitude;		//Pareil
} vehicule;

typedef struct list_t {
	vehicule *Vehicule;
	struct list_t *nextNode;
} liste;
