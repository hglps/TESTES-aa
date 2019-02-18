#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node node;
typedef struct pqueue pqueue;

struct node
{
  int item;
  int priority;
  node *next;
};
struct pqueue
{
  node *head;
};

pqueue* create_pqueue()
{
  pqueue *new_pqueue = (pqueue*) malloc(sizeof(pqueue));
  new_pqueue->head = NULL;
  return new_pqueue;
}

int empty(pqueue* pq)
{
  return (pq->head == NULL);
}

void enqueue(pqueue *pq, int it, int prior)
{
  node *new_node = (node*) malloc(sizeof(node));
  new_node->item = it;
  new_node->priority = prior;

  if(empty(pq) || (prior > pq->head->priority)) /// se a atual for maior q a da head
  {
    new_node->next = pq->head;
    pq->head = new_node;
  }
  else  /// se for menor.. vai indo pelo next ate achar um ser menor q o atual
  {
    node *curr = pq->head;
    while((curr->next != NULL) && (curr->next->priority > prior))
      curr = curr->next;

    new_node->next = curr->next;
    curr->next = new_node;
  }
}

int verify(pqueue *pq, int *a,int index,int quantity,int count)
{
  if(pq->head == NULL) return count;
  if(index <= quantity)
  {
    if(a[index] == pq->head->item)
    {
      count++;
    }
  }
  verify(pq->head->next,a, index+1,quantity,count);
}
void main()
{
  int n,i,quant,j,num;
  int note[1000];
  scanf("%d", &n);
  for(i=0;i<n;i++) /// for geral
  {
    pqueue* queue = create_pqueue();
    int cont=0;
    scanf("%d", &quant);
    for(j=0;j<quant;j++)
    {
      scanf("%d", &num);
      note[j] = num;
      enqueue(queue,num,num);
    }


    for(j=0;j<quant;j++)
    {
      if(note[j] == queue->head->item)
      {
        cont++;
      }
      queue->head = queue->head->next;
    }

    printf("%d\n", cont);
    free(queue);
  }/// fim do for geral
}
