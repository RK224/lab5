#include "element.h"
#include "mergeSort.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void merge(element* ls1 , int size1 , element* ls2 , int size2 , element* ls){
	int i , j , k ;
	i = j = k = 0 ;
	while(i < size1 && j < size2){
		if(ls1[i].k.data < ls2[j].k.data){
			//strcpy(ls[k].studentName,ls1[i].studentName);
			ls[k++] = ls1[i++] ;
		}else{
			//strcpy(ls[k].studentName,ls2[j].studentName);
			ls[k++] = ls2[j++] ;
		}
	}
	element* lsTemp = NULL ;
	int size , n ;
	if( i == size1 ){
		lsTemp = ls2 ;
		size = size2;
		n = j ;
	}else{
		lsTemp = ls1 ;
		size = size1 ;
		n = i ;
	}
	for(;n<size;n++){
		ls[k++] = lsTemp[n] ;
	}

	return ;
}

void mergeSortRec(element* ls,int low , int high){
	int size = high - low + 1 ;
	if(size <=1 ) return ;
	else{
		int mid = (high + low) / 2 ;
		mergeSortRec(ls,low,mid);
		mergeSortRec(ls,mid+1,high);
		element *ls_temp = (element*)malloc(sizeof(element)*(high-low+1));
		//printf("%p\n",ls_temp);
		//fflush(stdout);		
		merge(ls+low, mid - low + 1 , ls+mid+1 , high - mid, ls_temp );
		memcpy(ls+low,ls_temp,sizeof(element)*(high - low + 1));
		free(ls_temp);
		
	}
}

int min(int a, int b){
	return (a<b)?a:b;
}

void mergeSortItr(element* ls,int low , int high){
	int n = high - low + 1 ;
	element* ls_temp = (element*)malloc(sizeof(element)*(n));
	int j, slSz;
	for(slSz = 1,j=0 ; slSz < n ;slSz*=2,j++ ){
	if(j%2==0){
	element *arrL_start=ls+low, *arrR_start=ls+low+slSz;
		for(;arrR_start <= ls+high;arrL_start+=2*slSz, arrR_start+=2*slSz){	
			merge(arrL_start , slSz , arrR_start , min(slSz,ls+high-arrR_start) , ls_temp+(arrL_start-ls));
		}
	}
	else{
		element *arrL_start=ls_temp+low, *arrR_start=ls_temp+low+slSz;
		for(;arrR_start <= ls_temp+high;arrL_start+=2*slSz, arrR_start+=2*slSz){	
			merge(arrL_start , slSz , arrR_start , min(slSz,ls+high-arrR_start) , ls+(arrL_start-ls_temp));
		}
	}
	printf("ls->\n");
	printStudents(ls,n);
	printf("ls_temp->\n");
	printStudents(ls_temp,n);
	}
	if(j%2==0)
		memcpy(ls,ls_temp,sizeof(element)*n);
}
