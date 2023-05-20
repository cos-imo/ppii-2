CC=clang
CFLAGS=-c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
LDFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

ALL_OBJECTS= src/borne.o src/dijkstra.o src/trip.o src/graph.o src/vehicule.o
ALL_EXECUTABLES=main
ALL_TEST_EXECUTABLES= tests/test_borne tests/test_dijkstra tests/test_graph tests/test_trip



######## SOURCE CODE ########


# main file
## REFAIRE pareil que celui dans src mais ici...
# main TEMPORAIRE
main: src/vehicule.o src/bornes.o src/main.o
	mkdir build
	gcc src/vehicule.o src/bornes.o src/main.o -o build/main_output
	rm src/*.o

src/main.o: src/main.c
	gcc -c -I include src/main.c -o src/main.o

src/vehicule.o: src/init_vehicules.c
	gcc -c -I include src/init_vehicules.c -o src/vehicule.o -Iinclude

src/bornes.o: src/init_bornes.c
	gcc -I include -c src/init_bornes.c -o src/bornes.o


# vehicule
vehicule_part: src/vehicule.c include/vehicule.h
	$(CC) -I include $(CFLAGS) src/vehicule.c

vehicule: src/vehicule.o
	$(CC) -I include $(LDFLAGS) src/vehicule.o -o vehicule

# trip
src/trip.o: src/trip.c include/trip.h
	$(CC) -I include $(CFLAGS) src/trip.c -o src/trip.o

# dijkstra
src/dijkstra.o: src/dijkstra.c include/dijkstra.h
	$(CC) -I include $(CFLAGS) src/dijkstra.c src/trip.o -o src/dijkstra.o

# borne
src/borne.o: src/borne.c include/borne.h
	$(CC) -I include $(CFLAGS) src/borne.c -o src/borne.o

# coordinates
src/coordinates.o: src/coordinates.c include/coordinates.h
	$(CC) -I include $(CFLAGS) src/coordinates.c -o src/coordinates.o




######## TESTING ########



# test_trip
tests/test_trip: tests/test_trip.o src/trip.o
	$(CC) -I include $(LDFLAGS) tests/test_trip.o src/trip.o -o tests/test_trip
tests/test_trip.o: tests/test_trip.c include/test_trip.h
	$(CC) -I include $(CFLAGS) tests/test_trip.c -o tests/test_trip.o

# test_dijkstra
tests/test_dijkstra: tests/test_dijkstra.o
	$(CC) -I include $(LDFLAGS) tests/test_dijkstra.o src/borne.o src/trip.o src/dijkstra.o -o tests/test_dijkstra
tests/test_dijkstra.o: tests/test_dijkstra.c src/dijkstra.o src/trip.o src/borne.o
	$(CC) -I include $(CFLAGS) tests/test_dijkstra.c -o tests/test_dijkstra.o

# test_borne
tests/test_borne: tests/test_borne.o src/borne.o
	$(CC) -I include $(LDFLAGS) tests/test_borne.o src/borne.o -o tests/test_borne
tests/test_borne.o: tests/test_borne.c src/borne.o
	$(CC) -I include $(CFLAGS) tests/test_borne.c -o tests/test_borne.o


# clean workspace
clean: 
	rm -f *.o ./tests/*.o ./src/*.o ${ALL_OBJECTS} ${ALL_TEST_EXECUTABLES} ${ALL_EXECUTABLES}
