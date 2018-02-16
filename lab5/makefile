dummy : fileIO.o mergeSort.o dummy.o
	gcc -g fileIO.o mergeSort.o dummy.o -o mergeSort

fileIO.o : fileIO.c student.h
	gcc -g -c fileIO.c

mergeSort.o : mergeSort.c element.h mergeSort.h student.h
	gcc -g -c mergeSort.c

dummy.o : dummy.c fileIO.c mergeSort.c mergeSort.h
	gcc -g -c dummy.c

clean : 
	rm -rf mergeSort *.o


