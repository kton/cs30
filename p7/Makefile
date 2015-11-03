family.out : main.o file.o vector.o search.o
	gcc -Wall -g main.o file.o vector.o search.o -o family.out

main.o : main.c
	gcc -Wall -c main.c

file.o : file.c file.h
	gcc -Wall -c file.c

vector.o : vector.c vector.h
	gcc -Wall -c vector.c

search.o : search.c search.h
	gcc -Wall -c search.c

clean :
	rm -f family.out main.o file.o vector.o search.o