CC=clang
all: textbook network insertion

common: partition.c test.c
	$(CC) $(CFLAGS) -c partition.c -o partition.o
	$(CC) $(CFLAGS) -c test.c -o test.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

textbook: textbook.o common
	$(CC) $(CFLAGS) $< partition.o test.o -o $@

network: network.o common
	$(CC) $(CFLAGS) $< partition.o test.o -o $@

insertion: insertion.o common
	$(CC) $(CFLAGS) $< partition.o test.o -o $@

clean:
	rm -f *.o textbook network insertion
