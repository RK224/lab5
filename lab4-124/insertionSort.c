#include "bank.h"
void insertInOrder(creditCard* cards , int size , creditCard card){
	int i = 0 ;
	while(i < size && card.creditCardNo > cards[i].creditCardNo){
		i++ ;
	}
	for(int j = size -1 ; j >= i ; j--){
		cards[j+1] = cards[j] ;
	}
	cards[i] = card ;
	return ;
	

}

void insertionSort(creditCard* cards ,int size){
	if(size == 1) return;
	else{	
		creditCard temp = cards[size-1] ;
		insertionSort(cards,size-1);
		insertInOrder(cards,size-1 , temp);
	}

}
