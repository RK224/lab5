#include <stdio.h>
#include <stdlib.h>
//extern int size = 0 ;
typedef struct creditCard{
	long long creditCardNo ;
	char* bankCode ;
	char* expiryDate ;
	char* fName ;
	char* lName ;

}creditCard;

void printAccounts(creditCard* cards , int noOfRecords);
creditCard* readRecordsAndStore(char* filename);
void insertInOrder(creditCard* cards ,int size , creditCard card);
void insertionSort(creditCard* cards ,int size);
void test(char* filename,int noOfRecords);
