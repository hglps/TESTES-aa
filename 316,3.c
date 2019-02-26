#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 201
typedef struct element element;
typedef struct hash hash;
//// HASH TABLE IMPLEMENTED WITH ARRAY
struct element
{
  int content[MAX_SIZE];
  int sum;
  int last_size;
};
struct hash
{
  element *table[MAX_SIZE];
};

hash* create_hash()
{
  hash *new_hash = (hash*) malloc(sizeof(hash));
  int i;
  for(i=0;i<MAX_SIZE;i++)
  {
    new_hash->table[i] = NULL;
    new_hash->table[i]->sum = 0;
  }
  return new_hash;
}

void put_(hash *hs,int key, char *item)
{
  int h = key % MAX_SIZE,i;

  if(hs->table[0] == NULL)
  {
    element *new_element = (element*)malloc(sizeof(element));
    new_element->sum=0;
    for(i=0;i<strlen(item);i++)
    {
      new_element->content[i] = (item[i] - 65) + h + i;
    }
    hs->table[0] = new_element;
    hs->table[0]->last_size = i;
  }
  else
  {
    int j = hs->table[0]->last_size;
    for(i=j;i<(j+strlen(item)); i++)
    {
      hs->table[0]->content[i] = (item[i] - 65) + h + i;
    }
    hs->table[0]->last_size= i;
  }
}

void main()
{
  int n,i,num,line;
  char word[101];
  hash *htable;
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    scanf("%d", &num);
    htable = create_hash();
    for(line=0;line<num;line++)
    {
      scanf("%s",word);
      getchar();
      put_(htable,line,word);
      for(j=0;j<3;j++)
      {
        printf("%d ", htable->table[0]->content[j]);
      }
      break;
    }

    free(htable);
  }

  //printf("%d ", htable->table[0]->sum);
}
