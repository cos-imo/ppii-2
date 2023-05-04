CC=clang
CFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address


ALL_EXECUTABLES=graph main # Ajouter tous les executables au fur et à mesure


all: graph main # Pareil ici


# main file
main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c


# Graph File
graph: graph.o
	$(CC) $(CFLAGS) -o graph graph.o
graph.o: graph.c

# Graph File
graphe_borne: graphe_borne.o
	$(CC) $(CFLAGS) -o graphe_borne graphe_borne.o
graphe_borne.o: graphe_borne.c

# # Vehicle File
# vehicle: vehicle.o
# 	$(CC) $(CFLAGS) -o vehicle vehicle.o
# vehicle.o: vehicle.c


# # Electri Station File
# electric_station: electric_station.o
# 	$(CC) $(CFLAGS) -o electric_station electric_station.o
# electric_station.o: electric_station.c





clean:
	rm -f *.o ${ALL_EXECUTABLES}