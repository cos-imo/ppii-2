CC=clang
CFLAGS=-c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
LDFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

## Files
vehicule_part: src/vehicule.c include/vehicule.h
	$(CC) -I include $(CFLAGS) src/vehicule.c

vehicule: src/vehicule.o
	$(CC) -I include $(LDFLAGS) src/vehicule.o -o vehicule

src/trip.o: src/trip.c src/trip.h
	$(CC) -I include $(CFLAGS) src/trip.c -o src/trip.o

src/dijkstra.o: src/dijkstra.c src/dijkstra.h
	$(CC) -I include $(CFLAGS) src/dijkstra.c -o src/dijkstra.o

src/borne.o: src/borne.c src/borne.h
	$(CC) -I include $(CFLAGS) src/borne.c -o src/borne.o

## Tests
tests/test_trip: tests/test_trip.o src/trip.o
	$(CC) -I include $(LDFLAGS) tests/test_trip.o src/trip.o -o tests/test_trip

tests/test_trip.o: tests/test_trip.c tests/test_trip.h
	$(CC) -I include $(CFLAGS) tests/test_trip.c -o tests/test_trip.o

tests/test_dijkstra: tests/test_dijkstra.o
	$(CC) -I include $(LDFLAGS) tests/test_dijkstra.o src/borne.o src/trip.o src/dijkstra.o -o tests/test_dijkstra

tests/test_dijkstra.o: tests/test_dijkstra.c src/dijkstra.o src/trip.o src/borne.o
	$(CC) -I include $(CFLAGS) tests/test_dijkstra.c -o tests/test_dijkstra.o

clean: 
	rm -f src *.o tests/*.o src/*.o