run : measureTimeAndSpace.o insertionSort.o readRecords.o main.o
	gcc -pg measureTimeAndSpace.o insertionSort.o readRecords.o main.o -o insertionSort

measureTimeAndSpace.o : measureTimeAndSpace.c bank.h alloc.h
	gcc -pg -c measureTimeAndSpace.c

insertionSort.o : insertionSort.c bank.h
	gcc -pg -c insertionSort.c

readRecords.o : readRecords.c bank.h alloc.h
	gcc -pg -c readRecords.c
	
main.o : main.c bank.h alloc.h
	gcc -pg -c main.c
