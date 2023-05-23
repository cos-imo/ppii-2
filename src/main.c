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
        printf("Initialisation ok\n");
        // vehicule** all_vehicles = init_vehicules();
        char* list_models[50] = {"Tesla Model Y Long Range Dual Motor", "Tesla Model 3", "Tesla Model Y", "Tesla Model 3 Long Range Dual Motor", "BYD ATTO 3", "MG MG4 Electric 64 kWh", "Tesla Model S Plaid", "BMW i4 eDrive40", "BMW iX xDrive40", "Tesla Model Y Performance", "Kia Niro EV", "BMW iX1 xDrive30", "Mercedes EQS 450+", "Mercedes EQE 350+", "Hongqi E-HS9 99 kWh", "BYD HAN", "Audi Q8 e-tron 55 quattro", "Kia EV6 GT", "Tesla Model S Dual Motor", "Lexus RZ 450e", "Skoda Enyaq iV 80", "BMW i7 xDrive60", "Hyundai IONIQ 6 Long Range AWD", "Hyundai Kona Electric 64 kWh", "Audi Q4 e-tron 40", "Smart #1", "Nissan Ariya 87kWh", "BMW iX xDrive50", "Tesla Model 3 Performance", "Dacia Spring Electric 45", "BMW iX3", "BMW i4 M50", "Volkswagen ID. Buzz Pro", "BMW i4 eDrive35", "Audi e-tron GT RS", "Renault Megane E-Tech EV60 220hp", "MG ZS EV Long Range", "Fiat 500e Hatchback 42 kWh", "Mercedes EQC 400 4MATIC", "BYD TANG", "Renault Zoe ZE50 R110", "Kia EV6 Long Range 2WD", "Volkswagen ID.4 Pro", "Mercedes EQS 580 4MATIC", "Hyundai IONIQ 6 Long Range 2WD", "MG MG4 Electric 51 kWh", "Peugeot e-208", "Toyota bZ4X FWD", "Volkswagen ID.4 Pro Performance"};

        // Parameters
        // vehicule v = find_vehicle(vehicle_model, all_vehicles);
        // int range = (100 - not_below) * v.range;
        // Trip *final_trip = dijkstra(tableauBornes, 10000, range, 0, 1);
        // show_coordinates(trip, tableauBornes);

        return EXIT_SUCCESS;
    }

    else{
        printf("Invalid number of arguments.\n");
        printf("Usage:\n    [*] main: returns all models of vehicles in the database\n    [*] main minBatteryPercent maxTimeAtStation model lat long: returns a sequence of coordinates corresponding to electric stations to pass by, according to parameters provided\n");

        return EXIT_FAILURE;
    }

}
