#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data ;
	struct node* pNext ;
}node;

typedef struct list{
	node* pStart ;
	node* pEnd ;
	int length ; 	
}list;

list newList();
node *newNode(int data);
list insertAtBeginning(list l , int data);
list insertAtEnd(list l , int data);
list insertInOrder(list l , int data);
list deleteAtFront(list l);
node* find(list l , int data);
list delete(list l ,int data);
void printList(list l);
list merge(list A , list B) ;
int min(list l);
list insertionSort(list l);
void test() ;
