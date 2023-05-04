CC=clang
CFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -I ../src/graph.c


ALL_EXECUTABLES=test_graph test_trip test_dijkstra


all: test_graph test_trip test_dijkstra


# test_graph File
test_graph: test_graph.o
	$(CC) $(CFLAGS) -o test_graph test_graph.o

test_graph.o: test_graph.c


# test_trip File
test_trip: test_trip.o
	$(CC) $(CFLAGS) -o test_trip test_trip.o
test_trip.o: test_trip.c

# test_dijkstra File
test_dijkstra: test_dijkstra.o
	$(CC) $(CFLAGS) -o test_dijkstra test_dijkstra.o
test_dijkstra.o: test_dijkstra.c




clean:
	rm -f *.o ${ALL_EXECUTABLES}