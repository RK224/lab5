#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#define K 64
int noOfFiles ;
element* readFileAndStore(char* filename){
	int size = 10 ;
	i = 0 ;
	element* students = (element*)malloc( size * sizeof(element));
	FILE* ifp = fopen(filename,"r");
	if(ifp != NULL){
		while(fscanf(ifp,"%m[^ ,],%f\n",&students[i].studentName,&students[i].k.data) != EOF){
			i++ ;
			if(i == size){
				size *= 2 ;
				element* pTemp = NULL ;
				pTemp = (element*)realloc(students,size*sizeof(element));
				if(pTemp != NULL){
					students = pTemp;
				}else{	
					break ;
				}
				
			}
	}
	}
	fclose(ifp);
	return students ;
}

void printStudents(element* students, int size,char* fileName){
	FILE* ofp = fopen(fileName,"w");
	for(int i = 0 ; i < size ; i++){
		fprintf(ofp,"%s,%f\n",students[i].studentName,students[i].k.data);
	}
	fclose(ofp);
	return ;
}

void readLargeAndSort(char* filename){
	int k = K ;
	element* students = (element*)malloc(sizeof(element)*k);
	FILE* ifp = fopen(filename,"r");
	int i = 0 , fileNo = 0 ;
	while(!feof(ifp)){
		if( i < k ){
			fscanf(ifp,"%m[^ ,],%f\n",&students[i].studentName,&students[i].k.data);
			i++ ;
		}
		if( i == k){
			mergeSortRec(students,0,k-1);
			i = 0 ;
			char* filename = (char*)malloc(sizeof(char)*15);
			sprintf(filename,"temp%i.txt",fileNo);
			printStudents(students,k,filename);
			fileNo ++ ;
			noOfFiles++ ;
	}
	}
	fclose(ifp);
	return ;	
}

void mergeFiles(char* file1, char* file2 , char* outputFile){
	FILE* ifp1 = fopen(file1,"r");
	FILE* ifp2 = fopen(file2,"r");
	FILE* ofp = fopen(outputFile,"w");
	char *name1 ,*name2 ;
	float cgpa1,cgpa2 ;
	fscanf(ifp1,"%m[^ ,],%f\n",&name1,&cgpa1);
	fscanf(ifp2,"%m[^ ,],%f\n",&name2,&cgpa2);
	while(!feof(ifp1) && !feof(ifp2)){
		if(cgpa1 < cgpa2){
			fprintf(ofp,"%s,%f\n",name1,cgpa1);
			fscanf(ifp1,"%m[^ ,],%f\n",&name1,&cgpa1);
		}else{
			fprintf(ofp,"%s,%f\n",name2,cgpa2);
			fscanf(ifp2,"%m[^ ,],%f\n",&name2,&cgpa2);
		}

	}
	while(!feof(ifp1)){
			fscanf(ifp1,"%m[^ ,],%f\n",&name1,&cgpa1);
						fprintf(ofp,"%s,%f\n",name1,cgpa1);
			
	}
	while(!feof(ifp2)){
			fscanf(ifp2,"%m[^ ,],%f\n",&name2,&cgpa2);
						fprintf(ofp,"%s,%f\n",name2,cgpa2);
			
	}
	fclose(ifp1);
	fclose(ifp2);
	fclose(ofp);
	return ;
}
void sort(char* fName){
	readLargeAndSort(fName);
	FILE* ofp = fopen("output.txt","r+");
	fclose(ofp);
	for(int i = 0 ; i < noOfFiles ; i++){
		char f1[15];
		sprintf(f1,"temp%i.txt",i);
		mergeFiles("output.txt",f1,"output.txt");

}
}

