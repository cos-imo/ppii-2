CC=clang
CFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address



ALL_EXECUTABLES=graph main borne trip dijkstra # Ajouter tous les executables au fur et à mesure
ALL_TEST_EXECUTABLES=test_graph test_borne test_trip test_dijkstra



all: graph main borne trip dijkstra
all_tests: test_graph test_borne test_trip test_dijkstra




######## SOURCE CODE ########

# main file
main: main.o
	make dijkstra.o trip.o borne.o && $(CC) $(CFLAGS) -o main main.o
main.o: main.c

# Graph File
graph: graph.o
	$(CC) $(CFLAGS) -o graph graph.o
graph.o: graph.c

# Graph File
graphe_borne: graphe_borne.o
	$(CC) $(CFLAGS) -o graphe_borne graphe_borne.o
graphe_borne.o: graphe_borne.c

# Dijsktra File
dijkstra.o: dijkstra.c

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
	make graph.o trip.o borne.o && $(CC) $(CFLAGS) borne.o graph.o trip.o -o dijkstra dijkstra.o
dijkstra.o: dijkstra.c


# # Vehicle File
# vehicle: vehicle.o
# 	$(CC) $(CFLAGS) -o vehicle vehicle.o
# vehicle.o: vehicle.c





######## TESTING ########

# test_graph File
test_graph: ../tests/test_graph.o
	make graph.o && $(CC) $(CFLAGS) graph.o -o test_graph ../tests/test_graph.o
../tests/test_graph.o: ../tests/test_graph.c


# test_trip File
test_trip: ../tests/test_trip.o
	make trip.o && $(CC) $(CFLAGS) trip.o -o test_trip ../tests/test_trip.o
../tests/test_trip.o: ../tests/test_trip.c


# test_borne File
test_borne: ../tests/test_borne.o
	make borne.o && $(CC) $(CFLAGS) borne.o -o test_borne ../tests/test_borne.o
../tests/test_borne.o: ../tests/test_borne.c


# test_dijkstra File
# test_dijkstra: test_dijkstra.o
# 	$(CC) $(CFLAGS) ../src/dijkstra.o -o test_dijkstra test_dijkstra.o
# test_dijkstra.o: ../tests/test_dijkstra.c




clean:
	rm -f *.o ../tests/*.o ${ALL_EXECUTABLES} ${ALL_TEST_EXECUTABLES}
