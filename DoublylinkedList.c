#include <stdio.h>
#include <stdlib.h>
///// DOUBLY LINKED LIST
typedef struct node node;
struct node
{
	int item;
	node *next;
	node *previous;
};

node* create_list()
{
	node* blabla= (node*) malloc(sizeof(node));
	blabla->next = NULL; blabla->previous= NULL;
	blabla->item = NULL;
	return (blabla);
}

node* add_general(node *head, int item)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;///
	new_node->previous = head;
	head->next = new_node;
	
	if(head!=NULL) head=new_node;///
	return new_node;
}

void print_list(node *list)
{ 
	while(1)
	{
	    printf("%d ",list->item);
		list = list->previous;
		
	    if (list->previous==NULL) break;
		
	}
}

void main()
{
	node* list = create_list();
	int n,i;
	//scanf("%d", &n);
	while(scanf("%d", &n) != EOF)
	{
		list = add_general(list,n);
	}

	print_list(list);

	free(list);
}
