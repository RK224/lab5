#include "interface.h"

list merge(list A , list B){
	list l = newList() ;
	if(A.pStart->data < B.pStart->data){
		l.pStart = l.pEnd = A.pStart ;
		A.pStart = A.pStart->pNext ;
		l.length++ ;
		A.length-- ;
		/*if(A.pStart==NULL)
			A.pEnd=NULL;*/
	}else{
		l.pStart = l.pEnd = B.pStart ;
		B.pStart = B.pStart->pNext ;
		l.length++ ;
		B.length--;
		/*if(B.pStart==NULL)
			B.pEnd=NULL;*/
	}
	while(A.pStart != NULL && B.pStart != NULL){
		if(A.pStart->data < B.pStart->data){
			l = insertAtEnd(l, A.pStart->data);
		A.pStart = A.pStart->pNext ;
		A.length -- ;
		/*if(A.pStart==NULL)
			A.pEnd=NULL;*/
		}else{
			l = insertAtEnd(l,B.pStart->data);
		B.pStart = B.pStart->pNext ;
		B.length--;
		/*if(B.pStart==NULL)
			B.pEnd=NULL;*/
		}
}
	if(A.pStart == NULL){
		l.pEnd->pNext = B.pStart;
		l.pEnd = B.pEnd ;
		l.length+=B.length ;
	}else if(B.pStart == NULL){
		l.pEnd->pNext = A.pStart;
		l.pEnd = A.pEnd ;
		l.length+=A.length ;
	}
	return l ;
}

list insertionSort(list l){
	list nList = newList();
	node* pNode = l.pStart ;
	while(pNode != NULL){
		nList = insertInOrder(nList,pNode->data);
		pNode = pNode->pNext ;
		
	}
	return nList ;
}
void test(){
	list A = newList();
	A = insertAtEnd(A,4);
	A = insertAtEnd(A,1);
	A = insertAtEnd(A,8);
	A = insertAtEnd(A,10);
	A = insertAtEnd(A,41);
	A = insertAtEnd(A,2);
	A = insertAtEnd(A,21);
	printList(A);
	A = insertionSort(A);
	printf("sorted list\n");
	printList(A);
	list B = newList();
	B = insertAtEnd(B,14);
	B = insertAtEnd(B,11);
	B = insertAtEnd(B,81);
	B = insertAtEnd(B,110);
	B = insertAtEnd(B,91);
	B = insertAtEnd(B,12);
	B = insertAtEnd(B,13);
	B = insertAtEnd(B,31);
	printList(B);
	B = insertionSort(B);
	printf("sorted list\n");
	printList(B);
	printf("merging lists\n");
	printList(merge(A,B));

}

