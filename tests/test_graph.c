#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

#include "graph.h"


// Functions from graph.c file
// float distance_between(Graph graph, int id_station1, int id_station2){
//     Link *current_link = graph.link_list;
    
//     while (current_link != NULL){
//         if ((current_link->id_borne_1 == id_station1 && current_link->id_borne_2 == id_station2) || (current_link->id_borne_1 == id_station2 && current_link->id_borne_2 == id_station1)){
//             // We identified the two stations
//             return distance(id_station1, id_station2);
//         }
//         else{
//             current_link = current_link->next;
//         }
//     }

//     // Final check on last element
//     if ((current_link->id_borne_1 == id_station1 && current_link->id_borne_2 == id_station2) || (current_link->id_borne_1 == id_station2 && current_link->id_borne_2 == id_station1)){
//         return distance(id_station1, id_station2);
//     }
//     return -1.;
//}


int get_nb_vertices(Graph *graph) {
    int size = 0;
    Link *current_link = graph->link_list;

    while (current_link != NULL){
        size++;
        current_link = current_link->next;
    }

    return size;
}





int testGraph(){
    // Create a new Graph object
    Graph graph;
    graph.electric_station_id = NULL;
    graph.link_list = NULL;

    // Add three vertices to the graph
    Link* link1 = (Link*)malloc(sizeof(Link));
    link1->id_borne_1 = 1;
    link1->id_borne_2 = 2;
    link1->next = NULL;

    Link* link2 = (Link*)malloc(sizeof(Link));
    link2->id_borne_1 = 2;
    link2->id_borne_2 = 3;
    link2->next = NULL;

    Link* link3 = (Link*)malloc(sizeof(Link));
    link3->id_borne_1 = 3;
    link3->id_borne_2 = 1;
    link3->next = NULL;

    link1->next = link2;
    link2->next = link3;
    graph.link_list = link1;

    // // Add vertices with a for loop
    // int n = 12;
    // Link *vertices[n];

    // Link *link_0 = (Link*)malloc(sizeof(Link));
    // link_0->id_borne_1 = 0;
    // link_0->id_borne_2 = 1;

    // for (int i=1; i<n-1; i++){
    //     Link *link_i = (Link*)malloc(sizeof(Link));
    //     link_i->id_borne_1 = i;
    //     link_i->id_borne_2 = i+1;
    //     vertices[i-1]->next = link_i;
    // }
    
    // Link *link_n = (Link*)malloc(sizeof(Link));
    // link_n->id_borne_1 = n-1;
    // link_n->id_borne_2 = 0;
    // vertices[n-1]->next = link_n;

    // Display the size of the graph
    int graph_size = get_nb_vertices(&graph);
    printf("The graph has %d vertices.\n", graph_size);
    printf("Vertices 1 and 2 are separated by %fm.\n", distance_between(graph, 1, 2));
    
    // Free memory
    free(link1);
    free(link2);
    free(link3);
    // for (int i=0; i<n; i++){
    //     // Free in a loop or call a function already made
    // }


    return EXIT_SUCCESS;
}



int main(){
    testGraph();
    return EXIT_SUCCESS;
}
