all: day5.exe
	./day5.exe

day5.exe: day5.o
	gcc -o day5.exe day5.o

day5.o: day5.c
	gcc -c day5.c

clean:
	rm *.o *.exe