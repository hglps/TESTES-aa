#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE 1000000
typedef struct node node;
typedef struct hash hash;
struct node
{
  int item;
  node *next;
};
struct hash
{
  node *table[MAX_SIZE];
};

hash* create_hash(int n)
{
  hash *new_hash = (hash*) malloc(sizeof(hash));
  int i;
  for(i=0;i<n;i++)
  {
    new_hash->table[i] = NULL;
  }
  return new_hash;
}

int del(node *find, int item)
{
    if(has( find, item))
    {
        node *previous = NULL;
        node *current = find;
        while (current != NULL && current->item != item)
        {
          previous = current;
          current = current->next;
        }
        if (current == NULL)
          return 0;
        if (previous == NULL)
        {
          find = current->next;
        }

        else
        {
          previous->next = current->next;
          return 1;
        }
        free(current);
        return 1;
    }
    else return 0;


}

int has(node *search, int item, int *count)
{
  int *n = count;
  node *aux = search;
  while(aux != NULL)
  {
    *n +=1;
    if(aux->item == item)
    {
      count = n;
      return 1;
    }
    aux = aux->next;
  }
  return 0;
}

int put(hash *hs, int item, int size, int *cont)
{
    int key = item % size;
    int *aux = cont;
    if(hs->table[key] == NULL)
    {
      node *new_node = (node*) malloc(sizeof(node));
      new_node->item = item;
      new_node->next = NULL;
      hs->table[key] = new_node;
      *cont = 0;
      return 1;
    }
    else
    {
      if(has(hs->table[key],item,aux))
      {
        cont = aux;

        return 0;
      }
      else
      {
        cont = aux;
        node *new_node = (node*) malloc(sizeof(node));
        new_node->item = item;
        new_node->next = hs->table[key];
        hs->table[key] = new_node;
        return 1;
      }
    }
}

void print_node(node *n)
{
    node *aux = n;
    printf("LISTA==  ");
    while(n != NULL)
    {
        printf("%d ", n->item);
        n = n->next;
    }
    printf("\n");
}

void main()
{
  hash *h_table = create_hash(7);
  int size_hash=7;
  int i=0;
  float op=0;
  int quant_terms=0;
  int num,h,operations=0;
  char word[3];
  while(scanf("%s", word)!= EOF)
  {
    if(!strcmp(word,"ADD"))
    {
      scanf("%d\n", &num);
      if(put(h_table,num,size_hash,&operations))
      {
        printf("%d 1 %d\n", i, operations);
        quant_terms+=1;
      }
      else printf("%d 0 %d\n", i, operations);
      op = (float) quant_terms/size_hash;
      //printf("QUANT TERMS = %d\n", quant_terms);
      if(op >= 0.75)
      {
        //rehash(h_table); //// finish
        printf(" |||TA CHEIA FAZ REHASH||| \n");
      }
      operations = 0;

    }
    else if(!strcmp(word,"HAS"))
    {

    }
    else if(!strcmp(word,"DEL"))
    {
        scanf("%d\n", &num);
        if(del(h_table,num,size_hash,&operations)) printf("%d 1 %d\n", i, operations);
        else printf("%d 0 %d\n", i, operations);
        operations = 0;
    }


    i++;
  } /// end of while

}
