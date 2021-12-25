CC=gcc
CFLAGS=-c -Wall
all:makeBP3 clean run

makeBP3: main.o islemler.o
	$(CC) main.o islemler.o -o BP3Proje2

main.o:main.c
	$(CC) $(CFLAGS) main.c
islemler.o: islemler.c islemler.h
	$(CC) $(CFLAGS) islemler.c
clean:
	del *.o
run:
	BP3Proje2.exe