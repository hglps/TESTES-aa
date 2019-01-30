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

void sort_up(node *head, node *aux)/// crescente
{
	if(head->item > aux->item)
	{
		int auxiliar = head->item;
		head->item = aux->item;
		aux->item = auxiliar;
	}
}
void sort_down(node *head, node *aux) /// decrescente
{
	if(head->item < aux->item)
	{
		int auxiliar = head->item;
		head->item = aux->item;
		aux->item = auxiliar;
	}
}
void sort_item(node *head, int up_or_down)
{
	while(head != NULL)
	{
		node *aux = head;
		while(aux != NULL)// bbsort
		{
			up_or_down ? sort_up(head, aux) : sort_down(head, aux);
			aux = aux->next;
		}
		head = head->next;
	}
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

void print_front(node *list)
{ 
	while(1)/// 
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

void print_back(node *list)
{
    while(1)
    {
        printf("%d ", list->item);
        list = list->previous;
        
        if(list->previous == NULL) break;
    }
}

int find_item(node *head, int item)
{
    if(head->item == item) return 1;
    if(head == NULL) return 0;
    find_item (head->next, item);
}

node* remove_front(node *head, int item) /// remove apenas 1 por vez, mesmo que seja igual.
{
	node *curr = head;
	while(curr != NULL && curr->item != item) curr = curr->next;
	
	if(curr == NULL) return head;
	
	if(head == curr) head = curr->next;
	else curr->previous->next = curr->next;
	
	if(curr->next != NULL) curr->next->previous = curr->previous;
	
	free(curr);
	return head;
	
	//testar depois com find_back e front
	
}

node* remove_back(node *head, int item)/// parece inutil '-'
{
	node *curr = head;
	while(curr != NULL && curr->item != item) curr = curr->previous;
	
	if(curr == NULL) return head;
	
	if(head == curr) head = curr->previous;
	else curr->next->previous = curr->previous;
	
	if(curr->previous != NULL) curr->previous->next = curr->next;
	
	free(curr);
	return head;
	
}

void main()
{
	node* list = create_list();
	int n,i=0;
	node* tail;
	
	while(scanf("%d", &n) != EOF)
	{
		list = add_general(list,n);
		if (i==0)
		{   tail=list; i++; }
	}
    
    	sort_item(tail, 1); // crescente~~ 0 para decrescente; refazer;
	print_front(tail);
	

	free(list);
	free(tail);
}
