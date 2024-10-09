CFLAGS = -Wall -g
LDFLAGS = -lm

CC = gcc

objects = testa_conjunto.o LibConjunto.o

all: testa_conjunto

testa_conjunto: $(objects)
	$(CC) $^ -o $@ $(LDFLAGS)

testa_conjunto.o: testa_conjunto.c LibConjunto.h
	$(CC) -c $< $(CFLAGS)

LibConjunto.o: LibConjunto.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(objects)

purge:
	rm -f $(objects) testa_conjunto