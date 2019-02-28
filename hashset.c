#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE 6000
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

int has(node *search, int item)
{

}

int put(hash *hs, int item, int size) /// sem verify
{
    int key = item % size;
    if(hs->table[key] == NULL)
    {
      node *new_node = (node*) malloc(sizeof(node));
      new_node->item = item;
      new_node->next = NULL;
      hs->table[key] = new_node;
      return 1;
    }
    else
    {
      if(has(hs->table[key],item)) return 0;
      else
      {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->item = item;
        new_node->next = hs->table[key];
        hs->table[key] = new_node;
        return 1;
      }
    }
}

void main()
{
  hash *h_table = create_hash(7);
  int size_hash=7;
  int i=0;
  float op=0;
  int quant_terms=0;
  int num;
  char word[3];
  while(scanf("%s", word)!= EOF)
  {
    if(!strcmp(word,"ADD"))
    {
      scanf("%d\n", &num);
      put(h_table,num,size_hash);
      quant_terms+=1;
      op = (float) quant_terms/size_hash;
      printf("QUANT TERMS = %d\n", quant_terms);
      if(op >= 0.75)
      {
        //rehash(h_table); //// finish
        printf(" |||TA CHEIA FAZ REHASH||| \n");
      }

    }
    else if(!strcmp(word,"HAS"))
    {}
    else if(!strcmp(word,"DEL"))
    {}

    i++;
  } /// end of while

}
