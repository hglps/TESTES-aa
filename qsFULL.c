#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(int *a1, int *a2)
{
  int aux = *(a1);
  *(a1) = *(a2);
  *(a2) = aux;
}
void qs(int *arr, int a, int b)
{
   int i=a, j=b, pivot = arr[(a+b)/2];
 
    while(i <= j)
   {
      while(arr[i] < pivot) i++;
      while(arr[j] > pivot) j--;
      if(i <= j)
      {
         swap(&arr[i],&arr[j]); 
         i++; j--;
      }
   }
 
   if(a < j)
      qs(arr, a, j);
   if(i < b)
      qs(arr, i, b);
}
int main() 
{
  int *a =(int*) malloc(sizeof(double));
  int i=0,total;
  while(1)
  {
      if(scanf("%d", (a+i))==EOF) break;
      i++;
      a= (int*) realloc(a, sizeof(double)*(i+1));
  }
  total=i;
  qs(a, 0, total-1);

  for(i=0;i<total;i++)
  {
    printf("%d ", *(a+i));
  }
  return 0;
	return 0;
}
