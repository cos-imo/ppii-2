#include "vehicule.h"


vehicule find_vehicle(char* model, vehicule* vehicle_table){
	// On sait que le modèle est dans la liste
    int size = 49;
    for (int i=0; i<49; i++){
        if (vehicle_table[i].modele == model){
            return vehicle_table[i];
        }
    }
}


int main(int argc, char **argv) {
	
	FILE* fp = fopen("data.txt", "r");

	int max_id = 0;
 
    if (!fp)
        printf("Can't open file\n");
    else {
        char buffer[1024];
        int row = 0;
        int column = 0;
 
        while (fgets(buffer, 1024, fp)){
            column = 0;
            row++;
 
            if (row == 1)
                continue;
 
            char* value = strtok(buffer, ";");
 
            while (value) {
                switch (column){
			        case 0:
			            printf("Hello");
    	    			vehicule *Vehicule = (vehicule *)malloc(sizeof(vehicule));
	    	    		char *modele_str = malloc(sizeof(char)*MAX_MODEL_NAME);

        				strcpy(value, modele_str);

        				Vehicule->modele=modele_str;
        				Vehicule->id = max_id;
        				max_id++;

		        		printf("Name :");
            		break;
 
                	case 1:
	        			printf("\tNom du modèle :");
	        			Vehicule->capacite;
            		break;
 
                	case 2:
        				printf("\tAutonomie (km) :");
            		break;

                    case 3:
				        printf("\tacceleration:");
    				break;
	        		
	        		case 4:
			        	printf("\tVitesse max:");
				    break;
			        
			        case 5:
				        printf("\tEfficiency?:");
				    break;
        			
        			case 6:
		    	    	printf("\tCharge rapide:");
			    	break;
        			
        			case 7:
        			    //fprintf(fp,"%??", vehicule);
		        		printf("\tMarque:");
			    	break;
		}

                printf("%s", value);
                value = strtok(NULL, ";");
                column++;
            }
 
            printf("\n");
        }
        //fwrite(type,fwrite(clientdata, sizeof(char), sizeof(clientdata), f);
        fclose(fp);
    }
	
    	return 0;
}
