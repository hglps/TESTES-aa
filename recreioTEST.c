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
  return (pqueue->head == NULL);
}

void enqueue(pqueue *pq, int it, int prior)
{
  node *new_node = (node*) malloc(sizeof(node));
  new_node->item = it;
  new_node->priority = p;

  if(empty(pq) || (prior > pq->head->priority)) /// se a atual for maior q a da head
  {
    new_node->next = pq->head;
    pq->head = new_node;
  }
  else  /// se for menor.. vai indo pelo next ate achar um ser menor q o atual
  {
    node *curr = pq->head;
    while(curr->next != NULL) && (curr->next->priority > p))
      curr = curr->next;

    new_node->next = curr->next;
    curr->next = new_node;
  }
}

node* dequeue(pqueue *pq)
{
  if(empty(pq))
  {
    printf("PQUEUE UNDERFLOW\n"); return NULL;
  }
  else
  {
    node *node1 = pq->head;
    pq->head = pq->head->next;
    node1->next = NULL;
    return node1;
  }
}

int maximum(pqueue *pq)
{
  if(empty(pq))
  {
    printf("TA VAZIA JA\n");
    return -1;
  }
  else return pq->head->item;
}

int print_pqueue(pqueue *pq)
{
  while(pqueue->head != NULL)
  {
    printf("%d ", pqueue->head->item);
    pq->head = pq->head->next;
  }
}

void main()
{
  int n,i,quant,j,num;
  int note[1000];
  scanf("%d", &n);
  for(i=0;i<n;i++) /// for geral
  {
    pqueue* queue = create_pqueue();
    scanf("%d", &quant);
    for(j=0;j<quant;j++)
    {
      scanf("%d", &num)
      note[j] = num;
      enqueue(queue,num,num);
    }

    //enqueue(queue,num,num);
    print_pqueue(queue);

    break;



    free(queue);
  }/// fim do for geral
}
