#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sb(int *p, int i, int num, int n)
{
  if(p[i]==num)
  {
    return i;
  }
  else if(p[i]>num)/// esquerda
  {
    sb(*p, (n-i)/2, num, (n+1)/2);
  }
  else/// direita
  {
    sb(*p, (n+i)/2, num, (n+1)/2);
  }
}


int main()
{
  int *array = (int*) malloc(sizeof(int)*10);
  int k,search;
  for(k=0;k<10;k++)
  {
    scanf("%d", *(array+k));
  }

  scanf("%d", &search);

  printf("POSIÇÃO NO ARRAY É = %d\n", sb(array, k/2, search, k) );

  return 0;
}
/// ARRAY DE TESTE = 0 1 2 3 4 5 6 7 8 9; busca do índice= erro nos indices 4,6,8,9 
/// .°. indices colados com o do meio e das pontas
/// END OF CODE :p
