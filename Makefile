CFLAGS = -g -Wall -Wstrict-prototypes
PROGS = make-matrix print-matrix mm-serial
LDFLAGS = -lm 
CC = gcc

all: $(PROGS)

make-matrix: make-matrix.o functions.o
	$(CC) $(LDFLAGS) -o make-matrix make-matrix.o functions.o

print-matrix: print-matrix.o functions.o
	$(CC) $(LDFAGS) -o print-matrix print-matrix.o functions.o

mm-serial: mm-serial.o functions.o
	$(CC) $(LDFLAGS) -o mm-serial mm-serial.o functions.o

make-matrix.o: make-matrix.c
	$(CC) $(CFLAGS) -c make-matrix.c

print-matrix.o: print-matrix.c
	$(CC) $(CFLAGS) -c print-matrix.c

mm-serial.o: mm-serial.c
	$(CC) $(CFLAGS) -c mm-serial.c

clean:
	rm -f $(PROGS) *.o core* *.~
	rm -f *.o
