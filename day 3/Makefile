all: day3.exe
	./day3.exe 15

day3.exe: day3.o formulas.o
	gcc -o day3.exe day3.o formulas.o

day3.o: day3.c formulas.h
	gcc -c day3.c

formulas.o: formulas.c formulas.h
	gcc -c formulas.c

clean:
	rm day3.c day3.exe