#include <stdio.h>
#include <stdlib.h>

#include "vehicle.h"


float get_battery_percentage(Vehicle vehicle){
    return vehicle.actual_battery_percentage;
}


float autonomy_left(Vehicle vehicle){
    float full_autonomy = vehicle.capacity / vehicle.consumption;
    // Revoir avec valeurs de la table
    return 0;
    //return (vehicle.actual_battery_percentage * ())
}


int main(){
    return 0;
}
