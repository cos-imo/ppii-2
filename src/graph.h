// Boolean type
typedef enum Bool{
    FALSE,
    TRUE
} Bool;




// Link structure
typedef struct Link{
    int id_borne_1;
    int id_borne_2;
    struct Link *next;
} Link;


// Graph structure
typedef struct Graph{
    int *electric_station_id; // A changer en fonction du nom
    Link *link_list;
} Graph;


// Trip structure
typedef struct Trip{
    int id_borne;
    struct Trip *next;
} Trip;



// Graph Functions
int get_nb_vertices(Graph *graph);
float distance_between(Graph graph, int id_borne1, int id_borne2);
Bool isEmpty(Trip *trip);
void addVertex(Trip *trip, int id_borne);
void removeVertex(Trip *trip);
int get_nb_stops(Trip *trip);
void showTrip(Trip *trip);
void freeTrip(Trip *trip);
float distance_trip(Graph *graph, Trip *trip);
int distance(int idBorne1, int idBorne2);
Trip dijkstra(Graph graph);
