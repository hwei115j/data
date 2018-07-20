CC := gcc
all: main.c huffman.o
	$(CC) main.c huffman.o
huffman.o: huffman.c huffman.h
	$(CC) -c huffman.c
clean:
	rm -f *.o *.exe* *.out*
