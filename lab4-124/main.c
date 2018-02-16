#include "bank.h"
#include <string.h>
#include "alloc.h"

int main(int argc , char* argv[]){
	if(argc  != 3){
		printf("usage : %s filename noOfrecordsInTheFile\n\n",argv[0]);
		return 1 ;
	}
	char* filename = argv[1];
	int noOfRecords = atoi(argv[2]);
	test(filename , noOfRecords);
	return 0 ;

}

