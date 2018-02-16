#include "que.h"

Queue* newQ(){
	Queue* pQ = (Queue*)malloc(sizeof(Queue));
	pQ->fNode = pQ->lNode = NULL ;
	pQ->length = 0 ;
	return pQ ;
	

}

int isEmptyQueue(Queue* q){
	if(q->length == 0) return 1 ;
	else return 0 ;

}

Queue* delQ(Queue* q){
	q->fNode =  q->fNode->pNext ;
	q->length -- ;
	return q ;

}

element front(Queue* q){
	return q->fNode->e ;

}

Queue* addQ(Queue* q , element e){
	node* pNode = (node*)malloc(sizeof(node));
	pNode->e = e ;
	if(q->length == 0){
		q->fNode =  q->lNode = pNode;
		q->length = 1;
		return q ;
	}
	q->lNode->pNext = pNode ;
	q->lNode = pNode ;
	q->length ++ ;
	return q ;

}

int lengthQ(Queue* q){
	return q->length ;
}

element newEle(int data){
	element* e = (element*)malloc(sizeof(element));
	e->data = data ;
	return *e ;
}
void printQ(Queue* q){
 	 node* pNode = q->fNode ;
	 while(pNode != NULL){
       		 printf("%d ",pNode->e.data);
       		 pNode = pNode->pNext;
}

}
