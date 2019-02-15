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

int pop(stack *st)
{
	if(empty(st)) { printf("STACK UNDERFLOW\n"); return -1;}
	int it = st->top->item;
	st->top = st->top->next;
	st->top->next = NULL;
	return it;
}

int peek(stack *st)
{
	if(empty(st)) { printf("STACK UNDERFLOW\n"); return -1;}
	return st->top->item;
}

void main()
{
	int n,i,j;
	char ch[256];
	scanf("%d\n", &n);
	for(i=0;i<n;i++)
	{
		char ch[256];
		gets(ch);
		for(j=0;j<strlen(ch);j++)
		{
			if(ch[j] != ' ')
			{
				stack//// FINISH LATER ON LAPTOP
			}
		}
	}
}
