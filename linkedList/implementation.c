#include "interface.h"

list newList(){
	list* pList = (list*)malloc(sizeof(list));
	pList->pStart = pList->pEnd = NULL ;
	pList->length = 0;
	return *pList;
	
}

node *newNode(int number){
	node* pNode = (node* )malloc(sizeof(node));
	pNode->data = number ;
	pNode->pNext = NULL ;
	return pNode ;
}

list insertAtBeginning(list l , int data){
	node* nNode = newNode(data);
	if(l.length == 0){
		l.pStart = l.pEnd = nNode ;		
	}else{
	nNode->pNext = l.pStart ;
	l.pStart = nNode ;
	}
	l.length++ ;
	return l ;
	
}

list insertAtEnd(list l , int data){
	node *nNode = newNode(data);
	if(l.length == 0){
		l.pStart =l.pEnd = nNode ;
	}else{
	l.pEnd->pNext = nNode ;
	l.pEnd = nNode ;
	}
	l.length++;
	return l ;
	
}	

list insertInOrder(list l , int data){
	node* nNode = newNode(data);
	node* pNode = l.pStart ;
	if(l.length == 0){
		l = insertAtBeginning(l,data);
		l.pEnd = l.pStart ;
		return l ;		
	}else if(l.pStart->data > data){
		l = insertAtBeginning(l,data);
		return l ;
	
	}else{
		while(pNode->pNext != NULL){
			if((pNode->pNext)->data < data){
				pNode = pNode->pNext ;
			}else{
				nNode->pNext = pNode->pNext ;
				pNode->pNext = nNode ;
				l.length++ ;
				return l ;
			}
		}
		l = insertAtEnd(l,data);
		return l ;
		}
}

list deleteAtFront(list l){
	l.pStart = l.pStart->pNext ;
	l.length -- ;
	return l ;
}

list delete(list l ,int data){
	node* pNode = l.pStart ;
	if(pNode->data == data){
		l = deleteAtFront(l);
		printf("\n%d deleted from the list.",data);
		return l ;
	}else{
		while(pNode->pNext != l.pEnd){
			if(pNode->pNext->data == data)
				break ;
			else{
				pNode = pNode->pNext ;
			}
		}
		if(pNode->pNext == l.pEnd){
			if(pNode->pNext->data == data){
				pNode->pNext == NULL ;
				l.pEnd == pNode ;
				l.length -- ;
		printf("\n%d deleted from the list.",data);
				return l ;	
			}else {
				printf("\n%d not in the list.",data);
				return l ;
			}
			
			}else{
				pNode->pNext = pNode->pNext->pNext ;
				l.length -- ;
		printf("\n%d deleted from the list.",data);
				return l ;
			
			}
		
	}

}
node* find(list l , int data){
	node* pNode = l.pStart ;
	while(pNode->pNext != NULL){
		if(pNode->data == data){ return pNode ;}
		else{
			pNode = pNode->pNext ;
		}
}
	if(pNode->data == data){
		return pNode;
		}
	return NULL ;
}



void printList(list l){
	printf("size of the list : %d\n",l.length);
	printf("first node : %d\n",((l.pStart)->data));
	printf("last node : %d\n",((l.pEnd)->data));
	node* pNode = l.pStart ;
	while(pNode->pNext != NULL){
		printf("%d " , pNode->data);
		pNode = pNode->pNext ;	
	}
		printf("%d\n" , pNode->data);
}

int min(list l){
	node* pNode = l.pStart ;
	int min = l.pStart->data ;
	while(pNode != NULL){
		if(pNode->data < min){
			min = pNode->data;
		}
		pNode = pNode->pNext ;
	}
	//printf("%d",min);
	return min ;
	
	

}
