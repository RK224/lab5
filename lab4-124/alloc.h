#include <stdio.h>
long long memoryAllocated ;
typedef struct mem{
	void* p ;
	int size ;
}mem ;

mem* myAlloc(long long size);
void myFree(mem* pMem);
