#include "multiQ.h"
#include <string.h>

int main(void){
		multiQ mq = createMQ(10);
		mq = loadData(mq,"input600000.txt");
		printMQ(mq);
				printf("\nsize of the mQ = %d\n\n" , sizeMQ(mq));
		mq = testDel(mq,1000);
		printMQ(mq);
		printf("\nsize of the mQ = %d\n\n" , sizeMQ(mq));
		
		mq = testDel(mq,50000);
		printMQ(mq);
		printf("\nsize of the mQ = %d\n\n" , sizeMQ(mq));
		return 0;
		
		
	}
	
	

