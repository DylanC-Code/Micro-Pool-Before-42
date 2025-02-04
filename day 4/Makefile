all: day4.exe
	./day4.exe "Jambon Beurre"

day4.exe: day4.o
	gcc -o day4.exe day4.o

day4.o: day4.c
	gcc -c day4.c

clean: 
	rm *.o *.exe