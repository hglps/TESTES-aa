#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
	int item;
	node *previous;
	node *next;
};

node* createLIST()
{
	return NULL;
}

node* add_at_begg(node *head, int item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	new_node->previous = NULL; /// *** analyze;
	if(head!= NULL) head->previous = new_node;

	return new_node;
}


/// ......
