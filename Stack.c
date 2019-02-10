#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// STACK USING LINKED LIST
typedef struct node node;
typedef struct stack stack;
struct node
{
	int item;
	node *next;
} 
struct stack
{
	node *top;
}

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;		
}

int empty(stack *st)
{
	return (stack->top == NULL);
} 

void push(stack *stack, int item)
{
	node *new_node = malloc(sizeof(node));
	new_node->item = item;
	new_node->next = stack->top;
	stack->top = new_node;
}

int pop(stack *st)
{
	if(empty(st)) {  printf("STACK UNDERFLOW\n"); return -1; }	
	int it= node->item;/// save it, then delete it
	st->top = node->next;
	node->next = NULL;
	return it;	
}

int peek(stack *st)
{
	if(empty(st)) { printf("STACK UNDERFLOW\n")/ return -1;}
	
	return node->item;
}

void main()
{
	stack *stack = create_stack();
	///stuff
	///stuff
	free(stack);
}
