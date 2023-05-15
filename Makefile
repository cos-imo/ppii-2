CC=clang
CFLAGS=-c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
LDFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

vehicule_part: src/vehicule.c include/vehicule.h
	$(CC) -I include $(CFLAGS) src/vehicule.c

vehicule: src/vehicule.o
	$(CC) -I include $(LDFLAGS) src/vehicule.o -o vehicule

tests/test_trip: tests/test_trip.o src/trip.o
	$(CC) -I include $(LDFLAGS) tests/test_trip.o src/trip.o -o tests/test_trip

src/trip.o: src/trip.c src/trip.h
	$(CC) -I include $(CFLAGS) src/trip.c

tests/test_trip.o: tests/test_trip.c tests/test_trip.h
	$(CC) -I include $(CFLAGS) tests/test_trip.c -o tests/test_trip.o
