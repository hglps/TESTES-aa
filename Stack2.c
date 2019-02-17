#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node node;
typedef struct stack stack;

struct node
{
	char item;
	node *next;
};

struct stack
{
	node *top;
};

stack* create_stack()
{
	stack* new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

int empty(stack *st)
{
	return (st->top == NULL);
}

void push(stack *st, char item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = st->top;
	st->top = new_node;
}

void pop(stack *st)
{
    node *update = (node*) malloc (sizeof(node));
	  update = st->top->next;
	  st->top->next = NULL;
    st->top = update;
}

char peek(stack *st)
{
	if(empty(st)) { /*printf("STACK UNDERFLOW\n");*/ return NULL;}/// rever relação char
	return st->top->item;
}

void main()
{
stack *st1 = create_stack();
...
}
