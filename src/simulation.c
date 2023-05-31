#include "simulation.h"

int temps = 0;
int* *attente;
int *destination;
int *utilisateurs;
int *utilisateurs_start;
int nbUtilisateurs;


trip *trajectoires;
vehicule* *tab_vehicules;
BorneElectrique* *tab_bornes;

srand(time(NULL));

void
init_tabs()
{
        tab_vehicules = init_vehicules();
        tab_bornes = init_bornes();
}

int
nombreBornes()
{
        int res = 0;
        FILE* fp = fopen("../assets/bornes_parsed.csv", "r");
        char buffer[1024];

        if (!fp)
                printf("Importation du fichier data-bornes impossible\n Initialisation interompue\n\n");
        else {
                while (fgets(buffer,1024,fp)){
                        res ++;
                }
        }

        return res;
}

int
nombreVehicules()
{
        int res = 0;
        FILE *fp = fopen("../assets/ev-data.csv");
        char buffer[1024];

        if(!fp)
                printf("Lecture de ev-data impossible\n Initialisation de la simulation interrompue\n");
        else{
                while(fgets(buffer,1024,fp)){
                        res++;
                }
        }

        return res;
}


void
generer_usagers
        (int modulo)
{
        nbUtilisateurs = 0;
        int N = nombreBornes();
        int *tab = (int *)malloc(sizeof(int)*N);
        int *utilisateurs_start = (int *)malloc((sizeof(tab)));

        for(int i=0; i<N; i++)
        {
                tab[i]=rand()%modulo;
                nbUtilisateurs+=tab[i];
        }

        for(int j=1; i<(sizeof(tab)/sizeof(int));i++)
        {
                utilisateurs_start[j]=utilisateurs_start[j-1]+tab[i];
        }

        attente = init_attente(N);

        utilisateurs = tab; 
}

int *
init_destination
        (int nbBornes)
{
        int N=0;
        
        for(int i=0; i<nbBornes; i++){
                N+=utilisateurs[i];
        }
        
        destination = (int *)calloc(N,sizeof(int));
        
        for (int i=0; i<N; i++){
               int dest = rand()%nbBornes;
                destination[i]=dest;
        }
}

int * *
init_attente
        (int nbBornes)
{
        int* *tab_general = (int* *)malloc(sizeof(int*)*nbBornes);
        for(int i=0; i<nbBornes; i++){
                int *newTab = (int *)malloc(sizeof(int));
                tab_general[i]=newTab;
        }
        return tab_general;
}

void
init_trajectoires()
{
        //trip *trajectoires = (trip *)malloc(sizeof(trip)*nbUtilisateurs);
        for(int i=0; i<nbUtilisateurs; i++)
        {
                int vehicule = rand()%10;
                //trajectoires 
        }
}

void simulation_step()
{
        

        temps+=10;
}


int main(){

        int* *tab = init_attente(nombreBornes());

        return 0;
}
