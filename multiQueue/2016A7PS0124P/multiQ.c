#include "multiQ.h"


multiQ createMQ(int num){
	multiQ mq ;
	mq.list = (Queue**)malloc(sizeof(Queue*)*num) ;
	for(int i = 0 ; i< num ;i ++){
		mq.list[i] = newQ();
	}
	mq.length = num ;
	return mq;
}	

task newTask(int taskID , int priority){
	task t ;
	t.tID = newEle(taskID);
	t.priority = priority ;
	return t ;
}

multiQ addMQ(multiQ mq , task t){
	int index = t.priority - 1 ;
	mq.list[index] = addQ(mq.list[index],t.tID);
	return mq ;

}

//returns -1 in the task priority if all empty
task* nextMQ(multiQ mq){
	if(isEmptyMultiQ(mq)){
		return NULL ;
	}
	else{
	int i = mq.length - 1 ;
	TaskID tID;
	while(i>=0 && isEmptyQueue(mq.list[i])){ i --;}
	int maxPriority = i+1 ;
	tID = front(mq.list[i]);
	task* t = (task*)malloc(sizeof(task)) ;
	t->tID = tID ;
	t->priority = maxPriority ;
	return t ;
}
}

multiQ delNextMQ(multiQ mq){
	if(isEmptyMultiQ(mq)) return mq ;
	else{
	task* maxPriorTask = nextMQ(mq);
	int maxPrior = maxPriorTask->priority ;
	mq.list[maxPrior - 1] =  delQ(mq.list[maxPrior - 1]);
	
	return mq ;
}
}

void printMQ(multiQ mq){
	for(int i = 0 ; i < 10 ; i++){
		printQ(mq.list[i]);
		printf("\n\n");
	}

}

int isEmptyMultiQ(multiQ mq){
	for(int i = 0 ; i < mq.length ; i++){
		if(!isEmptyQueue(mq.list[i])) return 0 ; 
	}
	return 1 ;
}

int sizeMQ(multiQ mq){
	int sizeMq = 0 ;
	for(int i = 0 ; i < mq.length ; i++){
		sizeMq+=sizeMQbyPriority(mq,i+1) ;
	}
	return sizeMq;
}

int sizeMQbyPriority(multiQ mq , int priority){
	return mq.list[priority - 1]->length ;
}

Queue* getQueueFromMQ(multiQ mq , int priority){
	return mq.list[priority - 1];
}
