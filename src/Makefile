CC=clang
CFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address


ALL_EXECUTABLES=graph main borne trip dijkstra # Ajouter tous les executables au fur et à mesure


all: graph main borne trip dijkstra # Pareil ici


# main file
main: main.o
	$(CC) $(CFLAGS) -o main main.o
main.o: main.c


# Graph File
graph: graph.o
	$(CC) $(CFLAGS) -o graph graph.o
graph.o: graph.c


# Borne electrique File
borne: borne.o
	$(CC) $(CFLAGS) -o borne borne.o
borne.o: borne.c


# Trip File
trip: trip.o
	$(CC) $(CFLAGS) -o trip trip.o
trip.o: trip.c


# Dijkstra File
dijkstra: dijkstra.o
	$(CC) $(CFLAGS) borne.o graph.o trip.o -o dijkstra dijkstra.o
dijkstra.o: dijkstra.c


# # Vehicle File
# vehicle: vehicle.o
# 	$(CC) $(CFLAGS) -o vehicle vehicle.o
# vehicle.o: vehicle.c







clean:
	rm -f *.o ${ALL_EXECUTABLES}
