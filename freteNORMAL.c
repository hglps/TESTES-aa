#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
typedef struct adj_list adj_list;
typedef struct graph graph;
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
  int u,v, alt, save,aux=1;
  int dist[101] ={10000}; // setei todos como """infinito"
  dist[1] = 0;
  int way[101] = {10000};

  u = gp->vertices[source]->item;
  gp->vertices[source] = gp->vertices[source]->next;
  while(!gp->visited[source])
  {
      if(gp->visited[dest]) break;
    printf("\nSOURCE = %d\n", source);
    gp->visited[source] = 1; /// p eu ter uma nocao de onde """parar"
    while(gp->vertices[source] != NULL) // vejo toda lista de cada termo
    {
        printf(" u = %d,  v = %d \n", u,v);
      v= gp->vertices[source]->item; // pego o item seguinte da lista
      if(aux) { save = v; aux = 0; } //aqui eh p os proximos u e v
      alt = dist[source] + distance(gp,source,v); // oq vc tinha falado, mais ou menos
      printf("ALT = %d\n", alt);
        printf(" %d é maior que %d???\n", dist[v], alt);
      if(dist[v] < alt) ///// era p ser dist > alt, mas ai fica dist = 0 sempre n sei pq
      {
        dist[v] = alt;
        printf("aaaaaaaaaaaaa %d", dist[v]);
        way[v] = u;
      }
      gp->vertices[source] = gp->vertices[source]->next; // vou percorrer todos os vizinhos
      printf("dist[%d] = %d\n", v, dist[v]);
    }
    source = save; // vou p o proximo vizinho dps de verificar todos os vizinhos da source principal
    aux = 1;
  }

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
  printf("\nRESPOSTA FINAL = %d\n", result);

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
