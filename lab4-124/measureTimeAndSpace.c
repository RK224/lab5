#include "bank.h"
#include "alloc.h"
#include <sys/time.h>
void test(char* filename,int noOfRecords)
{
	struct timeval t1,t2 ;
	long double elapsedTime = 0 ;
	long double time  = 0 ;
	FILE* ofp = fopen("usage-profile","w");
	
	gettimeofday(&t1,NULL);
	creditCard* cards = readRecordsAndStore(filename);
    gettimeofday(&t2,NULL);
	time = (t2.tv_usec - t1.tv_usec)/1000.0 ;
	elapsedTime += time ;
	fprintf(ofp,"Time taken to read records : %Lf ms\n",time);
	fprintf(ofp,"Memory allocated : %lld bytes\n",memoryAllocated);
	
	gettimeofday(&t1,NULL);
	printAccounts(cards,noOfRecords);
	gettimeofday(&t2,NULL);
	time = (t2.tv_usec - t1.tv_usec)/1000.0 ;

	elapsedTime += time ;
	fprintf(ofp,"Time taken to print records : %Lf ms\n",time);
	
	gettimeofday(&t1,NULL);
	insertionSort(cards,noOfRecords);
	gettimeofday(&t2,NULL);
	time = (t2.tv_sec - t1.tv_sec)*1000 ;

	//time = (t2.tv_usec - t1.tv_usec)/1000.0 ;
	
	elapsedTime += time ;
	fprintf(ofp,"Time taken to sort records : %Lf ms\n",time);
	
	gettimeofday(&t1,NULL);
	printAccounts(cards,noOfRecords);
	gettimeofday(&t2,NULL);
	time = (t2.tv_usec - t1.tv_usec)/1000.0 ;
	elapsedTime += time ;
	fprintf(ofp,"Time taken to print records : %Lf ms\n",time);
	fprintf(ofp,"Total time elapsed : %Lf ms\n",elapsedTime);
	fclose(ofp);
	free(cards);
	elapsedTime = 0 ;
	return ;
}
