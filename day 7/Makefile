all: day7.exe
	./day7.exe

day7.exe: day7.o
	gcc -o day7.exe day7.o -lm

day7.o: day7.c
	gcc -c day7.c

clean:
	rm *.o *.exe