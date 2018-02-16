#include <stdlib.h>
#include "alloc.h"
mem* myAlloc(long long size){
	mem* pMem = (mem*)malloc(sizeof(mem));
	pMem->size = size;
	pMem->p = malloc(pMem->size);
	memoryAllocated+=pMem->size ;
	return pMem ;

}

void myFree(mem* pMem){
	memoryAllocated-=pMem->size ;
	printf("in free\n");
	free(pMem->p);
	free(pMem);
}
