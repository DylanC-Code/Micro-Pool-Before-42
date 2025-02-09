all: day8.exe
	./day8.exe

day8.exe: day8.o
	gcc -o day8.exe day8.o -lm

day8.o: day8.c
	gcc -c day8.c

clean:
	rm *.o *.exe