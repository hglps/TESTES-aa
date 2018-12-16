#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sb(int *a, int start, int end, int num)
{
    if(end >= 1)
    {
        int n = (start +end) / 2;
        if(a[n] == num) return n;
        if(a[n] > num) return sb(a, start, n-1, num);
        if(a[n] < num) return sb(a,n + 1, end, num);
    }
    return -1;

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
  printf("POSIÇÃO NO ARRAY É = %d\n", sb(array, 0, k, search) );
  return 0;
}
