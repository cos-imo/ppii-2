#include "bases.h"
#include "graph.h"




typedef struct Vehicle{
    int id;
    char model[20];
    float capacity; // kW . h
    float consumption; // W . km-1
    float actual_battery_percentage; // %
    int time_charging;
    double latitude;
    double longitude; // Regarder si ça vaut vraiment le coup tous ces doubles
} Vehicle;



float get_battery_percentage(Vehicle vehicle);
float autonomy_left(Vehicle vehicle);
void update_location(Vehicle *vehicle);
Bool can_go_to_next(Graph graph, Vehicle vehicle);
