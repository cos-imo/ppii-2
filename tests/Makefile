CC=clang
CFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address 


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
test_dijkstra: test_dijkstra.o ../src/dijkstra.o ../src/graph.o
	$(CC) $(CFLAGS) -o test_dijkstra test_dijkstra.o ../src/dijkstra.o ../src/graph.o

test_dijkstra.o: test_dijkstra.c ../src/dijkstra.o
	$(CC) $(CFLAGS) -c test_dijkstra.c -o test_dijkstra.o

../src/dijkstra.o: ../src/dijkstra.c ../src/dijkstra.h ../src/graph.o
	$(CC) $(CFLAGS) -c ../src/dijkstra.c -o ../src/dijkstra.o

../src/graph.o: ../src/graph.c ../src/graph.h
	$(CC) $(CFLAGS) -c ../src/graph.c -o ../src/graph.o

clean:
	rm -f *.o ../src/*.o ${ALL_EXECUTABLES}