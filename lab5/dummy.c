#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
int main (void){
	element* students = readFileAndStore("10.txt",10);
	printStudents(students,10);
	mergeSortItr(students,0,9);
	printf("\n\n sorted lists of students : \n\n");
	printStudents(students,10);
}
