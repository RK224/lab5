#include "stack.h"

stack* newStack(int maxHeight){
	stack* s = (stack*)malloc(sizeof(stack));
	s->fNode = s->lNode = NULL ;
	s->maxHeight = maxHeight ;
	s->size = 0 ;
	return s ;
}

int size(stack* s){
	return s->size ;
}

node* newNode(element* e){
	node* nNode = (node*)malloc(sizeof(sizeof(node)));
	nNode->e = *e ;
	nNode->pNext = NULL ;
	return nNode ;
}

element* newElement(key* k){
	element* e = (element*)malloc(sizeof(element));
	e->k = *k ;
	return e ;
}

key* newKey(int data){
	key* k = (key*)malloc(sizeof(key));
	k->data = data ;
	return k ;
}
void push(stack* s, element* e){
	if(s->size == s->maxHeight){
	 	printf("stack is full.cannot add any more elements\n\n");
		return ;
	}else{
		node* nNode = newNode(e);
		if(s->fNode == NULL){
			s->fNode = s->lNode = nNode ;
			s->size = 1 ;
		}else{
		nNode->pNext = s->fNode ;
		s->fNode = nNode;
		s->size++ ;
		}
		printStack(s);
		return ;
	}
}


void printStack(stack* s){
	node* pNode = s->fNode ;
	printf("stack :\n");
	while(pNode!= NULL){
		printf("%d\n",pNode->e.k.data);
		pNode=pNode->pNext;	
}
	printf("\n\n");


}

element* pop(stack* s){
	if(!isEmpty(s)){
	node* pNode = s->fNode ;
	s->fNode = s->fNode->pNext ;
	s->size-- ;
	printf("popped ---> %d\n",pNode->e.k.data);
	return &(pNode->e);
	}
}

int isEmpty(stack* s){
	if(s->size == 0) return 1 ;
	else return 0 ;
}

int isFull(stack* s){
	if(s->size == s->maxHeight)	return 1 ;
	else return 0 ;
}
