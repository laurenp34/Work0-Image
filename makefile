all: picmaker.o
	gcc -o makepic picmaker.o

picmaker.o: picmaker.c picmaker.h
	gcc -c picmaker.c

run:
	./makepic
	convert pic.ppm pic.png
