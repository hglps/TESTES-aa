#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101
typedef struct node node;
typedef struct hash hash;
struct node
{
  char key;
  char item;
  int sum;
  node *next;
};
struct hash
{
  node *table[MAX_SIZE];
};

hash* create_hash()
{
  hash *new_hash = (hash*)malloc(sizeof(hash));
  int i;
  for(i=0;i<MAX_SIZE;i++)
  {
    new_hash->table[i] = NULL;
  }
  return new_hash;
}

void put(hash *hs,int key, int value)
{
  int h= key % MAX_SIZE; /// index of array
  if(hs->table[h] == NULL)
  {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = value;
    new_node->next = NULL;
    new_node->key = key;
    hs->table[h] = new_node;
  }
  else
  {
    while(hs->table[h] != NULL)
    {
      hs->table[h] = hs->table[key]->next;
    }
    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = value;
    new_node->next = NULL;
    new_node->key = key;
    hs->table[h] = new_node;
  }

}

void solve_(hash *hs, char *word,int line)
{
  int i,j,h;
  for(i=0;i<strlen(word);i++)
  {
    put(hs,line,word[i]);
  }
}
void main()
{
  int n,i,num,line; /// CBA   DDD
  char word[51];
  hash *htable = create_hash();
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    //int sum=0;
    scanf("%d", &num);
    //hash *htable = create_hash();
    for(line=0;line<num;line++)
    {
      scanf("%[^\n]s",word);
      getchar();
      solve_(htable,word,line);
      break;
    }

    //free(htable);
    break;
  }/// end of main for
  printf("%c ", htable->table[0]->item); /// dando erro de nao declaracao da hash se colocar dentro do for
                                         /// nao salva direito
}
