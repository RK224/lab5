#include "bank.h"
#include "alloc.h"
creditCard* readRecordsAndStore(char* filename){
	FILE* ifp = fopen(filename,"r");
	int sizeOfTheArr = 10 ;
	creditCard* cards = (creditCard*)malloc(sizeof(creditCard)*sizeOfTheArr);
	if(ifp != NULL){
		int i = 0 ;
		while(fscanf(ifp,"%lld,%m[^,],%m[^,],%m[^,],%m[^,\n]",&cards[i].creditCardNo,&cards[i].bankCode,&cards[i].expiryDate,&cards[i].fName,&cards[i].lName) != EOF){
			i++ ;
			memoryAllocated += sizeof(creditCard);
			if(i >= sizeOfTheArr){
				sizeOfTheArr *= 2 ;
				cards = (creditCard*)realloc(cards,sizeof(creditCard)*sizeOfTheArr);
			}

		}
	}
	fclose(ifp);
	return cards ;
	

}

void printAccounts(creditCard* cards,int noOfRecords){
	FILE* ofp = fopen("credit Card Holders","w"); 
	for(int i = 0 ; i < noOfRecords ; i++){
			fprintf(ofp,"%lld,%s,%s,%s,%s\n",cards[i].creditCardNo,cards[i].bankCode,cards[i].expiryDate,cards[i].fName , cards[i].lName);
	}
	fprintf(ofp,"\n");
	fclose(ofp);
				return ;

}


