#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "borne.h"

BorneElectrique* *tab;
int max_id;

void destroy(){
    for (int i = max_id; i>0; i--){
        free(tab[i]);
    }
    free(tab);
}

BorneElectrique*
*init_bornes()
{

	 FILE* fp = fopen("../assets/bornes_parsed.csv", "r");

	int max_id = 0;

    if (!fp)
        printf("Importation du fichier data-bornes impossible\n Initialisation iterompue\n\n");

    else {
        //printf("Ouverture du fichier data-bornes réussie\n Début de l'importation...\n");
        char buffer[1024];

        int row = 0;
        int column = 0;

				tab = (BorneElectrique* *)malloc(sizeof(BorneElectrique));

        int current_id = 0;

        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer, ",");

            while (value) {
        	            BorneElectrique *Borne = (BorneElectrique *)malloc(sizeof(BorneElectrique));
											assert(Borne!=NULL);

											char *end_ptr1;
        	            char *end_ptr2;

											tab = (BorneElectrique* *)realloc(tab,sizeof(BorneElectrique *)*max_id);
											assert(tab!=NULL);
											tab[max_id]=Borne;

                switch (column){
        			case 0:
        			    Borne->id = current_id;
        			    current_id ++;
        			    Borne->nbVoitures = 0;
        			    Borne->nbVoituresMax = 100;
                        Borne->latitude = strtol(value,&end_ptr1,10);
			    	break;

			    	case 1:
                        Borne->longitude = strtol(value,&end_ptr2, 10);
			    	break;
		}
                value = strtok(NULL, ",");
                column++;
            }
        }
        //printf("Importation terminée\n");
        fclose(fp);
    }

    	return tab;
}
