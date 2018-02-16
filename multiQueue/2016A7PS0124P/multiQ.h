#include "que.h"

typedef element TaskID;
typedef struct MultiQ{
	Queue** list;
	int length ;
}multiQ;

typedef struct Task{
	TaskID tID ;
	int priority ;
}task;

multiQ createMQ(int num);
multiQ addMQ(multiQ mq , task t);
task* nextMQ(multiQ mq);
task newTask(int taskID , int priority);
multiQ delNextMQ(multiQ mq);
void printMQ(multiQ mq);
int isEmptyMultiQ(multiQ mq);
int sizeMQ(multiQ mq);
int sizeMQbyPriority(multiQ mq,int priority);
Queue* getQueueFromMQ(multiQ mq , int priority);
multiQ loadData(multiQ mq ,char* filename);
multiQ testDel(multiQ mq ,int num);
