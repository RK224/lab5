#include "alloc.h"
#include <stdio.h>
#include <time.h>

typedef struct node{
	long data ;
	struct node* pNext ;
}node ;
typedef struct list{
	node* fNode ;
	node* lNode ;
	long long length ;
}list ;

list* createList(long N);
int main(void){
	list* ls = createList(1000000000);
}

list* createList(long N){
	srand(time(0));
	list* l = (list*)(myAlloc(sizeof(list))->p);
	//printf("created list\n");
	l->fNode = l->lNode = NULL ;
	l->length = 0 ;
	for( long i = 0 ; i < N ; i++){
		mem* pMem = myAlloc(sizeof(node));
		if(pMem != NULL){
		node* nNode = (node*)(pMem->p);
		//printf("created node.\n");
		nNode -> data = rand();
		if( i == 0){
			l->lNode = l->fNode = nNode ;
			l->lNode->pNext = NULL ;
			l->length = 1 ;
		}else{
			l->lNode->pNext =  nNode ;
			l->lNode = nNode ;
			l->lNode->pNext = NULL ;
			l->length++ ;
		}
		//printf("memory allocated : \t%lld\n",memoryAllocated);
	}else{
		FILE* fptr = fopen("output.txt","w");
		if(fptr == NULL){
		printf("memory allocated : \t%lld\n",memoryAllocated);
		}else{
			fprintf(fptr,"%d",memoryAllocated);
			fclose(fptr);
		}
		return l ;
	}
	}
	FILE* fptr = fopen("output.txt","w");
                if(fptr == NULL){
                printf("memory allocated : \t%lld\n",memoryAllocated);
                }else{
                        fprintf(fptr,"%d",memoryAllocated);
                        fclose(fptr);
                }

	return l ;
}
