///// ADAPTAR CODIGO PARA MAIS NUMEROS!!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *array1, int *array2)
{
  int aux;
  aux = *array1;
  *array1 = *array2;
  *array2 = aux;
}
void qs(int *ar, int size)
{
  if(size <= 1)
  {
    return ;
  }
  else
  {
    int pivot = v[size/2];
    int a=0;
    int b= size-1;

    while(a<b)
    {
      while(ar[a]< pivot && a<size)
      a++;
      while(ar[b]> pivot && b>=0)
      b--;

      if(a<=b)
      {
        swap(&ar[a], &ar[b]);
        a++;
      }
    }

    qs(ar,b);
    qs(ar + a, size-a);
  }
}


int main()
{
  int a[5];/// limitado a 5 numeros :/
  int i;
  for(i=0;i<5;i++)
  {
    scanf("%d", (a+i));
  }

  qs(a, 5);

  for(i=0;i<5;i++)
  {
    printf("%d ", *(a+i));
  }
  return 0;

}
