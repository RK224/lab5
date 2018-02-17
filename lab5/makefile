dummy : fileIO.o mergeSort.o dummy.o
	gcc -p -g fileIO.o mergeSort.o dummy.o -o mergeSort

fileIO.o : fileIO.c student.h
	gcc -p -g -c fileIO.c

mergeSort.o : mergeSort.c element.h mergeSort.h student.h
	gcc -p -g -c mergeSort.c

dummy.o : dummy.c fileIO.c mergeSort.c mergeSort.h
	gcc -p -g -c dummy.c

clean : 
	rm -rf mergeSort fileIO.o mergeSort.o dummy.o temp*.txt


