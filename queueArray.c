#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///QUEUE WITH ARRAY
#define MAX_SIZE 1000
typedef struct queue queue;
struct queue
{
  int size;
  int head;
  int tail;
  int item[MAX_SIZE];
};

queue* create_queue()
{
  queue* new_queue = (queue*)malloc(sizeof(queue));
  new_queue->size = 0;
  new_queue->head = 0;
  new_queue->tail = MAX_SIZE -1;
  return new_queue;
}

void enqueue(queue *queue, int item)
{
  if(queue->size >= MAX_SIZE) printf("QUEUE OVERFLOW\n");
  else
  {
    queue->tail = (queue->tail +1) % MAX_SIZE;
    queue->item[queue->tail] = item;
    queue->size++;
  }
}

void dequeue(queue *queue)
{
  if(empty(queue))
  {
    printf("TA VAZIA JA MEU CARO\n"); return -1;
  }
  else
  {
    int deq = queue->item[queue->head];
    queue->head = (queue->head +1) % MAX_SIZE;
    queue->size--;
    return deq;
  }
}
