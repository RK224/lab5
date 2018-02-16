#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
	int data ;
}element ;

typedef struct Node{
	element e ;
	struct Node* pNext ; 	
	
}node;

typedef struct queue{
	node* fNode ;
	node* lNode ;
	int length ;
}Queue;

Queue* newQ();
int isEmptyQueue(Queue* q);
Queue* delQ(Queue* q);
element front(Queue* q);
Queue* addQ(Queue* q , element e);
int lengthQ(Queue* q);
element newEle(int data);
void printQ(Queue* q);
