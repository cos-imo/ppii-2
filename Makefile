CC=clang
CFLAGS=-c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
LDFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

vehicule_part: src/vehicule.c include/vehicule.h
	$(CC) -I include $(CFLAGS) src/vehicule.c

vehicule: src/vehicule.o
	$(CC) -I include $(LDFLAGS) src/vehicule.o -o vehicule
