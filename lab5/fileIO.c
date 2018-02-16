#include <stdio.h>
#include "student.h"
#include <stdlib.h>

element* readFileAndStore(char* filename , int noOfRecords){
	element* students = (element*)malloc(noOfRecords * sizeof(element));
	FILE* ifp = fopen(filename,"r");
	if(ifp != NULL){
		int i = 0 ;
		while(fscanf(ifp,"%m[^ ,],%f\n",&students[i].studentName,&students[i].k.data) != EOF){
			i++ ;
	}
	}
	return students ;
}

void printStudents(element* students, int size){
	for(int i = 0 ; i < size ; i++){
		printf("Student name : %s | CGPA : %.2f\n",students[i].studentName,students[i].k.data);
	}
	return ;
}
