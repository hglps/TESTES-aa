#include <stdio.h>
#include <stdlib.h>
/// to be finished..
struct node
{
  void *item;/// generic item; pointer to any type
  node *next;
};
/// searching with Higher Order function;
/// must declare all the possible functions;
/// while it isn't on the last position...
/// keep changing the HEAD to the next one and analyzing each item;
/// if the item is found, return the actual "position" of the item;****to_be_finished****
node* search(node *head, void *item, int (*equal)(void *item1, void *item2))
{
  while (head != NULL)
  {
    if((*equal) (head->item, item)) return head;
    head = head->next;
  }
  return NULL;
}
/// begin explanation later..****to_be_finished****
node* add_at_begg(node *head, void *item)
{
  node *new_node = (node*) malloc(sizeof(node));
  new_node->item = item;
  new_node->next = head;
  return new_node;
}
