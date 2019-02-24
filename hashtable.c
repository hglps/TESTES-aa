#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101
typedef struct element element;
typedef struct hash hash;
//// HASH TABLE IMPLEMENTED WITH ARRAY
hash* create_hash(); ///
void put(hash *hs, int value); ///
int get(hash *hs, int key); ///
void remove_(hash *hs,int key); ///
int exist_key(hash *hs,int key); ///
void print_hash(hash *hs);
////////////////
struct element
{
  int key;
  int item;
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
  }
  return new_hash;
}

void put(hash *hs,int key, int value)
{
  int h = key % MAX_SIZE;
  while(hs->table[h] != NULL)
  {
    if(hs->table[h]->key == key)
    {
      hs->table[h]->item = value;
      break;
    }
    h = (h+1) % MAX_SIZE;
  }

  if(hs->table[h] == NULL)
  {
    element *new_element = (element*)malloc(sizeof(element));
    new_element->key = key;
    new_element->item = value;
    hs->table[h] = new_element;
  }
}

int get(hash *hs, int key)
{
  int h = key % MAX_SIZE;
  int visited = h,guard;//,count=0;
  while(1)
  {
    if(hs->table[h]->key == key) return hs->table[h]->item;
    if(guard == visited) break;//count+=1;
    h = (h+1) % MAX_SIZE;
    guard = h;
  }
  return -100;
}

void remove_(hash *hs, int key)
{
  int h = key % MAX_SIZE;
  while(hs->table[h] != NULL)
  {
    if(hs->table[h]->key == key)
    {
      ht->table[h]->key = -1;
    }
    h = (h+1) % MAX_SIZE;
  }
}

int exist_key(hash *hs, int key) /// ou colocar if(get(ht,key))
{
  int h = key % MAX_SIZE;
  int visited = h,guard;//,count=0;
  while(1)
  {
    if(hs->table[h]->key == key) return 1;
    if(guard == visited) break;//count+=1;
    h = (h+1) % MAX_SIZE;
    guard = h;
  }
  return -100;
}

void print(hash *hs)
{
  int h=0;
  while(h != MAX_SIZE && hs->table[h]!= NULL) /// testar sem a condition do NULL
  {
    printf("%d ", hs->table[h]->item);
    h = (h+1);
  }
}

void main()
{
  int n,num;
  hash *htable = create_hash();
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    scanf("%d", &num);
    put(htable,num,num);
  }

  free(htable);


}
