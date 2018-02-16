#include "stack.h"

int main(void){
	stack* s = newStack(10);
	printf("max height of the stack = %d\n",s->maxHeight);
	push(s,newElement(newKey(2)));
        push(s,newElement(newKey(1)));
        push(s,newElement(newKey(12)));
        push(s,newElement(newKey(4)));
        push(s,newElement(newKey(7)));
        push(s,newElement(newKey(13)));
	push(s,newElement(newKey(5)));
        push(s,newElement(newKey(7)));
        push(s,newElement(newKey(9)));
        push(s,newElement(newKey(31)));
        push(s,newElement(newKey(17)));
        push(s,newElement(newKey(23)));
        push(s,newElement(newKey(19)));
	element* e = pop(s);
	printStack(s);
	for(int i = 0 ; !isEmpty(s) ; i++){
		e = pop(s);
		printStack(s);
	}


	printf("is Full : %d\n",isFull(s));
	printf("is Empty: %d\n",isEmpty(s));

}
