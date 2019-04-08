#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct element element;
typedef struct hash hash;
//typedef struct element2 element2;
//typedef struct hash_order hash_order;
#define MAX_SIZE 101
#define TH 1000
///////////
/////////// FINISH LATER
///////////
///////////
///////////
struct adj_list
{
  char item[17];
  int pos;
  adj_list *next;
};

struct graph
{
  adj_list *vertices[MAX_SIZE];
  short visited[MAX_SIZE];
};

struct element
{
  char word[17];
  int pos;
};

struct hash
{
  element *table[1000];
  int size;
};

hash* create_hash()
{
  hash *new_hash = (hash*) malloc(sizeof(hash));
  int i;
  new_hash->size = 0;
  for(i=0;i<TH;i++)
  {
    new_hash->table[i]= NULL;
  }
  return new_hash;
}

graph* create_graph()
{
  graph *n_graph = (graph*) malloc(sizeof(graph));
  int i;
  for (i = 0; i < MAX_SIZE; i++)
  {
    n_graph->vertices[i] = NULL;
    n_graph->visited[i] = 0;
  }
  return n_graph;
}

adj_list* create_adj_list(char *item, int pos)
{
  adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
  strcpy(new_adj_list->item,item);
  new_adj_list->pos = pos;
  new_adj_list->next = NULL;
  return new_adj_list;
}

void add_edge(graph *graph, char *v1, char *v2, int i1, int i2)
{
  adj_list *vex = create_adj_list(v2, i2);
  vex->next = graph->vertices[i1];
  graph->vertices[i1] = vex;
}

void put_in_hash(graph *gp, hash *hs, char *a1, char *a2)
{
  int i=0,save1 = -1, save2 = -1;
  while(hs->table[i] != NULL)
  {
    if(!strcmp(hs->table[i]->word, a1))  { save1= hs->table[i]->pos; break; }
    i+=1;
  }
  if(save1 == -1)
  {
    element *new_element = (element*) malloc(sizeof(element));
    strcpy(new_element->word, a1);
    new_element->pos = hs->size;   save1 = new_element->pos;
    hs->table[hs->size] = new_element;
    hs->size+=1;
  }


  i=0;
  while(hs->table[i] != NULL)
  {
    if(!strcmp(hs->table[i]->word, a2)) { save2 = hs->table[i]->pos; break; }
    i+=1;
  }
  if(save2 == -1)
  {
    element *new_ele2 = (element*) malloc(sizeof(element));
    strcpy(new_ele2->word, a2);
    new_ele2->pos = hs->size;     save2 = new_ele2->pos;
    hs->table[hs->size] = new_ele2;
    hs->size+=1;
  }



  add_edge(gp, a1, a2, save1, save2); ////////////////parei aqui


}

void dfs(graph *graph/*,hash *hs*/,int source)
{
  /*if(graph->visited[source] != -1)*/ graph->visited[source] = 1;
  adj_list *n_adj_list = graph->vertices[source];

  while(n_adj_list != NULL)
  {
    if(n_adj_list->next == NULL)
    {
        if(graph->visited[source] != -1) graph->visited[source] = 0;// tava 1
    }
        //printf("%s\n", graph->vertices[source]->item);
    //printf("source = %d   word = %s\n\n", source, graph->vertices[source]->item);
    if (!graph->visited[n_adj_list->pos] )
    {
      dfs(graph,/* hs,*/ n_adj_list->pos);
    }
    n_adj_list = n_adj_list->next;
  }
  //printf("source = %d   word = %s\n\n", source, graph->vertices[source]->item);

}

void remover(graph *gp, int count)
{
    if(gp->visited[count])
    {
      
    }
    
    
    
}

int del(graph *gp, int count)
{
    item = ;
    adj_list *find = gp->vertices[count];
    adj_list *previous = NULL;
    adj_list *current = find
    while (current != NULL && current->item != item)
    {
      previous = current;
      current = current->next;
    }
    if (previous == NULL) gp->vertices[count] = current->next;
    else previous->next = current->next;

    free(current);
    return 1;
    }
    return 0;
}

void main()
{
  graph *gp = create_graph();
  hash *htable = create_hash();
  int i=0,j=0,n;

  char word1[18];
  char word2[18];
  printf("PUT n:\n");
  scanf("%d", &n);
  //while(scanf("%d", &n) != EOF)
  while(n--)
  {
    scanf("%s %s", word1, word2);
    put_in_hash(gp, htable, word1, word2);
  }

  


  dfs(gp,0); //// falta ajeitar
  for(i=0;i<MAX_SIZE;i++)
  {
    if(gp->visited[i])
    {
        printf("%s\n", htable->table[i]->word);
        gp->visited[i] = -1;
    }
  }
  printf("\n\n");
  dfs(gp,0);
  for(i=0;i<MAX_SIZE;i++)
  {
    if(gp->visited[i])
    {
        printf("%s\n", htable->table[i]->word);
        gp->visited[i] = -1;
    }
  }
  remover(gp,0);
  
  

//   for(i=0;i<MAX_SIZE;i++)
//   {
//       if(htable->table[i] != NULL)
//       {
//           printf("pos = %d   string = %s \n", htable->table[i]->pos, htable->table[i]->word);
//       }
//   }















}
