#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void *item;
	node *next;
}node;

int if_empty(node *head)/// if the list is empty, return the NULL
{
	return (head == NULL);
}

node* createLIST() // what it said...
{
	return NULL;
}

node* search(node *head, int item)
{
	while(head != NULL)
	{
		if(head->item) return head;
		head = head->next;
	}
	return NULL;
}

node* add_at_begg(node *head, int *item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = item;/// check void
	new_node->next = head;/// check void
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

void main()/// read numbers and print the linked list
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
	
}
