//#include "bases.h"


// Electric Station type
typedef struct Electric_station{
    int id;
    int nb_cars_here;
    int nb_cars_possible;
} Electric_station;



Bool is_occupied(Electric_station station);
int nb_waiting(Electric_station station);
