#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 300
typedef struct heap heap;
struct heap
{
  int size;
  int item[MAX_SIZE];
};

heap* create_heap()
{
  heap *new_heap = (heap*)malloc(sizeof(heap));
  new_heap->size = 0;
  return new_heap;
}

int parent_index_(heap *hp,int i)
{
  return (i/2);
}
int left_index_(heap *hp,int i)
{
  return (2*i);
}
int right_index_(heap *hp,int i)
{
  return (2*i + 1);
}
int what_item(heap *hp,int i)
{
  return hp->item[i];
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void max_heapify(heap *hp,int i)
{
  int big;
  int left_index = left_index_(hp,i);
  int right_index= right_index_(hp,i);

  if(left_index <= hp->size && hp->item[left_index] > hp->item[i])
  {
    big =  left_index;
  }
  else
  {
    big = i;
  }

  if(right_index <= hp->size && hp->item[right_index] > hp->item[big])
  {
    big = right_index;
  }

  if(hp->item[i] != hp->item[big])
  {
    swap(&hp->item[i], &hp->item[big]);
    max_heapify(hp,big);
  }
}

void build_max_heap(heap *hp)
{
  int i;
  int size = hp->size;
  for(i=size/2;i>=1;i--)
  {
    max_heapify(hp,i);
  }
}

void heapsort(heap *hp)
{
  //build_max_heap(hp);

  int i;
  for(i = hp->size; i>=1; i--)
  {
    swap(&hp->item[1], &hp->item[i]);
    hp->size--;
    max_heapify(hp,1);
    print_pre(hp);
  }
}

void print_pre(heap *hp)
{
    int i;
    for(i=1;i<=hp->size;i++)
    {
        printf("| %d |", hp->item[i]);
    }
    printf("\n\n");
}

void main()
{
  int num,i=1,j;
  heap *h = create_heap();
  while(scanf("%d", &num) != EOF)
  {
    h->item[i] = num;
    i++;
  }
  h->size = i-1;
  build_max_heap(h);
  print_pre(h);
  heapsort(h);
  
  
  h->size = i-1;//// print final 
  print_pre(h); /// print final
  

}
