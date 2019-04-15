#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct node node;
typedef struct stack stack;
#define MAX_SIZE 1001

struct adj_list
{
  int item;
  int w;
  adj_list *next;
};

struct graph
{
  adj_list *vertices[MAX_SIZE];
  short visited[MAX_SIZE];
};

struct node
{
	int item;
	int dist;
	node *next;
};

struct stack
{
	node *top;
};

stack* create_stack()
{
	stack* new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

int is_empty(stack *st)
{
	return (st->top == NULL);
}

void push(stack *st, int item, int dist)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->dist = dist;
	new_node->next = st->top;
	st->top = new_node;
}

void pop(stack *st)
{
    node *update = (node*) malloc (sizeof(node));
    update = st->top->next;
    st->top->next = NULL;
    st->top = update;
}

int peek(stack *st)
{
	return st->top->item;
}

adj_list* create_adj_list(int item, int w)
{
  adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
  new_adj_list->w = w;
  new_adj_list->item = item;
  new_adj_list->next = NULL;
  return new_adj_list;
}

graph* create_graph()
{
  graph *n_graph = (graph*) malloc(sizeof(graph));
  int i;
  for (i = 1; i <= MAX_SIZE - 1; i++)
  {
    n_graph->vertices[i] = NULL;
    n_graph->visited[i] = 0;
  }
  return n_graph;
}

void add_edge(graph *graph, int vertex1, int vertex2, int w)
{
  adj_list *vertex = create_adj_list(vertex2, w);
  vertex->next = graph->vertices[vertex1];
  graph->vertices[vertex1] = vertex;

  vertex = create_adj_list(vertex1,w);
  vertex->next = graph->vertices[vertex2];
  graph->vertices[vertex2] = vertex;
}

int distance(graph *gp, int one, int two)
{
  if(two == 0) return 0;

  while(gp->vertices[one]!= NULL)
  {
    if(gp->vertices[one]->item == two)
      return gp->vertices[one]->w;
  }
  return 0;
}

int dijkstra(graph *gp, int source, int dest)
{
  stack *st = create_stack();
  int u,v, alt, save,aux=1;
  int n = 2;
  adj_list *weightNEI;
  int dist[101] ={[0 ... 100] = 10000};
  dist[1] = 0;
  int way[101] = {[0 ... 100] = 10000};

  push(st,source,dist[source]);

  while(!is_empty(st) )
  {
    u = peek(st);
    pop(st);
    weightNEI = gp->vertices[u];
    v = weightNEI->item;
    printf("u = %d  v = %d\ndist[v] = %d eh maior que alt = %d\n ??? \n", u,v,dist[v], dist[u] + weightNEI->w);
    while()
    if(dist[v] > dist[u] + weightNEI->w)
    {
      alt = dist[u] + weightNEI->w;
      dist[v] = dist[u] + alt;
      push(st,v,dist[v]);
      printf("u = %d alt = %d    dist[v] = %d   peek = %d   \n",u, alt,dist[v], peek(st));
    }
    printf("final= %d\n\n", dist[dest]);
  }


  // u = gp->vertices[source]->item;
  // gp->vertices[source] = gp->vertices[source]->next;
  // while(!gp->visited[source])
  // {
  //     if(gp->visited[dest+1]) break;
  //   printf("\nSOURCE = %d\n", source);
  //   gp->visited[source] = 1;
  //   while(gp->vertices[source] != NULL)
  //   {
  //       printf(" u = %d,  v = %d \n", u,v);
  //     v= gp->vertices[source]->item;
  //     if(aux) { save = v; aux = 0; }
  //     alt = dist[source] + distance(gp,source,v);
  //     printf("ALT = %d\n", alt);
  //       printf(" %d é maior que %d???\n", dist[v], alt);
  //       dist[v] = INT_MAX;
  //     if(dist[v] > alt)
  //     {
  //       dist[v] = alt;
  //       printf("aaaaaaaaaaaaa %d", dist[v]);
  //       way[v] = u;
  //     }
  //     gp->vertices[source] = gp->vertices[source]->next;
  //     printf("dist[%d] = %d\n", v, dist[v]);
  //   }
  //   source = save;
  //   aux = 1;
  // }

  return dist[dest];

}


void main()
{
  graph *gp = create_graph();
  int i,n,m,ed1,ed2,weight,result;
  //puts("enter n and m:");
  scanf("%d%d", &n, &m);
  for(i=0;i<m;i++)
  {
      //puts("enter start and end:");
    scanf("%d%d%d", &ed1, &ed2, &weight);
    add_edge(gp,ed1,ed2,weight);
  }


  result = dijkstra(gp,1,n);
  printf("resposta final = %d\n", result);

  // for(i=1;i<=n;i++)
  // {
  //     printf("%d  ", i);
  //   while(gp->vertices[i] != NULL)
  //   {
  //     printf(" %d ((%d)) ->", gp->vertices[i]->item, gp->vertices[i]->w);
  //     gp->vertices[i] = gp->vertices[i]->next;
  //   }
  //   puts("");
  // }



}
