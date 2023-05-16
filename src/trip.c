#include <stdio.h>
#include <stdlib.h>

#include "trip.h"

// Function to create an empty trip
Trip *createTrip()
{
    Trip *trip = (Trip *)malloc(sizeof(Trip));
    trip->id_borne = -1;
    trip->next = NULL;

    return trip;
}

// Function to tell if a trip is empty
Bool tripEmpty(Trip *trip)
{
    if ((trip->id_borne == -1) && (trip->next == NULL))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    };
}

// Function to know if a station is part of the trip
Bool stopInTrip(Trip *trip, int id_station)
{
    Trip *current = trip;
    while (current != NULL)
    {
        if (current->id_borne == id_station)
        {
            return TRUE;
        }
        current = current->next;
    }
    return FALSE;
}

// Function to add an electric station to a trip
void addStop(Trip *trip, int id_station)
{
    if (tripEmpty(trip))
    {
        trip->id_borne = id_station;
    }

    else
    {
        Trip *new = (Trip *)malloc(sizeof(Trip));
        new->id_borne = id_station;
        new->next = NULL;

        Trip *current = trip;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new;
    }
}

// Function to add a stop at the beginning of the trip
void addStopBeginning(Trip *trip, int id_station)
{
    if (tripEmpty(trip)){
        trip->id_borne = id_station;
        trip->next = NULL;
    }
    else{
        Trip *new_trip = (Trip*)malloc(sizeof(Trip));
        new_trip->id_borne = trip->id_borne;
        new_trip->next = trip->next;
        trip->next = new_trip;
        trip->id_borne = id_station;
    }
}


// Function to add an element at position "position"
void addStopPosition(Trip *trip, int id_station, int position)
{
    if (position > get_nb_stops(trip))
    {
        position = get_nb_stops(trip);
    }

    Trip *current_trip = trip;
    Trip *new_stop = (Trip *)malloc(sizeof(Trip));

    int current_pos = 0;
    while (current_pos != position)
    {
    }
}

// Function to remove last step of a trip
void removeStop(Trip *trip, int id_station)
{
    if (stopInTrip(trip, id_station))
    {
        // Special case if station to remove is the first
        if (trip->id_borne == id_station)
        {
            Trip *temp = trip;

            // Second becomes first
            trip->id_borne = trip->next->id_borne;
            trip->next = trip->next->next;

            temp->next = NULL;
            free(temp);
        }

        else
        {
            Trip *predecessor = trip;
            Trip *current = trip->next;
            while (current->id_borne != id_station)
            {
                predecessor = predecessor->next;
                current = current->next;
            }
            predecessor->next = current->next;
            current->next = NULL;
            free(current);
        }
    }
    else
    {
        printf("\nTrying to remove stop %d which isn't in the trip.\n\n", id_station);
    }
}

// Function returning the number of stops in a trip
int get_nb_stops(Trip *trip)
{
    int res = 0;
    Trip *current = trip;
    while (current != NULL)
    {
        current = current->next;
        res++;
    }

    return res;
}

// Function to show all vertices of a trip
void showTrip(Trip *trip)
{
    printf("Trip: ");
    Trip *current = trip;
    while (current != NULL)
    {
        printf("%d", current->id_borne);
        current = current->next;
        if (current != NULL)
        {
            printf("-");
        }
    }
    printf("\n");
}

// Function to free memory of a trip
void freeTrip(Trip *trip)
{
    if (tripEmpty(trip))
    {
        free(trip);
    }
    else
    {
        Trip *current = trip;
        Trip *to_come = trip->next;
        while (to_come != NULL)
        {
            current->next = NULL;
            free(current);
            current = to_come;
            to_come = to_come->next;
        }
        free(current); // Freeing last element
    }
}
