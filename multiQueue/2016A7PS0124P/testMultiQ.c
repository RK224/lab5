#include "multiQ.h"

multiQ loadData(multiQ mq ,char* filename){
	FILE* f = fopen(filename,"r");
	int a ,b ;
	while(fscanf(f,"%d,%d",&a,&b) != EOF){
		task t = newTask(a,b);
		mq = addMQ(mq,t);
	}
	return mq ;
}

multiQ testDel(multiQ mq ,int num){
	for(int i = 0 ; i < num ; i++){
		mq = delNextMQ(mq);
	}		
	return mq ;

} 
