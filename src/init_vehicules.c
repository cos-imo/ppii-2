#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "vehicule.h"

vehicule* *tab;
int max_id;

void destroy_bornes(){
    for (int i = max_id; i>0; i--){
        free(tab[i]->modele);
        free(tab[i]->marque);
        free(tab[i]);
    }
    free(tab);
}

vehicule* *init_vehicules()
{

	 FILE* fp = fopen("../assets/ev-data.csv", "r");

	int max_id = 0;

    if (!fp)
        printf("Importation du fichier ev-data impossible\n Initialisation iterompue\n\n");

    else {
        //printf("Importation du fichier ev-data réussie!\n");
        char buffer[1024];

        int row = 0;
        int column = 0;

        tab = (vehicule* *)malloc(sizeof(vehicule));

        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer, ";");

            while (value) {
                        max_id++;
    	    			vehicule *Vehicule = (vehicule *)malloc(sizeof(vehicule));
    	    	        assert(Vehicule!=NULL);

    	    	        char *modele_str;
	    	    		modele_str = (char *)malloc((sizeof(char))*MAX_MODEL_NAME);
	    	            assert(modele_str!=NULL);

	    	            char *brand_str;
						brand_str = (char *)malloc(sizeof(char)*MAX_BRAND_NAME);
                        assert(brand_str!=NULL);

	    	            tab = (vehicule* *)realloc(tab,sizeof(vehicule *)*max_id);
	    	            assert(tab!=NULL);
	    	            tab[max_id]=Vehicule;

                switch (column){
			        case 0:
        				strcpy(modele_str, value);

        				Vehicule->modele=modele_str;
        				Vehicule->id = max_id;

            		break;

                	case 1:
	        			Vehicule->range = atoi(value);
            		break;

                    case 3:
						Vehicule->top_speed = atoi(value);
    				break;

	        		case 4:
						Vehicule->efficiency = atoi(value);
				    break;

			        case 5:
						Vehicule->fast_charge = atoi(value);
				    break;

        			case 6:
						strcpy(brand_str, value);

						Vehicule->marque=brand_str;
			    	break;
		}
                value = strtok(NULL, ";");
                column++;
            }

        }
        //printf("Importation réussie!\n");
        fclose(fp);
    }

    //destroy();

    	return tab;
}
