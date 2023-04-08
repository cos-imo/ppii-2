#include <stdio.h>

#include "graph.h"



int get_nb_vertices(Graph *graph){
    int n = 0;
    while (graph->electric_station_id[n] != NULL){
        n++;
    }

    return n;
}

Bool are_connected(Graph graph, int a, int b){
    while (graph.electric_station_id != NULL){
        Link *link_list = graph.link_list;
        if (graph.link_list->id_borne_1 == a && graph.link_list->id_borne_2 == b){
            return TRUE;
        }
    }
}



int main(){
    return 0;
}
