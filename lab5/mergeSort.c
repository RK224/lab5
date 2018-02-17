#include "element.h"
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


void mergeSortItr(element *ls , int low , int high){
	int size = high - low + 1 ;
	for( int slSz = 1 ; slSz < size ; slSz*=2){
		int no = (size/(2*slSz));
		for(int i = 0 ; i < no ; i++){
			element* lh = ls + low + 2*slSz*i ;
			element* rh = ls + low +(2*i + 1)*slSz ;
			element* ls_temp = (element*)malloc(sizeof(element)*(min(2*slSz,size - 2*slSz)));
			merge(lh,slSz,rh,min(slSz,size-(2*i + 1)*slSz),ls_temp);
			memcpy(lh,ls_temp,sizeof(element)*min(2*slSz,size - 2*slSz));
	}
}
