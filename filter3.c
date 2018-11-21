#include <stdio.h>
#include <stdlib.h>

int even(int ar)
{
  return !(ar%2);
}

int odd(int ar2)
{
  return (ar2%2);
}

void number((int)(*f)(int*), int *array, int size)
{
  int z;
  for(z=0; z< size;z++)
  {
    if(f( *(array+z)));
    {
      printf("%d ", *(array+z));
    }
  }
}

void main()
{
  int *a=malloc(sizeof(int));
  int i=0, total;
  char *word = malloc(sizeof(char)*5);

  while (scanf("%d", *(a+i)!= EOF)
  {
    realloc(int *a, i);
    i++;
  }
  total = i;
  getchar();
  gets(word);

  if(strcmp(word, "par") == 0) /// if even..
  {
    number(par, a,total); // use even funcion
  }
  else if(strcmp(word, "impar") == 0) // if odd..
  {
    number(impar, a);// use odd func.
  }

}
