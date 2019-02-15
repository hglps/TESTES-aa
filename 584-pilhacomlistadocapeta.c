#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// typedef struct node node;
// typedef struct stack stack;

// struct node
// {
// 	int item;
// 	node *next;
// };
// struct stack
// {
// 	node *top;
// };

// stack* create_stack()
// 	stack *new_stack = (stack*) malloc(sizeof(stack));
// 	new_stack->top = NULL;
// 	return new_stack;
// }

// int empty(stack *st)
// {
// 	return (st->top == NULL);
// } 

// void push(stack *stack, int item)
// {
// 	node *new_node = malloc(sizeof(node));
// 	new_node->item = item;
// 	new_node->next = stack->top; 
// 	stack->top = new_node;
// }

// void add_general(node *node, int item)
// {
//     node *new_node = (node*) malloc(sizeof)
// }

// int pop(stack *st)
// {
// 	if(empty(st)) {  printf("STACK UNDERFLOW\n"); return -1; }	
// 	int it= node->item;
// 	st->top = node->next;
// 	node->next = NULL;
// 	return it;
// }

// int peek(stack *st)
// {
// 	if(empty(st)) { printf("STACK UNDERFLOW\n")/ return -1;}
	
// 	return node->item;
// }

void main()
{
	//stack *stack1 = create_stack();
    //char trash;
    //int num;
    while(1)
    {
        char word[50];
        memset(word, 0, sizeof(word));// p o sucesso
        if(scanf("%s", word) == EOF)
        {
            break;
        }
        
        if(!strcmp(word,"PUSH"))
        {
            char trash;
            int num;
            while(1)
            {
                scanf("%d%c", &num, &trash);
                printf("%d ", num);
                if(trash == '\n') break;
            }
            printf("\n");
        }
        else
        {
            //solve();// vai stack
            printf("É POP\n");
        }
    }
    
	//free(stack1);
}
