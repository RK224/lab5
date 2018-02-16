#include <stdio.h>
#include <stdlib.h>

typedef struct key{
	int data ;
}key;

typedef struct element{
	key k ;
}element ;

typedef struct node{
	element e ;
	struct node* pNext ;
}node; 

typedef struct stack{
	node* fNode ;
	node* lNode ;
	int maxHeight ;
	int size ;
}stack;

stack* newStack(int maxHeight);
int size(stack* s);
node* newNode(element* e);
element* newElement(key* k);
key* newKey(int data);
void  push(stack* s, element* e);
void printStack(stack* s);
element* pop(stack* s);
int isEmpty(stack* s);
int isFull(stack* s);
