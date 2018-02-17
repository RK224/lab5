#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include <stdint.h>
int main (int argc , char* argv[]){
	if(argc != 2){
		printf("usage : ./mergeSort filename\n");
		return 1 ;
		}
	char* filename = argv[1];
	element* students = readFileAndStore(filename);
	int size = i ;
	mergeSortItr(students,0,size -1);
	printStudents(students,size,"students.txt");
	return 0 ; 
}
