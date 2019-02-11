#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// STACK USING array
#define MAX_SIZE 500
typedef struct stack stack;
struct stack
{
	int item[MAX_SIZE];
	int size;
};

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->size = 0;
	return new_stack;		
} 

int empty(stack *st)
{
	return (st->size);
} 

void push(stack *stack, int item)
{
	if(stack->size == MAX_SIZE) printf("TA CHEIA JA PO!!\n");
	stack->item[stack->size++] = item;
}

void pop(stack *st)
{
	if(empty(st)) {  printf("TA VAZIA MEU CARO\n"); }	
	else
	{
		st->size--;
	} 
}

int peek(stack *st)
{
	if(empty(st)) { printf("TA CHEIA JA PO\n"); return -1;}
	
	return st->item[st->size-1];
}

void main()
{
    stack *stack= create_stack();
	stack *back = NULL;
	stack *forw = NULL;// create_stack();
	while(1)
	{
	    char frase[10] = {"\0"};
	    gets(frase);
	    if(frase[0] == '\0') break;
		if(!strcmp(frase, "ENTER"))
		{
		    push(stack,1);
		}
		else if(!strcmp(frase, "FORWARD"))
		{
		    push(back,1);
		    pop(forw);
		    
		}
		else if(!strcmp(frase, "BACK")) 
		{    
		    pop(back);
		    push(forw,1);
	    }
	}
	
	printf("BACK: %d\nFORWARD: %d\n", back->size, forw->size);
	
	free(stack);
	free(back);
	free(forw);
}
