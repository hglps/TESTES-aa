#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
	int item;
	node *next;
};

int if_empty(node *head)/// if the list is empty, return the NULL
{
	return (head == NULL);
}

node* createLIST() // what it said...
{
	return NULL;
}

node* remove(node *head, int item)
{
	node *previous = NULL;
	node *current = search(head, previous, item);
	
	if(current == head) head = head->next; /// [start]
	else if( current!=head && current != NULL) previous->next = current->next; /// [middle , end]

	free(current);
	return head;
}

node* search(node *head,node *previous, int item)
{
	if(head == NULL && item== head->item) return head;
	search(head->next, head, item);
}

node* add_at_begg(node *head, int item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = item;// 
	new_node->next = head;// 
	return new_node;
}
void print_list(node *list)
{
	while(list !=NULL)
	{
		printf("%d\n", list->item);
		list = list->next;
	}
}

void main()/// set a quantity and print all the list
{
	node* list = createLIST();
	int item;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &item);
		list = add_at_begg(list, item);
	}

	print_list(list);
	
}
