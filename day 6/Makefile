all: day6.exe
	./day6.exe

day6.exe: day6.o
	gcc -o day6.exe day6.o -lm

day6.o: day6.c
	gcc -c day6.c

clean:
	rm *.o *.exe