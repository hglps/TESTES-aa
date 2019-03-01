#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE 100000
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

int del(hash *hs, int item, int size, int *cont)
{
    int key = item % size;
    int *n = cont;
    node *find = hs->table[key];
    if(has( find, item, n))
    {
        cont = n;
        node *previous = NULL;
        node *current = find;
        while (current != NULL && current->item != item)
        {
          previous = current;
          current = current->next;
        }
        if (current == NULL) return 0;
        if (previous == NULL) find = current->next;
        // else
        // {
        //   previous->next = current->next;
        //   return 1;
        // }
        else ////// ***************
        {
          node *auxfront = current->next;
          node *auxback = previous;
          previous = auxback;
          current = auxfront;
          return 1;
        }
        free(current);
        //return 1;
    }
    else
    {
      cont = n;
      return 0;
    }
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

int prt(hash *hs, int size)
{
  int i=0, cont=0,maior=0;
  node *find;
  for(i=0;i<size;i++)
  {
    find = hs->table[i];
    while(find != NULL)
    {
      cont++;
      find = find->next;
    }
    if(cont >= maior) maior = cont;
    cont = 0;
  }

  return maior;

}

int size_node(node *list) /// return size of node
{
    node *n = list;
    int cont=0;
    while(n!=NULL)
    {
        cont++;
        n = n->next;
    }
    return cont;
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

hash* rehash(hash *hs, int size)
{
    hash *new_hash = create_hash(2*size-1);
    int i,j,op=0;
    int new_size = 2*size - 1;
    for(i=0;i<size;i++)
    {
        if(hs->table[i]!= NULL)
        {
            for(j=0;j<size_node(hs->table[i]);j++)
            {
                put(new_hash,hs->table[i]->item, new_size, &op);
                hs->table[i] = hs->table[i]->next;
            }
        }
    }
    return new_hash;
}

void main()
{
  hash *h_table = create_hash(7);
  int size_hash=7;
  int i=0;
  float op=0;
  int quant_terms=0;
  int num,h,operations=0;
  char word[4];
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
      if(op >= 0.75)
      {
        h_table = rehash(h_table,size_hash);
        size_hash = 2*(size_hash) - 1;
      }
      operations = 0;

    }
    else if(!strcmp(word,"HAS"))
    {
      scanf("%d\n", &num);
      h = num % size_hash;
      if(has(h_table->table[h], num, &operations)) printf("%d 1 %d\n", i, operations);
      else printf("%d 0 %d\n", i, operations);
      operations = 0;
    }
    else if(!strcmp(word,"DEL"))
    {
        scanf("%d\n", &num);
        if(del(h_table,num,size_hash,&operations)) printf("%d 1 %d\n", i, operations);
        else printf("%d 0 %d\n", i, operations);
        quant_terms--;
        operations = 0;
    }
    else if(!strcmp(word,"PRT"))
    {
      printf("%d %d %d %d\n", i, size_hash, quant_terms, prt(h_table,size_hash));
      operations = 0;
    }

    i++;
  } /// end of while

  free(h_table);
}
