#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <assert.h>

#include "main.h"


vehicule find_vehicle(char* model, vehicule* vehicle_table){
	// On sait que le modèle est dans la liste
    int size = 49;
    for (int i=0; i<49; i++){
        if (strcmp(vehicle_table[i].modele, model) == 0){
            return vehicle_table[i];
        }
    }
}

/*
void destroy(void* tab){
    for (int i = max_id; i>0; i--){
        free(tab[i]);
    }
    free(tab);
}
*/

BorneElectrique* *init_bornes(){
    FILE* fp = fopen("../assets/bornes_parsed.csv", "r");

    int max_id = 0;
    BorneElectrique* *tab;

    if (!fp){
        // printf("Importation du fichier data-bornes impossible\nInitialisation intérrompue\n\n");
        return NULL;
    }

    else {
        // printf("Ouverture du fichier data-bornes réussie\n Début de l'importation...\n");
        char buffer[1024];

        int row = 0;
        int column = 0;

        tab = (BorneElectrique* *)malloc(sizeof(BorneElectrique *));

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
        // printf("Importation terminée\n");
        fclose(fp);
    }

        return tab;
    }

vehicule* *init_vehicules(){
    FILE* fp = fopen("../assets/ev-data.csv", "r");
    vehicule* *tab;

    int max_id = 0;

    if (!fp)
        // printf("Importation du fichier ev-data impossible\n Initialisation iterompue\n\n");
        return NULL;

    else {
        // printf("Importation du fichier ev-data réussie!\n");
        char buffer[1024];

        int row = 0;
        int column = 0;

        tab = (vehicule* *)malloc(sizeof(vehicule *));

        while (fgets(buffer,
                        1024, fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer, ";");

            while (value) {
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

                max_id++;
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
        // printf("Importation réussie!\n");
        fclose(fp);
    }

    //destroy();

    return tab;
    }



int main(int argc, char** argv){
    // Arguments argv : least battery percentage, max minutes
    // Nombre d'arguments varie : mode 1 renvoie tous les véhicules, mode 2 renvoie le Trip lat1,long1+lat2,long2+...

    // First launch: ./main -> list_vehicles
    if (argc == 1){
        // int not_below = atoi(argv[1]);
        // int max_minutes_at_station = atoi(argv[2]);
        char* list_models[50] = {"Tesla Model Y Long Range Dual Motor", "Tesla Model 3", "Tesla Model Y", "Tesla Model 3 Long Range Dual Motor", "BYD ATTO 3", "MG MG4 Electric 64 kWh", "Tesla Model S Plaid", "BMW i4 eDrive40", "BMW iX xDrive40", "Tesla Model Y Performance", "Kia Niro EV", "BMW iX1 xDrive30", "Mercedes EQS 450+", "Mercedes EQE 350+", "Hongqi E-HS9 99 kWh", "BYD HAN", "Audi Q8 e-tron 55 quattro", "Kia EV6 GT", "Tesla Model S Dual Motor", "Lexus RZ 450e", "Skoda Enyaq iV 80", "BMW i7 xDrive60", "Hyundai IONIQ 6 Long Range AWD", "Hyundai Kona Electric 64 kWh", "Audi Q4 e-tron 40", "Smart #1", "Nissan Ariya 87kWh", "BMW iX xDrive50", "Tesla Model 3 Performance", "Dacia Spring Electric 45", "BMW iX3", "BMW i4 M50", "Volkswagen ID. Buzz Pro", "BMW i4 eDrive35", "Audi e-tron GT RS", "Renault Megane E-Tech EV60 220hp", "MG ZS EV Long Range", "Fiat 500e Hatchback 42 kWh", "Mercedes EQC 400 4MATIC", "BYD TANG", "Renault Zoe ZE50 R110", "Kia EV6 Long Range 2WD", "Volkswagen ID.4 Pro", "Mercedes EQS 580 4MATIC", "Hyundai IONIQ 6 Long Range 2WD", "MG MG4 Electric 51 kWh", "Peugeot e-208", "Toyota bZ4X FWD", "Volkswagen ID.4 Pro Performance"};

        int nb_models = 49;
        for (int i=0; i<nb_models-1; i++){
            printf("%s+", list_models[i]);
        }
        printf("%s\n", list_models[48]);


        return EXIT_SUCCESS;
    }


    // User entered location, vehicle model and other parameters on Php page:
    // ./main minBatteryPercent maxTimeAtStation model lat long
    else if (argc == 6){
        //        CONVERTING DATA        //

        int not_below = atoi(argv[1]);

        int max_minutes_at_station = atoi(argv[2]);

        const char* latitude_str = argv[3];
        char* endptr_lat;
        double latitude = strtod(latitude_str, &endptr_lat);

        const char* longitude_str = argv[4];
        char* endptr_long;
        double longitude = strtod(longitude_str, &endptr_long);

        char* vehicle_model = argv[5];

        // ------------------------------ //


        // Computing Dijkstra

        // Initialize
        BorneElectrique* tableauBornes = *init_bornes();
        vehicule** all_vehicles = init_vehicules();
        char* list_models[50] = {"Tesla Model Y Long Range Dual Motor", "Tesla Model 3", "Tesla Model Y", "Tesla Model 3 Long Range Dual Motor", "BYD ATTO 3", "MG MG4 Electric 64 kWh", "Tesla Model S Plaid", "BMW i4 eDrive40", "BMW iX xDrive40", "Tesla Model Y Performance", "Kia Niro EV", "BMW iX1 xDrive30", "Mercedes EQS 450+", "Mercedes EQE 350+", "Hongqi E-HS9 99 kWh", "BYD HAN", "Audi Q8 e-tron 55 quattro", "Kia EV6 GT", "Tesla Model S Dual Motor", "Lexus RZ 450e", "Skoda Enyaq iV 80", "BMW i7 xDrive60", "Hyundai IONIQ 6 Long Range AWD", "Hyundai Kona Electric 64 kWh", "Audi Q4 e-tron 40", "Smart #1", "Nissan Ariya 87kWh", "BMW iX xDrive50", "Tesla Model 3 Performance", "Dacia Spring Electric 45", "BMW iX3", "BMW i4 M50", "Volkswagen ID. Buzz Pro", "BMW i4 eDrive35", "Audi e-tron GT RS", "Renault Megane E-Tech EV60 220hp", "MG ZS EV Long Range", "Fiat 500e Hatchback 42 kWh", "Mercedes EQC 400 4MATIC", "BYD TANG", "Renault Zoe ZE50 R110", "Kia EV6 Long Range 2WD", "Volkswagen ID.4 Pro", "Mercedes EQS 580 4MATIC", "Hyundai IONIQ 6 Long Range 2WD", "MG MG4 Electric 51 kWh", "Peugeot e-208", "Toyota bZ4X FWD", "Volkswagen ID.4 Pro Performance"};

        // Parameters
        vehicule v = find_vehicle(vehicle_model, all_vehicles);
        int range = (100 - not_below) * v.range;
        Trip *final_trip = dijkstra(tableauBornes, 10000, range, 0, 1);

    }

    else{
        printf("Invalid number of arguments.\n");
        printf("Usage:\n    [*] main: returns all models of vehicles in the database\n    [*] main minBatteryPercent maxTimeAtStation model lat long: returns a sequence of coordinates corresponding to electric stations to pass by, according to parameters provided\n");

        return EXIT_FAILURE;
    }
}
