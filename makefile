all: work15.o
	gcc -o work15m work15.o

nov1.o: work15.c
	gcc -c work15.c

run:
	./work15m

clean:
	rm *.o
	rm work15m
