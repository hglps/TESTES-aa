#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int odd(int ar2)/// IMPAR
{
  printf("AAAAAAAAAAA");
  return (ar2%2);
}

int even(int ar) /// PAR
{
  printf("BBBBBBBBBB");
  return !(ar%2);
}

void filterr(int *array, int size, int (*f)(int))
{
  int z;
  for(z=0; z< size;z++)
  {
    if(f(array[z]));
    {
      printf("%d ", array[z]);
    }
  }

}

void main()
{
  int *a=malloc(sizeof(int));
  int i=0, total;
  char *word = malloc(sizeof(char)*5);

  while (scanf("%d", (a+i)))
  {
    if(*(a+i)==-1) break;
    a = (int*) realloc(a, sizeof(double)*(i+1));
    i++;
  }
  total = i;
  ///filterr(a,total, even); /// CHAMADA NORMAL
  // //getchar();
  // //gets(word);
  //
  // if(strcmp(word, "par") == 0) /// if even..
  // {
  //   printf("paaaaaaaar\n");
  //   filterr(a,total,even); // use even funcion
  // }
  // else if(strcmp(word, "impar") == 0) // if odd..
  // {
  //   printf("impaaaar\n");
  //   filterr(a,total,odd);// use odd func.
  // }

}
