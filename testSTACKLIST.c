#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// STACK USING LINKED LIST no improviso com array por hora
typedef struct node node;
typedef struct stack stack;
#define MAX_SIZE 500
struct node
{
	int item;
	node *next;
	node *previous;
};
struct stack
{
	node *top;
	node *LLLL;
	node *tail;
};

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

node* create_list()
{
	return NULL;
}

int empty(stack *st)
{
	return (st->top == NULL);
} 

//void push(stack *st, int item)
//{
//	node *new_node = malloc(sizeof(node));
//	new_node->item = item;
//	new_node->next = st->top; 
//	st->top = new_node;
//}


node* add_general(node *head, int item)
{	
	node* new_node = (node*)malloc(sizeof(node));
	new_node->item = item;	
	new_node->next = NULL;
	new_node->previous = head;
	head->next = new_node;
	if(head!=NULL) head=new_node;
	return new_node;
}


//int pop(stack *st)
//{
//	if(empty(st)) {  printf("STACK UNDERFLOW\n"); return -1; }	
//	int it = node->item;
//	st->top = node->next;
//	node->next = NULL;
//	return it;
//}
//
//int peek(stack *st)
//{
//	if(empty(st)) { printf("STACK UNDERFLOW\n")/ return -1;}
//	
//	return node->item;
//}

void main()
{
	stack *stack1 = create_stack();
    int n,num,i=0;
    char trash;
    while(1)
    {
    	char word[500] ={ "\0" };
    	gets(word);
    	if(word[0] == '\0') break;
    	
        if(!strcmp(word,"PUSH"))
        {
        	stack1->LLLL = create_list();
        	while(1)
        	{
        		scanf("%d", &num); scanf("%c", &trash);
        		if(trash == '\n') break;
        		stack1->LLLL = add_general(stack1->LLLL, num);
        		if(i==0) { stack1->tail = stack1->LLLL; i++;}
        	}
        	i=0;
        } 
        
    }
    int x= 5; /////////// TA EMPTY PQP KRL EU VO MATA ALGUEM tem q fix later
    while(x--)
    {
    	printf("%d", stack1->tail->item);
    	stack1->tail->next;	
    }
    
    
	free(stack1);
	//free(list);
}
