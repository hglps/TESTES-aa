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
		list = list->next;
		
	    if (list->next==NULL) 
	    {
	        printf("%d ",list->item);
	        break;
	    }
		
	}
}

node* remove_item(node *list, int item)
{
	
}

void main()
{
	node* list = create_list();
	int n,i=0;
	node* tail;
	//scanf("%d", &n);
	while(scanf("%d", &n) != EOF)
	{
		list = add_general(list,n);
		if (i==0) 
		{   tail=list; i++; }
	}

	print_list(tail);

	free(list);
	free(tail);
}

