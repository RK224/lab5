#include <stdio.h> 
#include "alloc.h"
#include <time.h>
#include <stdlib.h>
#define N 1000
void allocX();
int main(void){
	srand(time(0));
	allocX();
	
}

void allocX(){
	
	long long m = rand()%15000 + 100000000;
	printf("addm%u\n", &m);
	fflush(stdout);
	mem* pMem = myAlloc(m);
	if(pMem != NULL){
		int* pIntArr = (int*)(pMem->p);
        	printf("memory allocated : %lld\n",memoryAllocated);
		for(int i=0;i<N;i++);
		allocX();
		myFree(pMem->p);
	        printf("memory allocated : %lld\n",memoryAllocated);

	}else{
		return ;
	}
}
