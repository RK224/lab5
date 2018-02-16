#include <stdio.h>

int main (void){
	FILE* ifp = fopen("10000","r");
	long long int creditCardNo ;
	char *bankCode, *expiryDate, *firstName , *lastName ;
	fscanf(ifp,"%lld,%m[^,],%m[^,],%m[^,],%m[^,\n]",&creditCardNo,&bankCode,&expiryDate,&firstName,&lastName);
	FILE* ofp = fopen("repeated","w");
	for(int i = 0 ; i < 80000 ; i++ ){
		fprintf(ofp,"%lld,%s,%s,%s,%s\n",creditCardNo,bankCode,expiryDate,firstName,lastName);
	}
	fclose(ofp);
}
