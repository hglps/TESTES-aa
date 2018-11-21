#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int odd(int ar2)/// analyze the number, if it's even..
{
  return (ar2%2);
}

int even(int ar) /// analyze the number, if it's even..
{
  return !(ar%2);
}

void filterr(int *array, int size, int (*f)(int))// filter the array
{
  int z;
  for(z=0; z< size;z++)
  {
    if(f(*(array+z))) // if condition is true;
    {
      printf("%d ", *(array+z));// print the number and so on
    }
  }

}

void main()
{
  int *a=malloc(sizeof(int)); // allocate 1 int to start
  int i=0, total;
  char *word = malloc(sizeof(char)*5); // allocate 1 char just to verify later :)

  while (scanf("%d", (a+i)))// scan the array until it ends
  {
    if(*(a+i)==-1) break;// if I press -1, finish it
    a = (int*) realloc(a, sizeof(double)*(i+1));// allocate 1 int by 1
    i++;// adds ""to the"" array
  }

  total = i;// gets the size of the array
  getchar();// gets the "enter" after scanning the string
  gets(word);// scan the string

  if(strcmp(word, "par") == 0) /// if string == "par"..
  {
    filterr(a,total,even); // use even funcion
  }
  else if(strcmp(word, "impar") == 0) // if string == "impar"..
  {
    filterr(a,total,odd);// use odd func.
  }

  free(a);
  free(word);
/////THE CODE IS OVER :)
}
