#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
//#include "electric_station.h"



// ----------------------- Graph Functions -----------------------


// Function to create a new graph
Graph* createGraph(){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->list_edges = NULL;
    graph->list_vertices = NULL;

    return graph;
}


// Function to know if there are vertices in a graph
Bool verticesEmpty(Graph *graph){
    if (graph->list_vertices == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


// Function to know if there are edges in a graph
Bool edgesEmpty(Graph *graph){
    if (graph->list_edges == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


// Function to know if a graph is empty
Bool graphEmpty(Graph *graph){
    // if (graph == NULL || (graph->list_edges == NULL && graph->list_vertices == NULL)){
    //     return TRUE;
    // }
    if (verticesEmpty(graph) && edgesEmpty(graph)){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


// Function to add a vertex to a graph
void addVertex(Graph *graph, int id_station){
    if (verticesEmpty(graph)){
        Vertices *vertex = (Vertices*)malloc(sizeof(Vertices));
        vertex->id_station = id_station;
        vertex->next = NULL;
        graph->list_vertices = vertex;
    }
    else{
        if (!(vertexInGraph(graph, id_station))){
            Vertices *new = (Vertices*)malloc(sizeof(Vertices));
            new->id_station = id_station;
            new->next = NULL;

            Vertices *current = graph->list_vertices;
            while (current->next != NULL){
                current = current->next;
            }
            
            current->next = new;
        }
    }
}


// Function to add a vertex and automatically make the graph complete
void addVertexComplete(Graph *graph, int id_station){
    addVertex(graph, id_station);
    if (get_nb_vertices(graph) != 1){
        Vertices *current = graph->list_vertices;
        while (current != NULL){
            if (current->id_station != id_station){
                addEdge(graph, current->id_station, id_station);
            }
            current = current->next;
        }
    }
}


// Function to remove a vertex from the graph
void removeVertex(Graph *graph, int id_station){
    if (vertexInGraph(graph, id_station)){
        Vertices *predecessor_vertex = graph->list_vertices;
        Vertices *current_vertex = graph->list_vertices->next;
        
        if (predecessor_vertex->id_station == id_station){
            graph->list_vertices = current_vertex;
            free(predecessor_vertex);
        }
        else{
            while (current_vertex->id_station != id_station){
                predecessor_vertex = predecessor_vertex->next;
                current_vertex = current_vertex->next;
            }

            predecessor_vertex->next = current_vertex->next;
            free(current_vertex);
        }

        // Adjust edges to remove
        Edges *predecessor_edge = graph->list_edges;
        Edges *current_edge = graph->list_edges->next;

        while (current_edge != NULL){
            if (current_edge->id_borne_1 == id_station || current_edge->id_borne_2 == id_station){
                predecessor_edge->next = current_edge->next;
                free(current_edge);
                current_edge = predecessor_edge->next;
            }
            else{
                predecessor_edge = current_edge;
                current_edge = current_edge->next;
            }
        }

        // Special case for first edge
        Edges *first_edge = graph->list_edges;
        if (first_edge->id_borne_1 == id_station || first_edge->id_borne_2 == id_station){
            graph->list_edges = first_edge->next;
            free(first_edge);
        }
    }
}



// Function to know if a vertex is in the graph
Bool vertexInGraph(Graph *graph, int id_station){
    Vertices *current = graph->list_vertices;
    while (current != NULL){
        if (current->id_station == id_station){
            return TRUE;
        }
        else{
            // printf("%d != %d\n", current->id_station, id_station);
        }
        current = current->next;
    }
    
    return FALSE;
}


// Function to know if an edge is in a graph
Bool edgeInGraph(Graph *graph, int id_station1, int id_station2){
    Edges *current = graph->list_edges;
    while (current != NULL){
        if ((current->id_borne_1 == id_station1 && current->id_borne_2 == id_station2) || (current->id_borne_1 == id_station2 && current->id_borne_2 == id_station1)){
            return TRUE;
        }
        current = current->next;
    }
    return FALSE;
}


// Function to add a edge between 2 vertices
void addEdge(Graph *graph, int id_station1, int id_station2){
    if (edgesEmpty(graph)){
        Edges *new = (Edges*)malloc(sizeof(Edges));
        new->id_borne_1 = id_station1;
        new->id_borne_2 = id_station2;
        new->next = NULL;

        graph->list_edges = new;
    }
    else{
        if (!(edgeInGraph(graph, id_station1, id_station2)) && (vertexInGraph(graph, id_station1) && (vertexInGraph(graph, id_station2)))){
            Edges *new = (Edges*)malloc(sizeof(Edges));
            new->id_borne_1 = id_station1;
            new->id_borne_2 = id_station2;
            new->next = NULL;
            
            Edges *current = graph->list_edges;
            while (current->next != NULL){
                current = current->next;
                }

                current->next = new;
        }
        else{
            if (!(vertexInGraph(graph, id_station1))){
                printf("\nTrying to build edge including vertex %d which is not in graph: impossible.\n\n", id_station1);
            }
            else if (!(vertexInGraph(graph, id_station2))){
                printf("\nTrying to build edge including vertex %d which is not in graph: impossible.\n\n", id_station2);
            }
            else{
                printf("\nEdge %d-%d already exists.\n", id_station1, id_station2);
            }
        }
    }
}


// Function to remove last edge of the graph
void removeEdge(Graph *graph, int id_station1, int id_station2){
    if (edgeInGraph(graph, id_station1, id_station2)){
        Edges *predecessor = NULL;
        Edges *current = graph->list_edges;

        // Special case for first edge
        if ((current->id_borne_1 == id_station1 && current->id_borne_2 == id_station2) || (current->id_borne_1 == id_station2 && current->id_borne_2 == id_station1)){
            graph->list_edges = current->next;
            current->next = NULL;
            free(current);
        }
        else{
            // General case to remove edge when not in first position
            while (!(current->id_borne_1 == id_station1 && current->id_borne_2 == id_station2) || (current->id_borne_1 == id_station2 && current->id_borne_2 == id_station1)){
                predecessor = predecessor->next;
                current = current->next;
            }

            predecessor->next = current->next;
            current->next = NULL;
            free(current);
        }
    }
    
    else{
        printf("Edge %d-%d does not exists.\n", id_station1, id_station2);
    }
}


// Function to get the number of vertices in the graph
int get_nb_vertices(Graph *graph) {
    int size = 0;
    Vertices *current_vertex = graph->list_vertices;

    while (current_vertex != NULL) {
        current_vertex = current_vertex->next;
        size++;
    }

    return size;
}


// Function to show data in a graph
void showGraph(Graph *graph){
    // Vertices
    printf("Vertices: ");
    Vertices *current_vertex = graph->list_vertices;
    while (current_vertex != NULL){
        printf("%d", current_vertex->id_station);
        if (current_vertex->next != NULL){
            printf(", ");
        }
        current_vertex = current_vertex->next;
    }
    printf("\n");
    
    // Edges
    printf("Edges: ");
    Edges *current_edge = graph->list_edges;
    while (current_edge != NULL){
        printf("%d-%d", current_edge->id_borne_1, current_edge->id_borne_2);
        if (current_edge->next != NULL){
            printf(", ");
        }
        current_edge = current_edge->next;
    }
    printf("\n\n");
}


// Function to remove all data from a graph
void freeGraph(Graph *graph) {
    Vertices *vertex = graph->list_vertices;
    while (vertex != NULL) {
        Vertices *temp = vertex;
        vertex = vertex->next;
        free(temp);
    }

    Edges *edges = graph->list_edges;
    while (edges != NULL) {
        Edges *temp = edges;
        edges = edges->next;
        free(temp);
    }

    free(graph);
}


// Function to compute the distance between 2 vertices
int distance(int idBorne1, int idBorne2){
    // A toi Thomas
    return idBorne1 + idBorne2; // Pour pas avoir d'erreur...
}

// Function to return the distance between two electric stations
float distance_between(Graph graph, int id_station1, int id_station2){
    Edges *current_edge = graph.list_edges;
    
    while (current_edge != NULL){
        if ((current_edge->id_borne_1 == id_station1 && current_edge->id_borne_2 == id_station2) || (current_edge->id_borne_1 == id_station2 && current_edge->id_borne_2 == id_station1)){
            // We identified the two stations
            return distance(id_station1, id_station2);
        }
        else{
            current_edge = current_edge->next;
        }
    }

    // Final check on last element
    if ((current_edge->id_borne_1 == id_station1 && current_edge->id_borne_2 == id_station2) || (current_edge->id_borne_1 == id_station2 && current_edge->id_borne_2 == id_station1)){
        return distance(id_station1, id_station2);
    }
    return -1.;
}





// Function computing Dijkstra Algorithm
// Trip dijkstra(Graph *graph, int range, int start, int end){
//     // Initialisation des structures nécessaires
//     int n = get_nb_vertices(graph);
//     // Initialisation du tableau des distances
//     int d[n];
//     for (int i=0;i<n;i++){
//         d[i] = 40000;
//     }
//     d[start] = 0;
//     // Initialisation du tableau des prédécesseurs
//     int pre[n];
//     for (int i=0;i<n;i++){
//         pre[i] = -1;
//     }
//     // Initialisation de P : un tableau de booléens
//     int P[n];
//     for (int i=0;i<n;i++){
//         P[i] = 0;
//     }
//     P[start] = 1;

//     // Algorithme de Dijkstra
//     while (P[end] == 0){
//         // Recherche du sommet de distance minimale
//         int min = 40000;
//         int min_index = -1;
//         for (int i=0;i<n;i++){
//             if (P[i]==0 && d[i]<min){
//                 min = d[i];
//                 min_index = i;
//             }
//         }
//         // Parcours des sommets accessibles
//         for (int i=0;i<n;i++){
//             if (P[i]==0 && distance_between(graph, min_index, i) < range){
//                 if (d[i] > d[min_index] + distance_between(graph, min_index, i)){
//                     d[i] = d[min_index] + distance_between(graph, min_index, i);
//                     pre[i] = min_index;
//                 }
//             }
//         }

//     }
//     // Reconstruction du trajet
//     Trip trip;
//     int current = end;
//     while (current != start){
//         trip = add_to_trip(trip, current);
//         current = pre[current];
//     }
    
//     return trip;
// }




// ----------------------- Trip Functions -----------------------


// Function to create an empty trip
Trip* createTrip(int id_station){
    Trip *trip = (Trip*)malloc(sizeof(Trip));
    trip->id_borne = id_station;
    trip->next = NULL;

    return trip;
}


// Function to tell if a trip is empty
Bool tripEmpty(Trip *trip){
    if (trip == NULL){
        return TRUE;
    }
    else {
        return FALSE;
    };
}


// Function to know if a station is part of the trip
Bool stopInTrip(Trip *trip, int id_station){
    Trip *current = trip;
    while (current != NULL){
        if (current->id_borne == id_station){
            return TRUE;
        }
    }
    return FALSE;
}


// Function to add an electric station to a trip
void addStop(Trip *trip, int id_station){
    Trip *new = (Trip*)malloc(sizeof(Trip));
    new->id_borne = id_station;
    new->next = NULL;

    Trip *current = trip;
    while (current->next != NULL){
        current = current->next;
    }
    
    current->next = new;
}


// Function to remove last step of a trip
void removeStop(Trip *trip, int id_station){
    if (stopInTrip(trip, id_station)){
        
        // Special case if station to remove is the first
        if (trip->id_borne == id_station){
            trip->next = NULL;
            free(trip);
        }
        
        else{
            Trip *predecessor = trip;
            Trip *current = trip->next;
            while (current->id_borne != id_station){
                predecessor = predecessor->next;
                current = current->next;
            }
            predecessor->next = current->next;
            current->next = NULL;
            free(current);
        }
    }
}


// Function returning the number of stops in a trip
int get_nb_stops(Trip *trip){
    int res = 0;
    Trip *current = trip;
    while (current != NULL){
        current = current->next;
        res++;
    }

    return res;
}


// Function to show all vertices of a trip
void showTrip(Trip *trip){
    printf("Trip: ");
    Trip *current = trip;
    while (current != NULL){
        printf("%d", current->id_borne);
        current = current->next;
        if (current != NULL){
            printf("-");
        }
    }
    printf("\n");
}


// Function to free memory of a trip
void freeTrip(Trip *trip){
    Trip *current = trip;
    Trip *to_come = trip->next;
    while (to_come != NULL){
        current->next = NULL;
        free(current);
        current = to_come;
        to_come = to_come->next;
    }
    free(current); // Freeing last element
}




// ------------------ Graph and Trip Functions ------------------


// Function to compute the total distance of a trip
float distance_trip(Graph *graph, Trip *trip){
    int d = 0;
    
    Trip *current_station = trip;
    Trip *trip_tail = trip->next;

    while (trip_tail != NULL) {
        int a = current_station->id_borne;
        int b = trip_tail->id_borne;
        
        d += distance_between(*graph, a, b);
        
        // Moving to next stop
        current_station = trip_tail;
        trip_tail = trip_tail->next;
    }


    return d;
}
