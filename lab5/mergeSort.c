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
			ls[k].studentName = ls1[i].studentName ;
			ls[k].k.data = ls1[i].k.data ;
			i++;k++;
		}else{
			//strcpy(ls[k].studentName,ls2[j].studentName);
			ls[k].studentName = ls2[j].studentName ;
			ls[k].k.data = ls2[j].k.data ;
			j++;k++;
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
	    ls[k].studentName = lsTemp[n].studentName;
		ls[k].k.data = lsTemp[n].k.data ;
		k++;
	}
	free(lsTemp);
	return ;
}

void mergeSort(element* ls,int low , int high){
	int size = high - low + 1 ;
	element* ls_temp;
	if(size <=1 ) return ;
	else{
		int mid = (high + low) / 2 ;
		mergeSort(ls,low,mid);
		mergeSort(ls,mid+1,high);
		ls_temp = (element*)malloc(sizeof(element)*(high-low+1));
		//printf("%p\n",ls_temp);
		//fflush(stdout);		
		merge(ls+low, mid - low + 1 , ls+mid+1 , high - mid, ls_temp );
		for(int i = low , j=0; i <= high ; i++,j++){ 
			ls[i].k.data = ls_temp[j].k.data;
			//strcpy(ls[i].studentName,ls_temp[i].studentName);
			ls[i].studentName = ls_temp[j].studentName ;
			}
		free(ls_temp);
		
	}
}
